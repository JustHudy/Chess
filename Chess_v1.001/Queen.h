#ifndef QUEEN_H
#define QUEEN_H

#include "Figure.h"

class Queen : public Figure
{
public:
	Queen(Point position, COLOR color);
	std::vector<Point> getMove();

};


Queen::Queen(Point position, COLOR color) : Figure(position, color)
{

}

std::vector<Point> Queen::getMove()
{
	return std::vector<Point>();
}
#endif