#include "render.h"
#include <iostream>


void myRender::paint(const snake& s, const food& f) {
	_rect.h = _gridHeight;
	_rect.w = _gridWidth;


	SDL_SetRenderDrawColor(_pRen, _backgroundColor.r, _backgroundColor.g, _backgroundColor.b, _backgroundColor.a);
	SDL_RenderClear(_pRen);

	SDL_Surface* pSurface = IMG_Load("./src/image/body.jpg");
	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(_pRen, pSurface);

	std::vector<SDL_Point> tmpVector = s.getBody();
	for (auto item = tmpVector.begin(); item!=tmpVector.end(); ++item) {
		_rect.x = (*item).x * _gridWidth;
		_rect.y = (*item).y * _gridHeight;
		SDL_RenderCopy(_pRen, pTexture, nullptr, &_rect);
	}
	SDL_FreeSurface(pSurface);
	SDL_DestroyTexture(pTexture);

	switch (s.getDire())
	{
	case snake::direction::DOWN :
		pSurface = IMG_Load("./src/image/down.jpg");
		break;
	case snake::direction::UP :
		pSurface = IMG_Load("./src/image/up.jpg");
		break;
	case snake::direction::LEFT :
		pSurface = IMG_Load("./src/image/left.jpg");
		break;
	case snake::direction::RIGHT:
		pSurface = IMG_Load("./src/image/right.jpg");
		break;
	default:
		break;
	}
	pTexture = SDL_CreateTextureFromSurface(_pRen, pSurface);	
	_rect.x = static_cast<int>(s.getHeadX()) * _gridWidth;
	_rect.y = static_cast<int>(s.getHeadY()) * _gridHeight;
	//SDL_RenderFillRect(_pRen, &_rect);
	SDL_RenderCopy(_pRen, pTexture, nullptr, &_rect);
	SDL_FreeSurface(pSurface);
	SDL_DestroyTexture(pTexture);

	pSurface = IMG_Load("./src/image/food.jpg");
	pTexture = SDL_CreateTextureFromSurface(_pRen, pSurface);
	_rect.x = f.getX() * _gridWidth;
	_rect.y = f.getY() * _gridHeight;
	SDL_RenderCopy(_pRen, pTexture, nullptr, &_rect);
	SDL_FreeSurface(pSurface);
	SDL_DestroyTexture(pTexture);

	SDL_RenderPresent(_pRen);
}

void myRender::showInfo(const char* info) {
	SDL_Surface* pSurface = TTF_RenderText_Solid(_pFont, info, {0, 255, 0, 0});
	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(_pRen, pSurface);
	SDL_Rect rect{0, 0, 100, 25};
	SDL_RenderCopy(_pRen, pTexture, nullptr, &rect);
	SDL_RenderPresent(_pRen);

	SDL_FreeSurface(pSurface);
	SDL_DestroyTexture(pTexture);
}

bool myRender::startUI() {
	SDL_Surface* pSurface = IMG_Load("./src/image/snake.jpg");
	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(_pRen, pSurface);
	SDL_RenderCopy(_pRen, pTexture, nullptr, nullptr);
	SDL_FreeSurface(pSurface);
	SDL_DestroyTexture(pTexture);

	pSurface = IMG_Load("./src/image/start.png");
	pTexture = SDL_CreateTextureFromSurface(_pRen, pSurface);
	SDL_Rect rect{400, 0, 200, 200};
	SDL_RenderCopy(_pRen, pTexture, nullptr, &rect);
	SDL_RenderPresent(_pRen);

	SDL_Event event;
	bool running = true;
	bool result = false;
	while (running)
	{
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				running = false;
				break;
			
			case SDL_MOUSEBUTTONUP: {
				int x, y;
				SDL_GetMouseState(&x, &y);
				if ((x>420 && x<570) && (y>65 && y<135)) {
					result = true;
					running = false;
				}
			}
				break;
			
			default:
				break;
			}
		}
	}
	

	SDL_FreeSurface(pSurface);
	SDL_DestroyTexture(pTexture);

	return result;
}