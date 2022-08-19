/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learngl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:27:01 by plouvel           #+#    #+#             */
/*   Updated: 2022/08/19 19:33:46 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "learngl.h"
#include <stdio.h>

static int	initException(t_learnGL *learnGL)
{
	if (learnGL->window)
		glfwDestroyWindow(learnGL->window);
	glfwTerminate();
	return (-1);
}
static void	error_callback(int errcode, const char *msg)
{
	fprintf(stderr, "An internal GLWF occured (%#X) : \n\t%s.\n", errcode, msg);
}

int	initLearnGL(t_learnGL *learnGL)
{
	learnGL->width = 800;
	learnGL->height = 600;
	learnGL->window = NULL;
	learnGL->title = "learnGL";
	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
		return (-1);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	learnGL->window = glfwCreateWindow(learnGL->width, learnGL->height, 
			learnGL->title, NULL, NULL);
	if (!learnGL->window)
		return (initException(learnGL));
	glfwMakeContextCurrent(learnGL->window);
	if (!gladLoadGLLoader((GLADloadproc) &glfwGetProcAddress))
		return (initException(learnGL));
	glViewport(0, 0, learnGL->width, learnGL->height);
	return (0);
}
