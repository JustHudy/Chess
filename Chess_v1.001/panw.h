#ifndef PAWN_H
#define PANW_H
#include "Figure.h"

class Pawn : public Figure
{
private:
	bool isFirstMove;
public:
	Pawn(Point position, COLOR color);
	virtual std::vector<Point> getMove();

};

Pawn::Pawn(Point position, COLOR color) : Figure(position, color)
{
	this->isFirstMove = true;

}

std::vector<Point> Pawn::getMove()
{
	return vector<Point>();
}
#endif