#ifndef KNIGHT_H
#define KNIGHT_H

#include "Figure.h"

class Knight : public Figure
{
public:
	Knight(Point position, COLOR color);
	virtual std::vector<Point> getMove();
};


Knight::Knight(Point position, COLOR color) : Figure(position, color)
{

}

std::vector<Point> Knight::getMove()
{
	return std::vector<Point>();
}
#endif