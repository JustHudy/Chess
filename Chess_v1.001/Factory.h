#ifndef FACTORY_H
#define FACTORY_H
#include <map>
#include <string>

#include "PawnController.h"
#include "RookController.h"
#include "KnightController.h"
#include "BishopController.h"
#include "QueenController.h"
#include "KingController.h"
#include "FieldView.h"


const unsigned int numOfObiectTypes = 7;

char *fileName[] = {
	"figury/field.obj", "figury/pawn.obj", "figury/rook.obj", "figury/knight.obj", "figury/bishop.obj",  "figury/queen.obj", "figury/king.obj"
};

enum OBIECT {FIELD, PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING};

glm::vec3 White(1.0f, 1.0f, 1.0f);
glm::vec3 Black(0.4f, 0.4f, 0.4f);
glm::vec3 Gray(0.5f, 0.5f, 0.5f);
glm::vec3 Blue(0.0f, 0.0f, 0.0f);


class Factory
{
private:
	static Factory * Instance;
	GLuint shader;
	GLuint indices[numOfObiectTypes];
	GLuint vertexbuffer[numOfObiectTypes];
	GLuint normalbuffer[numOfObiectTypes];
	GLuint elementbuffer[numOfObiectTypes];

	Factory();
public:
	~Factory();
	static Factory * getInstance();
	PawnController * createPawn(COLOR color, glm::vec3 position, glm::vec3 rotation);
	RookController * createRook(COLOR color, glm::vec3 position, glm::vec3 rotation);
	KnightController * createKnight(COLOR color, glm::vec3 position, glm::vec3 rotation);
	BishopController * createBishop(COLOR color, glm::vec3 position, glm::vec3 rotation);
	QueenController * createQueen(COLOR color, glm::vec3 position, glm::vec3 rotation);
	KingController * createKing(COLOR color, glm::vec3 position, glm::vec3 rotation);
	FieldView * createField(COLOR color, glm::vec3 position, glm::vec3 rotation);
};

Factory * Factory::Instance = nullptr;

Factory * Factory::getInstance()
{
	if (!Instance) Instance = new Factory();
	return Instance;
}

PawnController * Factory::createPawn(COLOR color, glm::vec3 position, glm::vec3 rotation)
{
	return new PawnController(new Pawn(Point(position.x + 4, position.z + 4), color), new PawnView(Color[color], position, rotation, shader, vertexbuffer[PAWN], normalbuffer[PAWN], elementbuffer[PAWN], indices[PAWN]));
}

RookController * Factory::createRook(COLOR color, glm::vec3 position, glm::vec3 rotation)
{
	return new RookController(new Rook(Point(position.x + 4, position.z + 4), color), new RookView(Color[color], position, rotation, shader, vertexbuffer[ROOK], normalbuffer[ROOK], elementbuffer[ROOK], indices[ROOK]));
}

KnightController * Factory::createKnight(COLOR color, glm::vec3 position, glm::vec3 rotation)
{
	return new KnightController(new Knight(Point(position.x + 4, position.z + 4), color), new KnightView(Color[color], position, rotation, shader, vertexbuffer[KNIGHT], normalbuffer[KNIGHT], elementbuffer[KNIGHT], indices[KNIGHT]));
}

BishopController * Factory::createBishop(COLOR color, glm::vec3 position, glm::vec3 rotation)
{
	return new BishopController(new Bishop(Point(position.x + 4, position.z + 4), color), new BishopView(Color[color], position, rotation, shader, vertexbuffer[BISHOP], normalbuffer[BISHOP], elementbuffer[BISHOP], indices[BISHOP]));
}

QueenController * Factory::createQueen(COLOR color, glm::vec3 position, glm::vec3 rotation)
{
	return new QueenController(new Queen(Point(position.x + 4, position.z + 4), color), new QueenView(Color[color], position, rotation, shader, vertexbuffer[QUEEN], normalbuffer[QUEEN], elementbuffer[QUEEN], indices[QUEEN]));
}

KingController * Factory::createKing(COLOR color, glm::vec3 position, glm::vec3 rotation)
{
	return new KingController(new King(Point(position.x+4, position.z+4), color), new KingView(Color[color], position, rotation, shader, vertexbuffer[KING], normalbuffer[KING], elementbuffer[KING], indices[KING]));
}

FieldView * Factory::createField(COLOR color, glm::vec3 position, glm::vec3 rotation)
{
	return new FieldView(Color[color], position, rotation, shader, vertexbuffer[FIELD], normalbuffer[FIELD], elementbuffer[FIELD], indices[FIELD]);
}


Factory::Factory() 
{
	shader = Loader::loadShader("StandardShading.vertexshader", "StandardShading.fragmentshader");
	
	for (int i = 0; i < numOfObiectTypes; i++)
	{
		Loader::loadObj(fileName[i], vertexbuffer[i], normalbuffer[i], elementbuffer[i], indices[i]);
	}
}

Factory::~Factory()
{
	for(int i = 0; i < numOfObiectTypes; i++)
	{
		glDeleteBuffers(1, &vertexbuffer[i]);
		glDeleteBuffers(1, &normalbuffer[i]);
		glDeleteBuffers(1, &elementbuffer[i]);
	}
}

#endif // !FACTORY_H

