# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/19 17:30:35 by plouvel           #+#    #+#              #
#    Updated: 2022/08/19 22:33:37 by plouvel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories

OBJS_DIR	=	objs

SRCS_DIR	=	srcs

GLFW_DIR	=	glfw

GLAD_DIR	=	glad

LIBS_DIR	=	libs

TMP_DIR		=	tmp

SRCS		=	learngl.c	\
				main.c	\

OBJS		=	$(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

INCS		=	includes

CFLAGS		=	-Wall -Werror -Wextra

CLIBS		=	-L $(LIBS_DIR) -lglfw3 \
				-L /usr/local/lib -lrt -lm -ldl \

CINCS		=	-I includes \
				-I includes/glad \
				-I $(GLAD_DIR)/include \
				-I $(GLFW_DIR)/include \

CC			=	cc

RM			=	rm -rf

NAME		=	learnOpenGL

GLFW		=	libglfw3.a

$(NAME):	$(LIBS_DIR)/$(GLFW) \
			$(OBJS)
	$(CC) $(CFLAGS) $(CINCS) -c $(GLAD_DIR)/src/glad.c -o objs/glad.o
	$(CC) $(OBJS) objs/glad.o -o $(NAME) $(CLIBS) 

$(LIBS_DIR)/$(GLFW): | $(LIBS_DIR)
	@cmake -S $(GLFW_DIR) -B $(TMP_DIR)/glfw_build
	make -C $(TMP_DIR)/glfw_build
	@cp ./$(TMP_DIR)/glfw_build/src/$(GLFW) $(LIBS_DIR)
	$(RM) $(TMP_DIR)

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(CINCS) -c $< -o $@


$(OBJS_DIR):
	@mkdir -p $@

$(LIBS_DIR):
	@mkdir -p $@

all:		$(NAME)

clean:
	$(RM) $(OBJS_DIR)

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(LIBS_DIR)

re:	fclean all

.PHONY:		all clean fclean
