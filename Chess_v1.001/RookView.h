#ifndef ROOKVIEW_H
#define ROOKVIEW_H

#include "FigureView.h"

class RookView : public FigureView
{
public:
	RookView(glm::vec3 color, glm::vec3 position, glm::vec3 rotation, GLuint shader, GLuint vertexbuffer, GLuint normalbuffer, GLuint elementbuffer, GLuint indices);

};

#endif // !PAWNVIEW_H

RookView::RookView(glm::vec3 color, glm::vec3 position, glm::vec3 rotation, GLuint shader, GLuint vertexbuffer, GLuint normalbuffer, GLuint elementbuffer, GLuint indices) :
	FigureView(color, position, rotation, shader, vertexbuffer, normalbuffer, elementbuffer, indices)
{

}
