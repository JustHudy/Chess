#ifndef GAME_H
#define GAME_H

#include "Scene.h"

class Game
{
public:
	~Game();
	static Game * getInstance();
	void select(Point point);
	void selectFigure(Point point);
	void selectFieldForMove(Point point);
	void changeTurn();
	bool checkIfCheck();
	bool checkIfMate();
	bool castling(Point point);
private:
	Game();
	static Game * instance;
	Board * board;
	COLOR turn;
	bool figureSelected;
	FigureController *** figure;
	GraphicsObject *** field;
	Scene * scene;
	Point selectedFigure;
	void swap(Point a, Point b);
};

Game * Game::instance = nullptr;

Game * Game::getInstance()
{
	if (!instance) 
		instance = new Game();
	return instance;
}

Game::Game()
{
	this->board = Board::getInstance();
	turn = COLOR::WHITE;
	figureSelected = false;
	figure = board->getFigures();
	field = board->getFileds();
	scene = Scene::getInstance();
}

Game::~Game()
{
	
}

void Game::select(Point point)
{
	if(castling(point)) return;
	if (figureSelected) selectFieldForMove(point);
	selectFigure(point);
	checkIfMate();

}

void Game::selectFigure(Point point)
{

	if (figure[point.x][point.y] && figure[point.x][point.y]->getColor() == turn)
	{
		cout << figure[point.x][point.y]->getPosition().x;
		if (!figureSelected && !figure[point.x][point.y]->isSelected())
		{
			selectedFigure.x = point.x;
			selectedFigure.y = point.y;
			
			figure[point.x][point.y]->select();
			figureSelected = true;
		}
		else if (figureSelected && figure[point.x][point.y]->isSelected())
		{
			figure[point.x][point.y]->unselect();
			figureSelected = false;
		}
	}
}

void Game::selectFieldForMove(Point point)
{
//	cout << typeid(*figure[0][0]).name() << endl;

	std::vector<Point> availableFields = figure[selectedFigure.x][selectedFigure.y]->getAvailableMove(figure);
	Point temp(-1, -1);
	for (int i = 0; i < availableFields.size(); i++)
	{
		if (point == availableFields[i])
		{
			temp = point;
		}
	}
	if (temp == point)
	{
		if (!figure[point.x][point.y])
		{
			swap(selectedFigure, point);
			
			if (!checkIfCheck())
			{
				changeTurn();
				figureSelected = false;
				figure[point.x][point.y]->unselect();
				figure[point.x][point.y]->moved();

			}
			else
			{
				swap(selectedFigure, point);
			}

		}
		else
		{
			//scene->deleteElement(figure[point.x][point.y]->getView()->getId());
			
			swap(selectedFigure, point);

			auto c = figure[selectedFigure.x][selectedFigure.y];
			figure[selectedFigure.x][selectedFigure.y] = nullptr;

			if (!checkIfCheck())
			{
				scene->deleteElement(c->getView()->getId());
				delete c;
				changeTurn();
				figureSelected = false;
				figure[point.x][point.y]->unselect();
				figure[point.x][point.y]->moved();
			}
			else
			{
				figure[selectedFigure.x][selectedFigure.y] = c;
				swap(selectedFigure, point);
			}
			
		}
	}
	cout << checkIfCheck();
}

void Game::swap(Point a, Point b)
{
	if (figure[a.x][a.y]) figure[a.x][a.y]->setPosition(b);
	if (figure[b.x][b.y]) figure[b.x][b.y]->setPosition(a);

	FigureController * c;
	c = figure[a.x][a.y];
	figure[a.x][a.y] = figure[b.x][b.y];
	figure[b.x][b.y] = c;
}

void Game::changeTurn()
{
	if (turn == COLOR::WHITE)
	{
		turn = COLOR::BLACK;
		Controls::cameraFromBlack();
	}
	else
	{
		turn = COLOR::WHITE;
		Controls::cameraFromWhite();
	}
}

bool Game::checkIfCheck()
{
	Point king;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (figure[i][j] && figure[i][j]->getColor() == turn && (typeid(*figure[i][j]) == typeid(KingController)))
			{
				king.x = i;
				king.y = j;
			}
		}
	}

	std::vector<Point> v2;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (figure[i][j] && figure[i][j]->getColor() != turn)
			{
				vector<Point> vtemp;
				vtemp = figure[i][j]->beating(figure);
				for (int k = 0; k < vtemp.size(); k++)
					v2.push_back(vtemp[k]);
			}
		}
	}

	for (int i = 0; i < v2.size(); i++)
	{
		if (king == v2[i])
		{
			cout << "szach\n";
			return true;
		}
	}
	return false;
}

bool Game::checkIfMate()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (figure[i][j] && figure[i][j]->getColor() == turn)
			{
				vector<Point> temp = figure[i][j]->getAvailableMove(figure);
				for (int k = 0; k < temp.size(); k++)
				{
					bool state = true;
					auto c = figure[temp[k].x][temp[k].y];
					figure[temp[k].x][temp[k].y] = nullptr;
					swap(temp[k], Point(i, j));
					state = checkIfCheck();
					swap(temp[k], Point(i, j));
					figure[temp[k].x][temp[k].y] = c;
					if (!state) return false;
				}
			}
		}
	}
	cout << "MAT!!!!" << endl;
	return true;
}

bool Game::castling(Point point)
{
	if (figureSelected &&
		(typeid(*figure[selectedFigure.x][selectedFigure.y]) == typeid(KingController)) &&
		figure[point.x][point.y] &&
		figure[selectedFigure.x][selectedFigure.y]->getColor() == figure[point.x][point.y]->getColor() &&
		(typeid(*figure[point.x][point.y]) == typeid(RookController)) &&
		figure[selectedFigure.x][selectedFigure.y]->isFirstMove() &&
		figure[point.x][point.y]->isFirstMove() &&
		!checkIfCheck()
		)
	{
		vector<Point> vec;
		
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (figure[i][j] && figure[i][j]->getColor() != turn)
				{
					vector<Point> temp = figure[i][j]->getAvailableMove(figure);
					vec.insert(vec.end(), temp.begin(), temp.end());
				}
			}
		}

		if (figure[point.x][point.y]->getPosition() == Point(0, 0))
		{
			if (!figure[1][0] && !figure[2][0])
			{
				for (int i = 0; i < vec.size(); i++)
				{
					cout << "x = " << vec[i].x << " y = " << vec[i].y << endl;
					if (vec[i] == Point(1, 0) || vec[i] == Point(2, 0)) return false;
				}
				figure[selectedFigure.x][selectedFigure.y]->unselect();
				swap(point, Point(2,0));
				swap(Point(1, 0), selectedFigure);
				
				figureSelected = false;
				changeTurn();
				return true;
			}
		}
		else if (figure[point.x][point.y]->getPosition() == Point(7, 0))
		{
			if (!figure[4][0] && !figure[5][0] && !figure[6][0])
			{
				for (int i = 0; i < vec.size(); i++)
				{
					cout << "x = " << vec[i].x << " y = " << vec[i].y << endl;
					if (vec[i] == Point(4, 0) || vec[i] == Point(5, 0) || vec[i] == Point(6, 0)) return false;
				}
				figure[selectedFigure.x][selectedFigure.y]->unselect();
				swap(point, Point(5, 0));
				swap(Point(6, 0), selectedFigure);

				figureSelected = false;
				changeTurn();
				return true;
			}
		}
		else if (figure[point.x][point.y]->getPosition() == Point(0, 7))
		{
			if (!figure[1][7] && !figure[2][7])
			{
				for (int i = 0; i < vec.size(); i++)
				{
					cout << "x = " << vec[i].x << " y = " << vec[i].y << endl;
					if (vec[i] == Point(1, 7) || vec[i] == Point(2, 7)) return false;
				}
				figure[selectedFigure.x][selectedFigure.y]->unselect();
				swap(point, Point(2, 7));
				swap(Point(1, 7), selectedFigure);

				figureSelected = false;
				changeTurn();
				return true;
			}
		}
		else if (figure[point.x][point.y]->getPosition() == Point(7, 7))
		{
			if (!figure[4][7] && !figure[5][7] && !figure[6][7])
			{
				for (int i = 0; i < vec.size(); i++)
				{
					cout << "x = " << vec[i].x << " y = " << vec[i].y << endl;
					if (vec[i] == Point(4, 7) || vec[i] == Point(5, 7) || vec[i] == Point(6, 7)) return false;
				}
				figure[selectedFigure.x][selectedFigure.y]->unselect();
				swap(point, Point(5, 7));
				swap(Point(6, 7), selectedFigure);

				figureSelected = false;
				changeTurn();
				return true;
			}
		}
	}
	return false;
}

#endif // !GAME_H