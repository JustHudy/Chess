#ifndef QUEEMVIEW_H
#define QUEEMVIEW_H

#include "FigureView.h"

class QueenView : public FigureView
{
public:
	QueenView(glm::vec3 color, glm::vec3 position, glm::vec3 rotation, GLuint shader, GLuint vertexbuffer, GLuint normalbuffer, GLuint elementbuffer, GLuint indices);

};

#endif // !PAWNVIEW_H

QueenView::QueenView(glm::vec3 color, glm::vec3 position, glm::vec3 rotation, GLuint shader, GLuint vertexbuffer, GLuint normalbuffer, GLuint elementbuffer, GLuint indices) :
	FigureView(color, position, rotation, shader, vertexbuffer, normalbuffer, elementbuffer, indices)
{

}
