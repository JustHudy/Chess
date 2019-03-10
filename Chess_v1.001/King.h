#ifndef KING_H
#define KING_H
#include "Figure.h"

class King : public Figure
{
private:

public:
	King(Point position, COLOR color);
	std::vector<Point> getMove();
};


King::King(Point position, COLOR color) : Figure(position, color)
{

}

std::vector<Point> King::getMove()
{
	return std::vector<Point>();
}
#endif