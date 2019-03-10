#ifndef BISHOP_H
#define BISHOP_H

#include "Figure.h"

class Bishop : public Figure
{
public:
	Bishop(Point position, COLOR color);
	std::vector<Point> getMove();
};


Bishop::Bishop(Point position, COLOR color) : Figure(position, color)
{

}

std::vector<Point> Bishop::getMove()
{
	return std::vector<Point>();
}
#endif