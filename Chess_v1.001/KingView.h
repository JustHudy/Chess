#ifndef KINGVIEW_H
#define KINGVIEW_H

#include "FigureView.h"

class KingView : public FigureView
{
public:
	KingView(glm::vec3 color, glm::vec3 position, glm::vec3 rotation, GLuint shader, GLuint vertexbuffer, GLuint normalbuffer, GLuint elementbuffer, GLuint indices);

};

#endif // !PAWNVIEW_H

KingView::KingView(glm::vec3 color, glm::vec3 position, glm::vec3 rotation, GLuint shader, GLuint vertexbuffer, GLuint normalbuffer, GLuint elementbuffer, GLuint indices) :
	FigureView(color, position, rotation, shader, vertexbuffer, normalbuffer, elementbuffer, indices)
{

}
