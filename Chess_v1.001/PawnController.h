#ifndef PAWNCONTROLLER
#define PAWNCONTROLLER

#include "FigureController.h"
#include "Panw.h"
#include "PawnView.h"

class PawnController:public FigureController
{
public:
	PawnController(Pawn * figure, PawnView * figureView) :
		FigureController(figure, figureView)
	{
	}
	~PawnController();
	virtual std::vector<Point> getAvailableMove(FigureController *** figure);
	virtual std::vector<Point> beating(FigureController *** figure);

private:

};

PawnController::~PawnController()
{

}

std::vector<Point> PawnController::getAvailableMove(FigureController *** figure)
{
	int px = this->getPosition().x;
	int py = this->getPosition().y;
	std::vector<Point> moves;

	if (this->getColor() == COLOR::WHITE)
	{
		if ((py + 1 <= 7) && !figure[px][py + 1]  )
		{
			moves.push_back(Point(px, py + 1));
			if ((py + 2 <= 7) && !figure[px][py + 2] && this->figure->isFirstMove())
				moves.push_back(Point(px, py + 2));
		}
		if ((px + 1 <= 7) && (py + 1 <= 7) && figure[px + 1][py + 1] && figure[px + 1][py + 1]->getColor() == COLOR::BLACK)
			moves.push_back(Point(px + 1, py + 1));
		if ((px - 1 >= 0) && (py + 1 <= 7) && figure[px - 1][py + 1] && figure[px - 1][py + 1]->getColor() == COLOR::BLACK)
			moves.push_back(Point(px - 1, py + 1));
	}
	else
	{
		if ((py - 1 >= 0) && !figure[px][py - 1])
		{
			moves.push_back(Point(px, py - 1));
			if ((py - 2 >= 0) && !figure[px][py - 2] && this->figure->isFirstMove())
				moves.push_back(Point(px, py - 2));
		}
		if ((px + 1 <= 7) && (py - 1 >= 0) && figure[px + 1][py - 1] && figure[px + 1][py - 1]->getColor() == COLOR::WHITE)
			moves.push_back(Point(px + 1, py - 1));
		if ((px - 1 >= 0) && (py - 1 >= 0) && figure[px - 1][py - 1] && figure[px - 1][py - 1]->getColor() == COLOR::WHITE)
			moves.push_back(Point(px - 1, py - 1));
	}
	return moves;
}

std::vector<Point> PawnController::beating(FigureController *** figure)
{
	std::vector<Point> v;

	if (getColor() == COLOR::WHITE)
	{
		if (getPosition().x<7 && getPosition().y<7)
			v.push_back(Point((int)getPosition().x + 1, (int)getPosition().y + 1));
		if (getPosition().x>0 && getPosition().y<7)
			v.push_back(Point((int)getPosition().x - 1, (int)getPosition().y + 1));
	}
	else
	{
		if (getPosition().x<7 && getPosition().y >= 0)
			v.push_back(Point((int)getPosition().x + 1, (int)getPosition().y - 1));

		if (getPosition().x>0 && getPosition().y >= 0)
			v.push_back(Point((int)getPosition().x - 1, (int)getPosition().y - 1));
	}

	return v;
}


#endif // !PAWNCONTROLLER
