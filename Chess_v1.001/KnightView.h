#ifndef KNIGHTVIEW_H
#define KNIGHTVIEW_H

#include "FigureView.h"

class KnightView : public FigureView
{
public:
	KnightView(glm::vec3 color, glm::vec3 position, glm::vec3 rotation, GLuint shader, GLuint vertexbuffer, GLuint normalbuffer, GLuint elementbuffer, GLuint indices);

};

#endif // !PAWNVIEW_H

KnightView::KnightView(glm::vec3 color, glm::vec3 position, glm::vec3 rotation, GLuint shader, GLuint vertexbuffer, GLuint normalbuffer, GLuint elementbuffer, GLuint indices) :
	FigureView(color, position, rotation, shader, vertexbuffer, normalbuffer, elementbuffer, indices)
{

}
