#ifndef SELECTION_H
#define SELECTION_H

#include "Point.h"

class Selection
{
protected:
	bool selected;
	static GLuint shader;
	static int id;
	glm::vec3 color;
	int r;
	int g;
	int b;
	GLuint pickingColorID;
	GLuint PickingMatrixID;

public:
	Selection();
	virtual void renderForSelection() = 0;
	virtual void select() = 0;
	virtual void unselect() = 0;
	bool isSelected() { return selected; }
	GLuint getPickingShader();
	GLuint getId();
};

GLuint Selection::getId()
{
	return r + g * 256 + b * 256 * 256;
}

int Selection::id = 0;

GLuint Selection::getPickingShader()
{
	return shader;
}


Selection::Selection()
{
	color = vec3(0, 0, 0.6);
	r = (id & 0x000000FF) >> 0;
	g = (id & 0x0000FF00) >> 8;
	b = (id & 0x00FF0000) >> 16;
	id++;

	if (shader == 0)
	{
		shader = Loader::loadShader("Picking.vertexshader", "Picking.fragmentshader");
	}
	pickingColorID = glGetUniformLocation(shader, "PickingColor");
	PickingMatrixID = glGetUniformLocation(shader, "MVP");

}

GLuint Selection::shader = 0;

#endif // !SELECTION_H
