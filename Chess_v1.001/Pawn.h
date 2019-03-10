#ifndef PAWN_H
#define PAWN_H
#include "Figure.h"

class Pawn : public Figure
{
private:

public:
	Pawn(Point position, COLOR color);
};



Pawn::Pawn(Point position, COLOR color): Figure(position, color)
{

}
#endif