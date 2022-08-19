/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learngl.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:27:27 by plouvel           #+#    #+#             */
/*   Updated: 2022/08/19 19:29:59 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEARNGL_H
# define LEARNGL_H

# include "glad/glad.h"
# include <GLFW/glfw3.h>

typedef struct	s_learnGL
{
	GLFWwindow	*window;
	int			width;
	int			height;
	const char	*title;
}				t_learnGL;

int	initLearnGL(t_learnGL *learnGL);

#endif
