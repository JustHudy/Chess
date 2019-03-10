#ifndef KNIGHTCONTROLLER_H
#define KNIGHTCONTROLLER_H

#include "FigureController.h"
#include "Knight.h"
#include "KnightView.h"

class KnightController :public FigureController
{
public:
	KnightController(Knight * figure, KnightView * figureView) :
		FigureController(figure, figureView)
	{
	}
	~KnightController();
	virtual std::vector<Point> getAvailableMove(FigureController *** figure);
	virtual std::vector<Point> beating(FigureController *** figure) { return getAvailableMove(figure); }

private:

};

KnightController::~KnightController()
{
}

std::vector<Point> KnightController::getAvailableMove(FigureController *** figure)
{ 
	std::vector<Point> move;

	if (((getPosition().x + 1) < 8) && ((getPosition().y + 2 < 8)))
		if (!figure[(int)getPosition().x + 1][(int)getPosition().y + 2])
			move.push_back(Point(getPosition().x + 1, getPosition().y + 2));
		else if (figure[(int)getPosition().x + 1][(int)getPosition().y + 2]->getColor() != getColor())
			move.push_back(Point(getPosition().x + 1, getPosition().y + 2));

	if (((getPosition().x + 2) < 8) && ((getPosition().y + 1 < 8)))
		if (!figure[(int)getPosition().x + 2][(int)getPosition().y + 1])
			move.push_back(Point(getPosition().x + 2, getPosition().y + 1));
		else if (figure[(int)getPosition().x + 2][(int)getPosition().y + 1]->getColor() != getColor())
			move.push_back(Point(getPosition().x + 2, getPosition().y + 1));

	if (((getPosition().x + 2) < 8) && ((getPosition().y - 1 >= 0)))
		if (!figure[(int)getPosition().x + 2][(int)getPosition().y - 1])
			move.push_back(Point(getPosition().x + 2, getPosition().y - 1));
		else if (figure[(int)getPosition().x + 2][(int)getPosition().y - 1]->getColor() != getColor())
			move.push_back(Point(getPosition().x + 2, getPosition().y - 1));

	if (((getPosition().x + 1) < 8) && ((getPosition().y - 2 >= 0)))
		if (!figure[(int)getPosition().x + 1][(int)getPosition().y - 2])
			move.push_back(Point(getPosition().x + 1, getPosition().y - 2));
		else if (figure[(int)getPosition().x + 1][(int)getPosition().y - 2]->getColor() != getColor())
			move.push_back(Point(getPosition().x + 1, getPosition().y - 2));

	if (((getPosition().x - 1) >= 0) && ((getPosition().y - 2 >= 0)))
		if (!figure[(int)getPosition().x - 1][(int)getPosition().y - 2])
			move.push_back(Point(getPosition().x - 1, getPosition().y - 2));
		else if (figure[(int)getPosition().x - 1][(int)getPosition().y - 2]->getColor() != getColor())
			move.push_back(Point(getPosition().x - 1, getPosition().y - 2));

	if (((getPosition().x - 2) >= 0) && ((getPosition().y - 1 >= 0)))
		if (!figure[(int)getPosition().x - 2][(int)getPosition().y - 1])
			move.push_back(Point(getPosition().x - 2, getPosition().y - 1));
		else if (figure[(int)getPosition().x - 2][(int)getPosition().y - 1]->getColor() != getColor())
			move.push_back(Point(getPosition().x - 2, getPosition().y - 1));

	if (((getPosition().x - 2) >= 0) && ((getPosition().y + 1 < 8)))
		if (!figure[(int)getPosition().x - 2][(int)getPosition().y + 1])
			move.push_back(Point(getPosition().x - 2, getPosition().y + 1));
		else if (figure[(int)getPosition().x - 2][(int)getPosition().y + 1]->getColor() != getColor())
			move.push_back(Point(getPosition().x - 2, getPosition().y + 1));

	if (((getPosition().x - 1) >= 0) && ((getPosition().y + 2 < 8)))
		if (!figure[(int)getPosition().x - 1][(int)getPosition().y + 2])
			move.push_back(Point(getPosition().x - 1, getPosition().y + 2));
		else if (figure[(int)getPosition().x - 1][(int)getPosition().y + 2]->getColor() != getColor())
			move.push_back(Point(getPosition().x - 1, getPosition().y + 2));
	return move;
}


#endif // !PAWNCONTROLLER
