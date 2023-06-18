#ifndef __GAME_H__
#define __GAME_H__

#include "snake.h"
#include "render.h"
#include "controller.h"
#include "food.h"
#include <ctime>
#include <cmath>
#include <SDL2/SDL.h>

struct gameInfo {
	int score;
	int frameRatio;
};

class game {
private:
	snake* _pSnake;
	myRender* _pRend;
	SDL_Window* _pWindow;
	controller* _pController;
	food* _pFood;
	int _windowWidth, _windowHeigth, _gridNumberRow,
		 _gridNumberCol, _gridWidth, _gridHeight;
	int _score, _framRatio;
public:
	game(int windowWidth, int windowHeight, int gridNumberRow, int gridNumberCol) :
		_windowWidth(windowWidth), _windowHeigth(windowHeight), _gridNumberRow(gridNumberRow), _gridNumberCol(gridNumberCol), _score(0) {
			_gridWidth = _windowWidth / _gridNumberCol;
			_gridHeight= _windowHeigth/ _gridNumberRow;
			_pWindow = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
					 windowWidth, windowHeight, SDL_WINDOW_ALLOW_HIGHDPI);
			_pRend = new myRender(_pWindow, _gridWidth, _gridHeight);
			int posSnakeX, posSnakeY;
			int posFoodX, posFoodY;
			#ifdef __linux
				std::random_device _rd;
				std::mt19937 gen(_rd());
				std::uniform_int_distribution<int> distForRow(0, _gridNumberRow-1);
				std::uniform_int_distribution<int> distForCol(0, _gridNumberCol-1);
				posSnakeX = distForRow(gen);
				posFoodX = distForRow(gen);
				posSnakeY = distForCol(gen);
				posFoodY = distForCol(gen);
			#endif
			#ifdef WINVER
				srand(time(nullptr));
				posSnakeX = static_cast<int>(fmod(rand(), _gridNumberRow));
				posSnakeY = static_cast<int>(fmod(rand(), _gridNumberCol));
				posFoodX = static_cast<int>(fmod(rand(), _gridNumberRow));
				posFoodY = static_cast<int>(fmod(rand(), _gridNumberCol));
			#endif
			_pSnake = new snake(_gridNumberRow, _gridNumberCol, posSnakeX, posSnakeY);
			_pController = new controller;
			_pFood = new food(_gridNumberRow, _gridNumberCol, posFoodX, posFoodY);
		}

	~game() {
		delete _pSnake;
		delete _pFood;
		delete _pRend;
		SDL_DestroyWindow(_pWindow);
	}

	void start();
	bool quitOrRestart();
};


#endif /*__GAME_H__*/