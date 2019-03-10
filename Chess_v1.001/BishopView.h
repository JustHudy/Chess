#ifndef BISHOPVIEW_H
#define BISHOPVIEW_H

#include "FigureView.h"

class BishopView : public FigureView
{
public:
	BishopView(glm::vec3 color, glm::vec3 position, glm::vec3 rotation, GLuint shader, GLuint vertexbuffer, GLuint normalbuffer, GLuint elementbuffer, GLuint indices);

};


BishopView::BishopView(glm::vec3 color, glm::vec3 position, glm::vec3 rotation, GLuint shader, GLuint vertexbuffer, GLuint normalbuffer, GLuint elementbuffer, GLuint indices) :
	FigureView(color, position, rotation, shader, vertexbuffer, normalbuffer, elementbuffer, indices)
{

}

#endif 
