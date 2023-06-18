#ifndef __RENDER_H__
#define __RENDER_H__

#include <iostream>
#include <string>
#include <random>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "snake.h"
#include "food.h"

class myRender {
private:
	SDL_Color _backgroundColor;
	SDL_Renderer* _pRen;
	TTF_Font* _pFont;
	size_t _gridWidth, _gridHeight;
	SDL_Rect _rect;
	std::random_device _rd;

public:
	myRender(SDL_Window* pWindow, size_t gridWidth, size_t gridHeight) : _backgroundColor({0x1E, 0x1E, 0x1E, 0xFF}), _gridWidth(gridWidth), _gridHeight(gridHeight) {
		TTF_Init();
		_pRen = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
		_pFont = TTF_OpenFont("ww.ttf", 20);
	}

	myRender(const SDL_Color& backgroundColor, SDL_Window* pWindow, size_t gridWidth, size_t gridHeight) : _backgroundColor(backgroundColor), 
		_gridWidth(gridWidth), _gridHeight(gridHeight) {
		TTF_Init();
		_pRen = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
		_pFont = TTF_OpenFont("ww.ttf", 20);
	}

	~myRender() {
		SDL_DestroyRenderer(_pRen);
		TTF_CloseFont(_pFont);
	}

	void paint(const snake& s, const food& f);
	void showInfo(const char* info);
	bool startUI();
};


#endif /*__RENDER_H__*/