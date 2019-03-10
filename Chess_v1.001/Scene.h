#ifndef SCENE_H_
#define SCENE_H_

#include <GL/glew.h>
//#include <GL/glut.h>
#include <glfw3.h>

#include "Loader.h"
#include "controls.h"
#include "Board.h"

class Scene {
private:
	static Scene * instance;
	GLuint shader;
	GLuint ViewMatrixID;
	vector<GraphicsObject *> buffer;
	Scene();

public:
	static Scene * getInstance();
	void render();
	vector<GraphicsObject *> & getBuffer();
	void deleteElement(int id);
	void addElement(GraphicsObject * e);
};

Scene * Scene::instance = nullptr;

void Scene::addElement(GraphicsObject * e)
{
	buffer.push_back(e);
}


void Scene::deleteElement(int id)
{
	for (int i = 0; i < buffer.size(); i++)
	{
		if (buffer[i]->getId() == id)
		{
			buffer.erase(buffer.begin() + i);
		}
	}
}

vector<GraphicsObject *> & Scene::getBuffer()
{
	return this->buffer;
}


Scene * Scene::getInstance()
{
	if (!instance)
	{
		instance = new Scene();
	}
	return instance;
}

Scene::Scene()
{
	shader = Loader::loadShader("StandardShading.vertexshader", "StandardShading.fragmentshader");
	ViewMatrixID = glGetUniformLocation(shader, "V");
}

void Scene::render()
{

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
	glUseProgram(shader);

	GLuint LightID = glGetUniformLocation(shader, "LightPosition_worldspace");
	Factory * f = Factory::getInstance();
	Board *board = Board::getInstance();
	GraphicsObject *** fields = board->getFileds();
	FigureController *** figure = board->getFigures();

	for(int i = 0; i<8; i++)
		for (int j = 0; j < 8; j++)
		{
			buffer.push_back(fields[i][j]);
			if (figure[i][j]) buffer.push_back(figure[i][j]->getView());
		}
	do
	{

		int width, height;
		glfwGetWindowSize(window, &width, &height);
		if (1.3333 *width > height)
			glViewport((width - 1.3333 * height) / 2, 0, 1.3333 * height, height);
		else if (1.3333 *width < height)
			glViewport(0, (1.3333 * height - width) / 2, 1.3333 * width, width);

		Controls::computeMatricesFromInputs();
		glm::mat4 ProjectionMatrix = Controls::getProjectionMatrix();
		glm::mat4 ViewMatrix = Controls::getViewMatrix();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(shader);
		glm::vec3 lightPos = glm::vec3(0, 10, 0);
		glUniform3f(LightID, lightPos.x, lightPos.y, lightPos.z);
		glUniformMatrix4fv(ViewMatrixID, 1, GL_FALSE, &ViewMatrix[0][0]);

		for (int i = 0; i < buffer.size(); i++)
		{
			buffer[i]->render();
		}

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		glDisableVertexAttribArray(2);

		glfwSwapBuffers(window);
		glfwPollEvents();
	} while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&	glfwWindowShouldClose(window) == 0);

	glDeleteProgram(shader);
	glDeleteVertexArrays(1, &VertexArrayID);

	glfwTerminate();
}

#endif //!RENDER_H
