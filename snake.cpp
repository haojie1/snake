#include "snake.h"
#include <cmath>

void snake::updateHead() {
	//step1: move the head according to the direction
	switch (_dire)
	{
	case direction::UP:
		_head_y -= _speed;
		break;
	case direction::DOWN:
		_head_y += _speed;
		break;
	case direction::LEFT:
		_head_x -= _speed;
		break;
	case direction::RIGHT:
		_head_x += _speed;
		break;
	default:
		break;
	}

	// in case of snake runs out of the window
	_head_x = fmodf(_head_x + _gridNumberRow, _gridNumberRow);
	_head_y = fmodf(_head_y + _gridNumberCol, _gridNumberCol);
	//step2: move the body forward
}

void snake::updateHeadPos(food* pFood) {
	//check if head position changes
	int newHead_x = static_cast<int>(_head_x);
	int newHead_y = static_cast<int>(_head_y);

	if (newHead_x!=_prevHead_x || newHead_y!=_prevHead_y) {
		for (auto iter = _body.begin(); iter!=_body.end(); ++iter) {
			if ((newHead_x==(*iter).x) && (newHead_y==(*iter).y)) {
				_alive = false;
				return;
			}
		}
		if (catchFood(pFood)) {
			_body.insert(_body.begin(), {newHead_x, newHead_y});
			_speed = baseSpeed + baseSpeed * log10(_body.size());
			_catchFood = true;

		} else {
			_body.insert(_body.begin(), {newHead_x, newHead_y});
			_body.pop_back();
		}
		_prevHead_x = newHead_x;
		_prevHead_y = newHead_y;
	}
}


void snake::update(food* pFood)
{
	if (_alive) {
		_catchFood = false;
		updateHead();
		updateHeadPos(pFood);
	}
}


bool snake::catchFood(food* pFood) {
	if ((static_cast<int>(_head_x) == pFood->getX())  && ((static_cast<int>(_head_y) == pFood->getY()) )) {
		pFood->updatePos();
		return true;
	} else {
		return false;
	}
}
