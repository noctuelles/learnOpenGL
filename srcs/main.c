#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_learnGL
{
	GLFWwindow	*window;
	int			width;
	int			height;
	const char	*title;
}				t_learnGL;

static void	error_callback(int errcode, const char *msg)
{
	fprintf(stderr, "An internal GLWF occured (%#X) : \n\t%s.\n", errcode, msg);
}

int	initException(t_learnGL *learnGL)
{
	if (learnGL->window)
		glfwDestroyWindow(learnGL->window);
	glfwTerminate();
	return (1);
}

int	initLearnGL(t_learnGL *learnGL)
{
	learnGL->width = 800;
	learnGL->height = 600;
	learnGL->window = NULL;
	learnGL->title = "learnGL";
	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
		return (EXIT_FAILURE);
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
	return (-1);
}

int	main(void)
{
	t_learnGL	learnGL;

	if (initLearnGL(&learnGL) == -1)
		return (1);
	while (!glfwWindowShouldClose(learnGL.window))
	{
		glfwSwapBuffers(learnGL.window);
		glfwPollEvents();
	}
	glfwDestroyWindow(learnGL.window);
	glfwTerminate();
	return (0);
}
