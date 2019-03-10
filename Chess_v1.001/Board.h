#ifndef BOARD_H
#define BOARD_H

#include "Factory.h"
class Board
{
private:
	static Board * instance;
	Factory * factory;
	Board();

	GraphicsObject *** field;
	FigureController *** figure;

public:
	~Board();

	static Board * getInstance();
	GraphicsObject *** getFileds();
	FigureController *** getFigures();
};

Board * Board::instance = nullptr;

GraphicsObject *** Board::getFileds()
{
	return field;
}

FigureController *** Board::getFigures()
{
	return figure;
}

Board::Board()
{
	factory = Factory::getInstance();
	field = new GraphicsObject**[8]();
	figure = new FigureController**[8]();
	for (int i = 0; i < 8; i++)
	{
		field[i] = new GraphicsObject*[8]();
		figure[i] = new FigureController*[8]();
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((j + i) % 2 == 0)
			{
				field[i][j] = factory->createField(COLOR::WHITE, vec3(i - 4, 0, j - 4), vec3(0, 0, 0));
			}
			else
			{
				field[i][j] = factory->createField(COLOR::GRAY, vec3(i - 4, 0, j - 4), vec3(0, 0, 0));
			}
		}
	}

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			figure[i][j] = nullptr;

	figure[0][0] = factory->createRook(COLOR::WHITE, vec3(-4.0f, 0.0f, -4.0f), vec3(0.0f, 3.14159265f, 0.0f));
	figure[1][0] = factory->createKnight(COLOR::WHITE, vec3(-3.0f, 0.0f, -4.0f), vec3(0.0f, 3.14159265f, 0.0f));
	figure[2][0] = factory->createBishop(COLOR::WHITE, vec3(-2.0f, 0.0f, -4.0f), vec3(0.0f, 3.14159265f, 0.0f));
	figure[3][0] = factory->createKing(COLOR::WHITE, vec3(-1.0f, 0.0f, -4.0f), vec3(0.0f, 3.14159265f, 0.0f));
	figure[4][0] = factory->createQueen(COLOR::WHITE, vec3(-0.0f, 0.0f, -4.0f), vec3(0.0f, 3.14159265f, 0.0f));
	figure[5][0] = factory->createBishop(COLOR::WHITE, vec3(1.0f, 0.0f, -4.0f), vec3(0.0f, 3.14159265f, 0.0f));
	figure[6][0] = factory->createKnight(COLOR::WHITE, vec3(2.0f, 0.0f, -4.0f), vec3(0.0f, 3.14159265f, 0.0f));
	figure[7][0] = factory->createRook(COLOR::WHITE, vec3(3.0f, 0.0f, -4.0f), vec3(0.0f, 3.14159265f, 0.0f));

	figure[0][1] = factory->createPawn(COLOR::WHITE, vec3(-4.0f, 0.0f, -3.0f), vec3(0.0f, 3.14159265f, 0.0f));
	figure[1][1] = factory->createPawn(COLOR::WHITE, vec3(-3.0f, 0.0f, -3.0f), vec3(0.0f, 3.14159265f, 0.0f));
	figure[2][1] = factory->createPawn(COLOR::WHITE, vec3(-2.0f, 0.0f, -3.0f), vec3(0.0f, 3.14159265f, 0.0f));
	figure[3][1] = factory->createPawn(COLOR::WHITE, vec3(-1.0f, 0.0f, -3.0f), vec3(0.0f, 3.14159265f, 0.0f));
	figure[4][1] = factory->createPawn(COLOR::WHITE, vec3(0.0f, 0.0f, -3.0f), vec3(0.0f, 3.14159265f, 0.0f));
	figure[5][1] = factory->createPawn(COLOR::WHITE, vec3(1.0f, 0.0f, -3.0f), vec3(0.0f, 3.14159265f, 0.0f));
	figure[6][1] = factory->createPawn(COLOR::WHITE, vec3(2.0f, 0.0f, -3.0f), vec3(0.0f, 3.14159265f, 0.0f));
	figure[7][1] = factory->createPawn(COLOR::WHITE, vec3(3.0f, 0.0f, -3.0f), vec3(0.0f, 3.14159265f, 0.0f));


	figure[0][7] = factory->createRook(COLOR::BLACK, vec3(-4.0f, 0.0f, 3.0f), vec3(0.0f, 0.0f, 0.0f));
	figure[1][7] = factory->createKnight(COLOR::BLACK, vec3(-3.0f, 0.0f, 3.0f), vec3(0.0f, 0.0f, 0.0f));
	figure[2][7] = factory->createBishop(COLOR::BLACK, vec3(-2.0f, 0.0f, 3.0f), vec3(0.0f, 0.0f, 0.0f));
	figure[3][7] = factory->createKing(COLOR::BLACK, vec3(-1.0f, 0.0f, 3.0f), vec3(0.0f, 0.0f, 0.0f));
	figure[4][7] = factory->createQueen(COLOR::BLACK, vec3(0.0f, 0.0f, 3.0f), vec3(0.0f, 0.0f, 0.0f));
	figure[5][7] = factory->createBishop(COLOR::BLACK, vec3(1.0f, 0.0f, 3.0f), vec3(0.0f, 0.0f, 0.0f));
	figure[6][7] = factory->createKnight(COLOR::BLACK, vec3(2.0f, 0.0f, 3.0f), vec3(0.0f, 0.0f, 0.0f));
	figure[7][7] = factory->createRook(COLOR::BLACK, vec3(3.0f, 0.0f, 3.0f), vec3(0.0f, 0.0f, 0.0f));

	figure[0][6] = factory->createPawn(COLOR::BLACK, vec3(-4.0f, 0.0f, 2.0f), vec3(0.0f, 0.0f, 0.0f));
	figure[1][6] = factory->createPawn(COLOR::BLACK, vec3(-3.0f, 0.0f, 2.0f), vec3(0.0f, 0.0f, 0.0f));
	figure[2][6] = factory->createPawn(COLOR::BLACK, vec3(-2.0f, 0.0f, 2.0f), vec3(0.0f, 0.0f, 0.0f));
	figure[3][6] = factory->createPawn(COLOR::BLACK, vec3(-1.0f, 0.0f, 2.0f), vec3(0.0f, 0.0f, 0.0f));
	figure[4][6] = factory->createPawn(COLOR::BLACK, vec3(-0.0f, 0.0f, 2.0f), vec3(0.0f, 0.0f, 0.0f));
	figure[5][6] = factory->createPawn(COLOR::BLACK, vec3(1.0f, 0.0f, 2.0f), vec3(0.0f, 0.0f, 0.0f));
	figure[6][6] = factory->createPawn(COLOR::BLACK, vec3(2.0f, 0.0f, 2.0f), vec3(0.0f, 0.0f, 0.0f));
	figure[7][6] = factory->createPawn(COLOR::BLACK, vec3(3.0f, 0.0f, 2.0f), vec3(0.0f, 0.0f, 0.0f));
}

Board::~Board()
{
}

Board * Board::getInstance()
{
	if (!instance)
		instance = new Board();
	return instance;
}

#endif // !BOARD_H
