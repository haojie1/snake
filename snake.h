#ifndef __SNAKE_H__
#define __SNAKE_H__

#include <SDL2/SDL.h>
#include <vector>
#include <iostream>
#include "food.h"

using namespace std;

class snake {
public:
	enum direction {UP, DOWN, LEFT, RIGHT};
	const double baseSpeed = 0.1;
private:
	float _speed;
	float _head_x, _head_y;
	int _prevHead_x, _prevHead_y;
	vector<SDL_Point> _body;
	bool _alive, _catchFood;
	direction _dire;
	int _gridNumberRow, _gridNumberCol;
public:
	snake(int gridNumberRow, int gridNumberCol, float head_x = 0, float head_y = 0) :
		_gridNumberRow(gridNumberRow), _gridNumberCol(gridNumberCol), _head_x(head_x), _head_y(head_y),
		_speed(baseSpeed), _alive(true), _dire(DOWN) {
			_prevHead_x = static_cast<int>(_head_x);
			_prevHead_y = static_cast<int>(_head_y);
			_body.push_back({_prevHead_x, _prevHead_y});
		}

	bool catchFood(food* pFood);
	bool alive() const {return _alive;}
	bool getCatchFood() const {return _catchFood;}

	void update(food* pFood);
	void setDirection(direction d) { _dire = d; }
	direction getDire() const {return _dire;}
	float getHeadX() const {return _head_x;}
	float getHeadY() const {return _head_y;}
	std::vector<SDL_Point> getBody() const {return _body;}
private:
	void updateHead();
	void updateHeadPos(food* pFood);

};


#endif
