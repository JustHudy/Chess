#ifndef FIGUREVIEW_H
#define FIGUREVIEW_H

#include "GraphicsObiect.h"

class FigureView: public GraphicsObject
{
private:
	vec3 currentColor;

public:
	FigureView(glm::vec3 color, glm::vec3 position, glm::vec3 rotation, GLuint shader, GLuint vertexbuffer, GLuint normalbuffer, GLuint elementbuffer, GLuint indices);
	~FigureView();
	vec3 getCurrentColor() const;
	void setCurrentColor(vec3 color);
};

FigureView::FigureView(glm::vec3 color, glm::vec3 position, glm::vec3 rotation, GLuint shader, GLuint vertexbuffer, GLuint normalbuffer, GLuint elementbuffer, GLuint indices) :
	GraphicsObject(color, position, rotation, shader, vertexbuffer, normalbuffer, elementbuffer, indices)
{

}

FigureView::~FigureView()
{

}

vec3 FigureView::getCurrentColor() const
{
	return this->currentColor;
}
void FigureView::setCurrentColor(vec3 color)
{
	this->currentColor = color;
}

#endif // !FIGUREVIEW_H
