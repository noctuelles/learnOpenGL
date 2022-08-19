# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/19 17:30:35 by plouvel           #+#    #+#              #
#    Updated: 2022/08/19 18:32:32 by plouvel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories

OBJS_DIR	=	objs

SRCS_DIR	=	srcs

GLFW_DIR	=	glfw

SRCS		=	glad.c	\
				main.c	\

OBJS		=	$(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

INCS		=	includes

CFLAGS		=	-Wall -Werror -Wextra

CINCS		=	$(shell pkg-config --cflags glfw3) \
				-I includes \
				-I includes/glad \

CC			=	cc

RM			=	rm -rf

NAME		=	learnOpenGL

$(NAME):	$(OBJS)
	$(CC) $(OBJS) $(CLIBS) -o $(NAME) $(shell pkg-config --static --libs glfw3)


$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(CINCS) -c $< -o $@


$(OBJS_DIR):
	@mkdir -p $@

all:		$(NAME)

clean:
	$(RM) $(OBJS_DIR)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:		all clean fclean
