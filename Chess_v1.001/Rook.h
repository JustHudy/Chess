#ifndef ROOK_H
#define ROOK_H

#include "Figure.h"

class Rook : public Figure
{
private:

public:
	Rook(Point position, COLOR color);
	virtual std::vector<Point> getMove();

};


Rook::Rook(Point position, COLOR color) : Figure(position, color)
{

}

std::vector<Point> Rook::getMove()
{
	return std::vector<Point>();
}
#endif