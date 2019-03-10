#ifndef GRAPHICS_OBIECT_H
#define GRAPHICS_OBIECT_H

#include "Selection.h"

class GraphicsObject : public Selection
{
private:
	GLuint shader;
	GLuint vertexbuffer;
	GLuint normalbuffer;
	GLuint elementbuffer;
	GLuint MatrixID;
	GLuint ViewMatrixID;
	GLuint ModelMatrixID;
	GLuint ColorID;
	glm::vec3 baseColor;
	glm::vec3 color;
	glm::vec3 position;
	glm::vec3 rotation;

public:
	GraphicsObject(glm::vec3 color, glm::vec3 position, glm::vec3 rotation, GLuint shader, GLuint vertexbuffer, GLuint normalbuffer, GLuint elementbuffer, GLuint indices);
	void render();
	vec3 getColor() const;
	vec3 getPosition()const;
	vec3 getRotation()const;
	GLuint indices;
	void setColor(vec3 color);
	void setPosition(vec3 position);
	void setRotation(vec3 rotation);
	GLuint getViewMatrixId() { return ViewMatrixID; }
	virtual void renderForSelection();
	virtual void select();
	virtual void unselect();
};

void GraphicsObject::select()
{
	this->color = vec3(0.0f, 0.0f, 0.6f);
	this->selected = true;
}

void  GraphicsObject::unselect()
{
	this->color = this->baseColor;
	this->selected = false;
}

void GraphicsObject::renderForSelection()
{
	glUseProgram(Selection::shader);
	glm::mat4 RotationMatrix = glm::toMat4(glm::quat(rotation));
	glm::mat4 TranslationMatrix = translate(mat4(), position);
	glm::mat4 ModelMatrix2 = TranslationMatrix * RotationMatrix;

	glm::mat4 MVP2 = ProjectionMatrix * ViewMatrix * ModelMatrix2;

	glUniformMatrix4fv(PickingMatrixID, 1, GL_FALSE, &MVP2[0][0]);

	glUniform4f(pickingColorID, r / 255.0f, g / 255.0f, b / 255.0f, 1.0f);
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP2[0][0]);
	glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, &ModelMatrix2[0][0]);
	glUniform3f(ColorID, color.x, color.y, color.z);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer);
	glDrawElements(GL_TRIANGLES, indices, GL_UNSIGNED_SHORT, (void*)0);

}


GraphicsObject::GraphicsObject(glm::vec3 color, glm::vec3 position, glm::vec3 rotation, GLuint shader, GLuint vertexbuffer, GLuint normalbuffer, GLuint elementbuffer, GLuint indices) : Selection()
{
	this->shader = shader;
	this->vertexbuffer = vertexbuffer;
	this->normalbuffer = normalbuffer;
	this->elementbuffer = elementbuffer;
	this->indices = indices;
	this->color = color;
	this->position = position;
	this->rotation = rotation;
	this->baseColor = color;
	MatrixID = glGetUniformLocation(shader, "MVP");
	ViewMatrixID = glGetUniformLocation(shader, "V");
	ModelMatrixID = glGetUniformLocation(shader, "M");
	ColorID = glGetUniformLocation(shader, "Color");
}

void GraphicsObject::render()
{
	Controls::computeMatricesFromInputs();
	glm::mat4 ProjectionMatrix = Controls::getProjectionMatrix();
	glm::mat4 ViewMatrix = Controls::getViewMatrix();

	glm::mat4 RotationMatrix = glm::toMat4(glm::quat(rotation));
	glm::mat4 TranslationMatrix = translate(mat4(), position);
	glm::mat4 ModelMatrix2 = TranslationMatrix * RotationMatrix;
	glm::mat4 MVP2 = ProjectionMatrix * ViewMatrix * ModelMatrix2;

	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP2[0][0]);
	glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, &ModelMatrix2[0][0]);
	glUniform3f(ColorID, color.x, color.y, color.z);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer);

	glDrawElements(GL_TRIANGLES, this->indices, GL_UNSIGNED_SHORT, (void*)0);
}

vec3 GraphicsObject::getColor() const
{
	return this->color;
}
vec3 GraphicsObject::getPosition()const
{
	return this->position;
}
vec3 GraphicsObject::getRotation()const
{
	return this->rotation;
}
void GraphicsObject::setColor(vec3 color)
{
	this->color = color;
}
void GraphicsObject::setPosition(vec3 position)
{
	this->position = position;
}
void GraphicsObject::setRotation(vec3 rotation)
{
	this->rotation = rotation;
}
#endif // !GRAPHICS_OBIECT_H
