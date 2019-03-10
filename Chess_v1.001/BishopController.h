#ifndef BISHOPCONTROLLER_H
#define BISHOPCONTROLLER_H

#include "FigureController.h"
#include "Bishop.h"
#include "BishopView.h"

class BishopController :public FigureController
{
public:
	BishopController(Bishop * figure, BishopView * figureView) :
		FigureController(figure, figureView)
	{
	}
	~BishopController();
	virtual std::vector<Point> getAvailableMove(FigureController *** figure);
	virtual std::vector<Point> beating(FigureController *** figure);

private:

};

BishopController::~BishopController()
{
}

std::vector<Point> BishopController::getAvailableMove(FigureController *** figure) 
{ 
	std::vector<Point> move;

	for (int i = 1; (getPosition().x + i < 8) && (getPosition().y + i < 8); i++)
	{
		if (!figure[(int)getPosition().x + i][(int)getPosition().y + i])
		{
			move.push_back(Point((int)getPosition().x + i, (int)getPosition().y + i));
		}
		else
		{
			if (figure[(int)getPosition().x + i][(int)getPosition().y + i]->getColor() != getColor())
			{
				move.push_back(Point((int)getPosition().x + i, (int)getPosition().y + i));
				break;
			}
			else
				break;
		}
	}

	for (int i = 1; (getPosition().x - i >= 0) && (getPosition().y + i < 8); i++)
	{
		if (!figure[(int)getPosition().x - i][(int)getPosition().y + i])
			move.push_back(Point((int)getPosition().x - i, (int)getPosition().y + i));
		else
			if (figure[(int)getPosition().x - i][(int)getPosition().y + i]->getColor() != getColor())
			{
				move.push_back(Point((int)getPosition().x - i, (int)getPosition().y + i));
				break;
			}
			else
				break;
	}

	for (int i = 1; (getPosition().x + i < 8) && getPosition().y - i >= 0; i++)
	{
		if (!figure[(int)getPosition().x + i][(int)getPosition().y - i])
			move.push_back(Point((int)getPosition().x + i, (int)getPosition().y - i));
		else
			if (figure[(int)getPosition().x + i][(int)getPosition().y - i]->getColor() != getColor())
			{
				move.push_back(Point((int)getPosition().x + i, (int)getPosition().y - i));
				break;
			}
			else
				break;
	}

	for (int i = 1; (getPosition().x - i >= 0) && getPosition().y - i >= 0; i++)
	{
		if (!figure[(int)getPosition().x - i][(int)getPosition().y - i])
			move.push_back(Point((int)getPosition().x - i, (int)getPosition().y - i));
		else
			if (figure[(int)getPosition().x - i][(int)getPosition().y - i]->getColor() != getColor())
			{
				move.push_back(Point((int)getPosition().x - i, (int)getPosition().y - i));
				break;
			}
			else
				break;
	}
	return move;
}


std::vector<Point> BishopController::beating(FigureController *** figure) 
{ 
	std::vector<Point> move;

	for (int i = 1; (getPosition().x + i < 8) && (getPosition().y + i < 8); i++)
	{
		if (!figure[(int)getPosition().x + i][(int)getPosition().y + i])
		{
			move.push_back(Point((int)getPosition().x + i, (int)getPosition().y + i));
		}
		else
		{
			if (figure[(int)getPosition().x + i][(int)getPosition().y + i]->getColor() != getColor())
			{
				move.push_back(Point((int)getPosition().x + i, (int)getPosition().y + i));
				break;
			}
			else
				break;
		}
	}

	for (int i = 1; (getPosition().x - i >= 0) && (getPosition().y + i < 8); i++)
	{
		if (!figure[(int)getPosition().x - i][(int)getPosition().y + i])
			move.push_back(Point((int)getPosition().x - i, (int)getPosition().y + i));
		else
			if (figure[(int)getPosition().x - i][(int)getPosition().y + i]->getColor() != getColor())
			{
				move.push_back(Point((int)getPosition().x - i, (int)getPosition().y + i));
				break;
			}
			else
				break;
	}

	for (int i = 1; (getPosition().x + i < 8) && getPosition().y - i >= 0; i++)
	{
		if (!figure[(int)getPosition().x + i][(int)getPosition().y - i])
			move.push_back(Point((int)getPosition().x + i, (int)getPosition().y - i));
		else
			if (figure[(int)getPosition().x + i][(int)getPosition().y - i]->getColor() != getColor())
			{
				move.push_back(Point((int)getPosition().x + i, (int)getPosition().y - i));
				break;
			}
			else
				break;
	}

	for (int i = 1; (getPosition().x - i >= 0) && getPosition().y - i >= 0; i++)
	{
		if (!figure[(int)getPosition().x - i][(int)getPosition().y - i])
			move.push_back(Point((int)getPosition().x - i, (int)getPosition().y - i));
		else
			if (figure[(int)getPosition().x - i][(int)getPosition().y - i]->getColor() != getColor())
			{
				move.push_back(Point((int)getPosition().x - i, (int)getPosition().y - i));
				break;
			}
			else
				break;
	}
	return move;
}

#endif // !PAWNCONTROLLER
