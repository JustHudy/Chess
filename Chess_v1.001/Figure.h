#ifndef FIGURE_H
#define FIGURE_H
#include "Point.h"
#include <vector>
enum COLOR { WHITE, BLACK, GRAY, BLUE };
std::map < COLOR, glm::vec3> Color;

class Figure
{
private:
	Point position;
	COLOR color;
	bool selected; 
	bool firstMove;
public:
	Figure(Point position, COLOR color);
	~Figure() {}
	virtual void select();
	virtual void unselect();
	virtual std::vector<Point> getMove() = 0;
	virtual bool isSelected() const;
	virtual bool isFirstMove() const { return firstMove; };
	virtual Point getPosition() const;
	virtual void setPosition(Point position);
	virtual COLOR getColor();
	void moved();
};

Figure::Figure(Point position, COLOR color)
{
	this->position = position;
	this->color = color;
	this->selected = false;
	this->firstMove = true;
}

void Figure::moved()
{
	firstMove = false;
}


void Figure::select()
{
	this->selected = true;
}
void Figure::unselect()
{
	this->selected = false;
}

bool Figure::isSelected() const
{
	return selected;
}

Point Figure::getPosition() const
{
	return this->position;
}

void Figure::setPosition(Point position)
{
	this->position = position;
}

COLOR Figure::getColor()
{
	return this->color;
}
#endif // !FIGURE_H
