#ifndef CONTROLS_H
#define CONTROLS_H
#include <glfw3.h>
extern GLFWwindow* window;
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

class Controls
{
private:
	static glm::vec3 position;
	static glm::vec3 to;

	static float horizontalAngle;
	static float verticalAngle;
	static float initialFoV;
	static float speed;
	static float mouseSpeed;
public:
	static void computeMatricesFromInputs();
	static glm::mat4 getViewMatrix();
	static glm::mat4 getProjectionMatrix();
	static void cameraFromBlack();
	static void cameraFromWhite();
};


glm::vec3 Controls::position = glm::vec3(-0.5, 8, -6);
glm::vec3 Controls::to = glm::vec3(-0.5, -0.5, 0);

float Controls::horizontalAngle = 0;
float Controls::verticalAngle = 5.35969f;
float Controls::initialFoV = 45.0f;
float Controls::speed = 3.0f;
float Controls::mouseSpeed = 0.005f;

using namespace glm;
using namespace std;

void Controls::cameraFromBlack()
{
	position = glm::vec3(-0.5, 8, 4.5);
	to = glm::vec3(-0.5, 0, -0.5);
}

void Controls::cameraFromWhite()
{
	position = glm::vec3(-0.5, 8, -5.5);
	to = glm::vec3(-0.5, 0, -0.5);
}


glm::mat4 ViewMatrix;
glm::mat4 ProjectionMatrix;

glm::mat4 Controls::getViewMatrix() {
	return ViewMatrix;
}
glm::mat4 Controls::getProjectionMatrix() {
	return ProjectionMatrix;
}
bool pressed = false;

void Controls::computeMatricesFromInputs() {


	//cout << horizontalAngle << " " << verticalAngle << std::endl;
	static double lastTime = glfwGetTime();

	double currentTime = glfwGetTime();
	float deltaTime = float(currentTime - lastTime);
	int width, height;
	glfwGetWindowSize(window, &width, &height);
	double xpos = width / 2, ypos = height / 2;
	horizontalAngle += mouseSpeed * float(width / 2 - xpos);
	verticalAngle += mouseSpeed * float(height / 2 - ypos);

	glm::vec3 direction(
		cos(verticalAngle) * sin(horizontalAngle),
		sin(verticalAngle),
		cos(verticalAngle) * cos(horizontalAngle)
	);

	glm::vec3 right = glm::vec3(
		sin(horizontalAngle - 3.14f / 2.0f),
		0,
		cos(horizontalAngle - 3.14f / 2.0f)
	);

	glm::vec3 up = glm::cross(right, direction);

	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
		if (pressed)
		{
			position.z -= 0.5;
			pressed = false;
		}
	
		//position += direction * deltaTime * speed;
	}
	else
		pressed = true;
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
		verticalAngle -= 0.0001;
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
		horizontalAngle -= 0.0002;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
		horizontalAngle += 0.0002;
	}
	if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {
		cout << "x=" << position.x << " y=" << position.y << " z=" << position.z << endl;
		cout << "v" << verticalAngle << endl;
		cout << "h" << horizontalAngle << endl;
	}

	float FoV = initialFoV;
	ProjectionMatrix = glm::perspective(FoV, 4.0f / 3.0f, 0.1f, 100.0f);
//	ViewMatrix = glm::lookAt(
//		position,
//		position + direction,
//		up
//	);
	//ViewMatrix = glm::lookAt(glm::vec3(-0.5, 8, -6), glm::vec3(-0.5, -0.5, 0), glm::vec3(0, 1.0f, 0));
	ViewMatrix = glm::lookAt(position, to, glm::vec3(0, 1.0f, 0));

	lastTime = currentTime;
}

#endif
