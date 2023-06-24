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
	SDL_Surface* _pExitSurface, *_pSnakeSurface, *_pStartSurface;
	SDL_Texture* _pExitTexture, *_pSnakeTexture, *_pStartTexture;
	SDL_Renderer* _pRen;
	TTF_Font* _pFont;
	size_t _gridWidth, _gridHeight;
	SDL_Rect _rect;
	std::random_device _rd;

public:
	myRender(SDL_Window* pWindow, size_t gridWidth, size_t gridHeight) : _backgroundColor({0x1E, 0x1E, 0x1E, 0xFF}), 
		_gridWidth(gridWidth), _gridHeight(gridHeight)
	 {
		TTF_Init();
		_pRen = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
		_pFont = TTF_OpenFont("ww.ttf", 20);
		_pExitSurface = IMG_Load("./src/image/exit.jpg");
		_pExitTexture = SDL_CreateTextureFromSurface(_pRen, _pExitSurface);

		_pSnakeSurface = IMG_Load("./src/image/snake.jpg");
		_pSnakeTexture = SDL_CreateTextureFromSurface(_pRen, _pSnakeSurface);

		_pStartSurface = IMG_Load("./src/image/start.png");
		_pStartTexture = SDL_CreateTextureFromSurface(_pRen, _pStartSurface);
	}

	myRender(const SDL_Color& backgroundColor, SDL_Window* pWindow, size_t gridWidth, size_t gridHeight) : _backgroundColor(backgroundColor), 
		_gridWidth(gridWidth), _gridHeight(gridHeight) {
		TTF_Init();
		_pRen = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
		_pFont = TTF_OpenFont("ww.ttf", 20);
		_pExitSurface = IMG_Load("./src/image/exit.jpg");
		_pExitTexture = SDL_CreateTextureFromSurface(_pRen, _pExitSurface);

		_pSnakeSurface = IMG_Load("./src/image/snake.jpg");
		_pSnakeTexture = SDL_CreateTextureFromSurface(_pRen, _pSnakeSurface);

		_pStartSurface = IMG_Load("./src/image/start.png");
		_pStartTexture = SDL_CreateTextureFromSurface(_pRen, _pStartSurface);
	}

	~myRender() {
		SDL_DestroyRenderer(_pRen);
		TTF_CloseFont(_pFont);
		SDL_FreeSurface(_pExitSurface);
		SDL_DestroyTexture(_pExitTexture);
		SDL_FreeSurface(_pSnakeSurface);
		SDL_DestroyTexture(_pSnakeTexture);
		SDL_FreeSurface(_pStartSurface);
		SDL_DestroyTexture(_pSnakeTexture);
	}

	void paint(const snake& s, const food& f);
	void showInfo(const char* info);
	bool startUI();
	void exitUI();
};


#endif /*__RENDER_H__*/