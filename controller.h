#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include "snake.h"
#include "food.h"
#include <SDL2/SDL.h>

class controller {
public:
	bool moveSnake(snake* pSnake);
};

#endif /*__CONTROLLER_H__*/