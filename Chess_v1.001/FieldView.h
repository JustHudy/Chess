#ifndef FIELDVIEW_H
#define FIELDVIEW_H

#include "GraphicsObiect.h"

class FieldView: public GraphicsObject
{
public:
	FieldView(glm::vec3 color, glm::vec3 position, glm::vec3 rotation, GLuint shader, GLuint vertexbuffer, GLuint normalbuffer, GLuint elementbuffer, GLuint indices);
	~FieldView();

private:

};

FieldView::FieldView(glm::vec3 color, glm::vec3 position, glm::vec3 rotation, GLuint shader, GLuint vertexbuffer, GLuint normalbuffer, GLuint elementbuffer, GLuint indices) :
	GraphicsObject(color, position, rotation, shader, vertexbuffer, normalbuffer, elementbuffer, indices)
{

}

FieldView::~FieldView()
{
}


#endif // !FIELDVIEW_H
