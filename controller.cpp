#include "controller.h"

bool controller::moveSnake(snake* pSnake) {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_QUIT:
			return false;
		case SDL_KEYUP: {
			switch (event.key.keysym.sym)
			{
			case SDLK_UP:
				if (pSnake->getDire() != snake::DOWN) {
					pSnake->setDirection(snake::UP);
				}
				break;
			case SDLK_DOWN:
				if (pSnake->getDire() != snake::UP) {
					pSnake->setDirection(snake::DOWN);
				}
				break;
			case SDLK_LEFT:
				if (pSnake->getDire() != snake::RIGHT) {
					pSnake->setDirection(snake::LEFT);
				}
				break;
			case SDLK_RIGHT:
				if (pSnake->getDire() != snake::LEFT) {
					pSnake->setDirection(snake::RIGHT);
				}
				break;
			default:
				break;
			}
		}
			break;
		default:
			break;
		}
	}

	return true;
}