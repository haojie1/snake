#ifndef __FOO_H__
#define __FOO_H__

#include <ctime>
#include <cmath>
#include <iostream>
#include <SDL2/SDL.h>

class food {
private:
	int _x, _y;
	size_t _gridNumberRow, _gridNumberCol;
	SDL_Color _color;
public:
	food(size_t gridNumberRow, size_t gridNumberCol, int x = 10, int y = 10) : 
		_x(x), _y(y), _gridNumberRow(gridNumberRow), _gridNumberCol(gridNumberCol), _color({0, 0, 255, 0}) {}
	
	int getX() const {return _x;}
	int getY() const {return _y;}
	SDL_Color getColor() const {return _color;}

	void updatePos() {
		#ifdef __linux
			std::random_device _rd;
			std::mt19937 gen(_rd());
			std::uniform_int_distribution<int> distForRow(0, _gridNumberRow-1);
			std::uniform_int_distribution<int> distForCol(0, _gridNumberCol-1);
			_x = distForRow(gen);
			_y = distForCol(gen);
		#endif
		#ifdef WINVER
			srand(time(nullptr));
			_x = static_cast<int>(fmod(rand(), _gridNumberRow));
			_y = static_cast<int>(fmod(rand(), _gridNumberCol));
		#endif
	}
};


#endif /*__FOO_H__*/