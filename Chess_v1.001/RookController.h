#ifndef ROOKCONTROLLER
#define ROOKCONTROLLER

#include "FigureController.h"
#include "Rook.h"
#include "RookView.h"

class RookController :public FigureController
{
public:
	RookController(Rook * figure, RookView * figureView) :
		FigureController(figure, figureView)
	{
	}
	~RookController();
	virtual std::vector<Point> getAvailableMove(FigureController *** figure);
	virtual std::vector<Point> beating(FigureController *** figure);

private:

};

RookController::~RookController()
{
}

std::vector<Point> RookController::getAvailableMove(FigureController *** figure)
{
	std::vector<Point> v;

	for (int i = 1; getPosition().x + i < 8; i++)
	{
		if (!figure[(int)getPosition().x + i][(int)getPosition().y])
		{
			v.push_back(Point((int)getPosition().x + i, (int)getPosition().y));
		}
		else
		{
			if (figure[(int)getPosition().x + i][(int)getPosition().y]->getColor() != getColor())
			{
				v.push_back(Point((int)getPosition().x + i, (int)getPosition().y));
				break;
			}
			else
				break;
		}
	}

	for (int i = 1; getPosition().x - i >= 0; i++)
	{
		if (!figure[(int)getPosition().x - i][(int)getPosition().y])
			v.push_back(Point((int)getPosition().x - i, (int)getPosition().y));
		else
			if (figure[(int)getPosition().x - i][(int)getPosition().y]->getColor() != getColor())
			{
				v.push_back(Point((int)getPosition().x - i, (int)getPosition().y));
				break;
			}
			else
				break;
	}

	for (int i = 1; getPosition().y + i < 8; i++)
	{
		if (!figure[(int)getPosition().x][(int)getPosition().y + i])
			v.push_back(Point((int)getPosition().x, (int)getPosition().y + i));
		else
			if (figure[(int)getPosition().x][(int)getPosition().y + i]->getColor() != getColor())
			{
				v.push_back(Point((int)getPosition().x, (int)getPosition().y + i));
				break;
			}
			else
				break;
	}

	for (int i = 1; getPosition().y - i >= 0; i++)
	{
		if (!figure[(int)getPosition().x][(int)getPosition().y - i])
			v.push_back(Point((int)getPosition().x, (int)getPosition().y - i));
		else
			if (figure[(int)getPosition().x][(int)getPosition().y - i]->getColor() != getColor())
			{
				v.push_back(Point((int)getPosition().x, (int)getPosition().y - i));
				break;
			}
			else
				break;
	}
	return v;
}

std::vector<Point> RookController::beating(FigureController *** figure)
{
	std::vector<Point> v;

	for (int i = 1; getPosition().x + i < 8; i++)
	{
		if (!figure[(int)getPosition().x + i][(int)getPosition().y])
		{
			v.push_back(Point((int)getPosition().x + i, (int)getPosition().y));
		}
		else
		{
			if (figure[(int)getPosition().x + i][(int)getPosition().y]->getColor() != getColor())
			{
				v.push_back(Point((int)getPosition().x + i, (int)getPosition().y));
				break;
			}
			else
				break;
		}
	}

	for (int i = 1; getPosition().x - i >= 0; i++)
	{
		if (!figure[(int)getPosition().x - i][(int)getPosition().y])
			v.push_back(Point((int)getPosition().x - i, (int)getPosition().y));
		else
			if (figure[(int)getPosition().x - i][(int)getPosition().y]->getColor() != getColor())
			{
				v.push_back(Point((int)getPosition().x - i, (int)getPosition().y));

				break;
			}
			else
				break;
	}

	for (int i = 1; getPosition().y + i < 8; i++)
	{
		if (!figure[(int)getPosition().x][(int)getPosition().y + i])
			v.push_back(Point((int)getPosition().x, (int)getPosition().y + i));
		else
			if (figure[(int)getPosition().x][(int)getPosition().y + i]->getColor() != getColor())
			{
				v.push_back(Point((int)getPosition().x, (int)getPosition().y + i));
				break;
			}
			else
				break;
	}

	for (int i = 1; getPosition().y - i >= 0; i++)
	{
		if (!figure[(int)getPosition().x][(int)getPosition().y - i])
			v.push_back(Point((int)getPosition().x, (int)getPosition().y - i));
		else
			if (figure[(int)getPosition().x][(int)getPosition().y - i]->getColor() != getColor())
			{
				v.push_back(Point((int)getPosition().x, (int)getPosition().y - i));
				break;
			}
			else
				break;
	}
	return v;
}


#endif // !PAWNCONTROLLER
