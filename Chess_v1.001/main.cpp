#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;
#include <Windows.h>
// Include GLEW
#include <GL/glew.h>
//#include <GL/glut.h>
// Include GLFW
#include <glfw3.h>
GLFWwindow* window;

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
using namespace glm;
#include "Game.h"

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		Scene * scene = Scene::getInstance();
		Game * game = Game::getInstance();
		vector<GraphicsObject *> & buffer = scene->getBuffer();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUseProgram(buffer[0]->getPickingShader());

		glUniformMatrix4fv(buffer[0]->getViewMatrixId(), 1, GL_FALSE, &ViewMatrix[0][0]); // This one doesn't change between objects, so this can be done once for all objects that use "programID"


		for (int i = 0; i < buffer.size(); i++)
		{
			buffer[i]->renderForSelection();
		}
		


		glDisableVertexAttribArray(0);
		glFlush();
		glFinish();
		int width, height;
		glfwGetWindowSize(window, &width, &height);

		unsigned char data[4];
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		glReadPixels(xpos, height - ypos, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, data);

		int pickedID =
			data[0] +
			data[1] * 256 +
			data[2] * 256 * 256;

		for (int i = 0; i < buffer.size(); i++)
		{
			if (buffer[i]->getId() == pickedID)
			{
				game->select(Point(buffer[i]->getPosition()));
				//buffer[i]->select();
			}
		}
	}
}


void init()
{
	Color[COLOR::BLACK] = vec3(0.0f, 0.0f, 0.0f);
	Color[COLOR::WHITE] = vec3(1.0f, 1.0f, 1.0f);
	Color[COLOR::GRAY] = vec3(0.5f, 0.5f, 0.5f);
	Color[COLOR::BLUE] = vec3(0.0f, 0.0f, 0.5f);


	if (!glfwInit())
	{
		return;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(1024, 768, "Chess", NULL, NULL);
	if (window == NULL) {
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(window);

	glewExperimental = true;
	if (glewInit() != GLEW_OK) {
		glfwTerminate();
		return;
	}

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_CULL_FACE);


	glfwSetMouseButtonCallback(window, mouse_button_callback);
}



int main(int argc, char * argv[])
{
	init();
	
	Scene * scene = Scene::getInstance();
	scene->render();


	return 0;
}
