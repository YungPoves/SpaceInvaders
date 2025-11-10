#include <cstddef>
#include <cstdint>
#include <cstdio>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

GLFWwindow* window;

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

void error_callback(int error, const char* description)
{
	fprintf(stderr, "Error: %s\n", description);
}

void window_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

int init()
{
	// init GLFW
	if(!glfwInit())
	{
		return -1;
	}

	// create window and set context
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Space Invaders", nullptr, nullptr);

	if(!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	glfwSetWindowSizeCallback(window, window_size_callback);

	// init GLEW
	GLenum err = glewInit();
	if(err != GLEW_OK)
	{
		fprintf(stderr, "Error initialising GLEW.\n");
		glfwTerminate();
		return -1;
	}

	/* set the viewport */
	glClearColor(0.6784f, 0.8f, 1.0f, 1.0f);
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

	glEnable(GL_DEPTH_TEST);

	return true;
}

void update()
{
	// Game loop
	while(!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}
}

int main()
{
	glfwSetErrorCallback(error_callback);

	if(!init())
	{
		return -1;
	}

	update();

	glfwDestroyWindow(window);

	glfwTerminate();

	return 0;
}
