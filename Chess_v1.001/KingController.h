#ifndef KINGCONTROLLER_H
#define KINGCONTROLLER_H

#include "FigureController.h"
#include "King.h"
#include "KingView.h"

class KingController :public FigureController
{
public:
	KingController(King * figure, KingView * figureView) :
		FigureController(figure, figureView)
	{
	}
	~KingController();
	virtual std::vector<Point> getAvailableMove(FigureController *** figure);
	virtual std::vector<Point> beating(FigureController *** figure);

private:

};

KingController::~KingController()
{
}

std::vector<Point> KingController::getAvailableMove(FigureController *** figure)
{ 
	std::vector<Point> v;
	std::vector<Point> v2;

	if (((getPosition().x + 1) < 8) && ((getPosition().y + 1 < 8)))
		if (!figure[(int)getPosition().x + 1][(int)getPosition().y + 1])
			v.push_back(Point(getPosition().x + 1, getPosition().y + 1));
		else if (figure[(int)getPosition().x + 1][(int)getPosition().y + 1]->getColor() != getColor())
			v.push_back(Point(getPosition().x + 1, getPosition().y + 1));

	if (((getPosition().x + 1) < 8) && ((getPosition().y - 0 < 8)))
		if (!figure[(int)getPosition().x + 1][(int)getPosition().y - 0])
			v.push_back(Point(getPosition().x + 1, getPosition().y - 0));
		else if (figure[(int)getPosition().x + 1][(int)getPosition().y - 0]->getColor() != getColor())
			v.push_back(Point(getPosition().x + 1, getPosition().y - 0));

	if (((getPosition().x + 1) < 8) && ((getPosition().y - 1 >= 0)))
		if (!figure[(int)getPosition().x + 1][(int)getPosition().y - 1])
			v.push_back(Point(getPosition().x + 1, getPosition().y - 1));
		else if (figure[(int)getPosition().x + 1][(int)getPosition().y - 1]->getColor() != getColor())
			v.push_back(Point(getPosition().x + 1, getPosition().y - 1));

	if (((getPosition().x + 0) < 8) && ((getPosition().y - 1 >= 0)))
		if (!figure[(int)getPosition().x + 0][(int)getPosition().y - 1])
			v.push_back(Point(getPosition().x + 0, getPosition().y - 1));
		else if (figure[(int)getPosition().x + 0][(int)getPosition().y - 1]->getColor() != getColor())
			v.push_back(Point(getPosition().x + 0, getPosition().y - 1));

	if (((getPosition().x - 1) >=0) && ((getPosition().y - 1 >= 0)))
		if (!figure[(int)getPosition().x - 1][(int)getPosition().y - 1])
			v.push_back(Point(getPosition().x - 1, getPosition().y - 1));
		else if (figure[(int)getPosition().x - 1][(int)getPosition().y - 1]->getColor() != getColor())
			v.push_back(Point(getPosition().x - 1, getPosition().y - 1));

	if (((getPosition().x - 1) >= 0) && ((getPosition().y - 0 >= 0)))
		if (!figure[(int)getPosition().x - 1][(int)getPosition().y - 0])
			v.push_back(Point(getPosition().x - 1, getPosition().y - 0));
		else if (figure[(int)getPosition().x - 1][(int)getPosition().y - 0]->getColor() != getColor())
			v.push_back(Point(getPosition().x - 1, getPosition().y - 0));

	if (((getPosition().x - 1) >= 0) && ((getPosition().y + 1 < 8)))
		if (!figure[(int)getPosition().x - 1][(int)getPosition().y + 1])
			v.push_back(Point(getPosition().x - 1, getPosition().y + 1));
		else if (figure[(int)getPosition().x - 1][(int)getPosition().y + 1]->getColor() != getColor())
			v.push_back(Point(getPosition().x - 1, getPosition().y + 1));

	if (((getPosition().x - 0) >= 0) && ((getPosition().y + 1 < 8)))
		if (!figure[(int)getPosition().x - 0][(int)getPosition().y + 1])
			v.push_back(Point(getPosition().x - 0, getPosition().y + 1));
		else if (figure[(int)getPosition().x - 0][(int)getPosition().y + 1]->getColor() != getColor())
			v.push_back(Point(getPosition().x - 0, getPosition().y + 1));

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (figure[i][j] && figure[i][j]->getColor() != getColor())
			{
				vector<Point> vtemp;
				vtemp = figure[i][j]->beating(figure);
				for (int k = 0; k < vtemp.size(); k++)
					v2.push_back(vtemp[k]);
			}
		}
	}


	for (int i = 0; i < v2.size(); i++)
	{
		Point temp = v2[i];
		for (int j = 0; j < v.size(); j++)
		{
			if (temp == v[j])
			{
				v.erase(v.begin() + j--);
			}
		}
	}
	return v;
}

std::vector<Point> KingController::beating(FigureController *** figure)
{ 
	std::vector<Point> v;
	std::vector<Point> v2;

	if (((getPosition().x + 1) < 8) && ((getPosition().y + 1 < 8)))
		if (!figure[(int)getPosition().x + 1][(int)getPosition().y + 1])
			v.push_back(Point(getPosition().x + 1, getPosition().y + 1));
		else if (figure[(int)getPosition().x + 1][(int)getPosition().y + 1]->getColor() != getColor())
			v.push_back(Point(getPosition().x + 1, getPosition().y + 1));

	if (((getPosition().x + 1) < 8) && ((getPosition().y - 0 < 8)))
		if (!figure[(int)getPosition().x + 1][(int)getPosition().y - 0])
			v.push_back(Point(getPosition().x + 1, getPosition().y - 0));
		else if (figure[(int)getPosition().x + 1][(int)getPosition().y - 0]->getColor() != getColor())
			v.push_back(Point(getPosition().x + 1, getPosition().y - 0));

	if (((getPosition().x + 1) < 8) && ((getPosition().y - 1 >= 0)))
		if (!figure[(int)getPosition().x + 1][(int)getPosition().y - 1])
			v.push_back(Point(getPosition().x + 1, getPosition().y - 1));
		else if (figure[(int)getPosition().x + 1][(int)getPosition().y - 1]->getColor() != getColor())
			v.push_back(Point(getPosition().x + 1, getPosition().y - 1));

	if (((getPosition().x + 0) < 8) && ((getPosition().y - 1 >= 0)))
		if (!figure[(int)getPosition().x + 0][(int)getPosition().y - 1])
			v.push_back(Point(getPosition().x + 0, getPosition().y - 1));
		else if (figure[(int)getPosition().x + 0][(int)getPosition().y - 1]->getColor() != getColor())
			v.push_back(Point(getPosition().x + 0, getPosition().y - 1));

	if (((getPosition().x - 1) < 8) && ((getPosition().y - 1 >= 0)))
		if (!figure[(int)getPosition().x - 1][(int)getPosition().y - 1])
			v.push_back(Point(getPosition().x - 1, getPosition().y - 1));
		else if (figure[(int)getPosition().x - 1][(int)getPosition().y - 1]->getColor() != getColor())
			v.push_back(Point(getPosition().x - 1, getPosition().y - 1));

	if (((getPosition().x - 1) < 8) && ((getPosition().y - 0 < 8)))
		if (!figure[(int)getPosition().x - 1][(int)getPosition().y - 0])
			v.push_back(Point(getPosition().x - 1, getPosition().y - 0));
		else if (figure[(int)getPosition().x - 1][(int)getPosition().y - 0]->getColor() != getColor())
			v.push_back(Point(getPosition().x - 1, getPosition().y - 0));

	if (((getPosition().x - 1) < 8) && ((getPosition().y + 1 < 8)))
		if (!figure[(int)getPosition().x - 1][(int)getPosition().y + 1])
			v.push_back(Point(getPosition().x - 1, getPosition().y + 1));
		else if (figure[(int)getPosition().x - 1][(int)getPosition().y + 1]->getColor() != getColor())
			v.push_back(Point(getPosition().x - 1, getPosition().y + 1));

	if (((getPosition().x - 0) < 8) && ((getPosition().y + 1 < 8)))
		if (!figure[(int)getPosition().x - 0][(int)getPosition().y + 1])
			v.push_back(Point(getPosition().x - 0, getPosition().y + 1));
		else if (figure[(int)getPosition().x - 0][(int)getPosition().y + 1]->getColor() != getColor())
			v.push_back(Point(getPosition().x - 0, getPosition().y + 1));

	return v;
}

#endif // !PAWNCONTROLLER
