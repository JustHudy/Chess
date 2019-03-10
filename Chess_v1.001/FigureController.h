#ifndef FIGURECONTROLLER_H
#define FIGURECONTROLLER_H

#include "Figure.h"
#include "FigureView.h"

class FigureController
{
protected:
	Figure * figure;
	FigureView * figureView;
public:
	COLOR getColor() const;
	Point getPosition()const;
	vec3 getRotation()const;
	void setColor(COLOR color);
	void setPosition(Point position);
	void setRotation(vec3 rotation);
	std::vector<Point> getMove();
	FigureView * getView() const;
	void select();
	void unselect();
	void moved();
	bool isSelected();
	bool isFirstMove();
	FigureController(Figure * figure, FigureView *figureView);
	virtual std::vector<Point> getAvailableMove(FigureController *** figure) = 0;
	virtual std::vector<Point> beating(FigureController *** figure) = 0;

};

void FigureController::moved()
{
	figure->moved();
}

bool FigureController::isFirstMove()
{
	return this->figure->isFirstMove();
}


bool FigureController::isSelected()
{
	return figure->isSelected();
}

void FigureController::select()
{
	figure->select();
	figureView->select();
}

void FigureController::unselect()
{
	figure->unselect();
	figureView->unselect();
}

FigureController::FigureController(Figure * figure, FigureView * figureView)
{
	this->figure = figure;
	this->figureView = figureView;
}

COLOR FigureController::getColor() const
{
	return this->figure->getColor();
}
Point FigureController::getPosition()const
{
	return this->figure->getPosition();
}

vec3 FigureController::getRotation()const
{
	return this->figureView->getRotation();
}
void FigureController::setColor(COLOR color)
{
	this->figureView->setCurrentColor(Color[color]);
}
void FigureController::setPosition(Point position)
{
	this->figure->setPosition(position);
	this->figureView->setPosition(glm::vec3(position.x-4, 0, position.y-4));
}
void FigureController::setRotation(vec3 rotation)
{
	this->figureView->setRotation(rotation);
}

std::vector<Point> FigureController::getMove()
{
	return this->figure->getMove();
}

FigureView * FigureController::getView() const
{
	return this->figureView;
}

#endif // !FIGURECONTROLLER_H
