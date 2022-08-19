#include "learngl.h"
#include <stdio.h>
#include <stdlib.h>

void	processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int	main(void)
{
	t_learnGL	learnGL;

	if (initLearnGL(&learnGL) == -1)
		return (EXIT_FAILURE);
	while (!glfwWindowShouldClose(learnGL.window))
	{
		processInput(learnGL.window);
		glClearColor(1, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(learnGL.window);
		glfwPollEvents();
	}
	glfwDestroyWindow(learnGL.window);
	glfwTerminate();
	return (EXIT_SUCCESS);
}
