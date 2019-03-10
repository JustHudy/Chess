#ifndef QUEENCONTROLLER_H
#define QUEENCONTROLLER_H

#include "FigureController.h"
#include "Queen.h"
#include "QueenView.h"

class QueenController :public FigureController
{
public:
	QueenController(Queen * figure, QueenView * figureView) :
		FigureController(figure, figureView)
	{
	}
	~QueenController();
	virtual std::vector<Point> getAvailableMove(FigureController *** figure);
	virtual std::vector<Point> beating(FigureController *** figure);

private:

};

QueenController::~QueenController()
{
}

std::vector<Point> QueenController::getAvailableMove(FigureController *** figure)
{ 
	std::vector<Point> move;

	for (int i = 1; getPosition().x + i < 8; i++)
	{
		if (!figure[(int)getPosition().x + i][(int)getPosition().y])
		{
			move.push_back(Point((int)getPosition().x + i, (int)getPosition().y));
		}
		else
		{
			if (figure[(int)getPosition().x + i][(int)getPosition().y]->getColor() != getColor())
			{
				move.push_back(Point((int)getPosition().x + i, (int)getPosition().y));
				break;
			}
			else
				break;
		}
	}

	for (int i = 1; getPosition().x - i >= 0; i++)
	{
		if (!figure[(int)getPosition().x - i][(int)getPosition().y])
			move.push_back(Point((int)getPosition().x - i, (int)getPosition().y));
		else
			if (figure[(int)getPosition().x - i][(int)getPosition().y]->getColor() != getColor())
			{
				move.push_back(Point((int)getPosition().x - i, (int)getPosition().y));
				break;
			}
			else
				break;
	}

	for (int i = 1; getPosition().y + i < 8; i++)
	{
		if (!figure[(int)getPosition().x][(int)getPosition().y + i])
			move.push_back(Point((int)getPosition().x, (int)getPosition().y + i));
		else
			if (figure[(int)getPosition().x][(int)getPosition().y + i]->getColor() != getColor())
			{
				move.push_back(Point((int)getPosition().x, (int)getPosition().y + i));
				break;

			}
			else
				break;
	}

	for (int i = 1; getPosition().y - i >= 0; i++)
	{
		if (!figure[(int)getPosition().x][(int)getPosition().y - i])
			move.push_back(Point((int)getPosition().x, (int)getPosition().y - i));
		else
			if (figure[(int)getPosition().x][(int)getPosition().y - i]->getColor() != getColor())
			{
				move.push_back(Point((int)getPosition().x, (int)getPosition().y - i));
				break;
			}
			else
				break;
	}

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

std::vector<Point> QueenController::beating(FigureController *** figure)
{
	std::vector<Point> move;

	for (int i = 1; getPosition().x + i < 8; i++)
	{
		if (!figure[(int)getPosition().x + i][(int)getPosition().y])
		{
			move.push_back(Point((int)getPosition().x + i, (int)getPosition().y));
		}
		else
		{
			if (figure[(int)getPosition().x + i][(int)getPosition().y]->getColor() != getColor())
			{
				move.push_back(Point((int)getPosition().x + i, (int)getPosition().y));
				break;
			}
			else
				break;
		}
	}

	for (int i = 1; getPosition().x - i >= 0; i++)
	{
		if (!figure[(int)getPosition().x - i][(int)getPosition().y])
			move.push_back(Point((int)getPosition().x - i, (int)getPosition().y));
		else
			if (figure[(int)getPosition().x - i][(int)getPosition().y]->getColor() != getColor())
			{
				move.push_back(Point((int)getPosition().x - i, (int)getPosition().y));
				break;
			}
			else
				break;
	}

	for (int i = 1; getPosition().y + i < 8; i++)
	{
		if (!figure[(int)getPosition().x][(int)getPosition().y + i])
			move.push_back(Point((int)getPosition().x, (int)getPosition().y + i));
		else
			if (figure[(int)getPosition().x][(int)getPosition().y + i]->getColor() != getColor())
			{
				move.push_back(Point((int)getPosition().x, (int)getPosition().y + i));
				break;

			}
			else
				break;
	}

	for (int i = 1; getPosition().y - i >= 0; i++)
	{
		if (!figure[(int)getPosition().x][(int)getPosition().y - i])
			move.push_back(Point((int)getPosition().x, (int)getPosition().y - i));
		else
			if (figure[(int)getPosition().x][(int)getPosition().y - i]->getColor() != getColor())
			{
				move.push_back(Point((int)getPosition().x, (int)getPosition().y - i));
				break;
			}
			else
				break;
	}

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
