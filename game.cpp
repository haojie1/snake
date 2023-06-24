#include "game.h"
#include <string>

void game::start() {
	bool run = true, opt, timeOut = false;
	char infoString[20];
	size_t frameRatio = 60, count = 0;
	uint32_t frameStart, frameEnd;
	sprintf(infoString, "score: %d frameRatio: %u", _score, frameRatio);
	opt = _pRend->startUI();
	if (opt == false) {
		return;
	}
	frameStart = SDL_GetTicks();
	while (run) {
		run = _pController->moveSnake(_pSnake);
		_pSnake->update(_pFood);
		_pRend->paint(*_pSnake, *_pFood);
		if (_pSnake->getCatchFood() || timeOut) {
			if (timeOut) {
				timeOut = false;
			} else {
				++_score;
			}
			sprintf(infoString, "score: %d frameRatio: %u", _score, frameRatio);
		}
		_pRend->showInfo(infoString);
		frameEnd = SDL_GetTicks();
		++count;
		if (frameEnd-frameStart >= 1000) {
			frameRatio = count;
			frameStart = frameEnd;
			count = 0;
			timeOut = true;
		}
		if (_pSnake->alive() == false) {
			#ifdef CANRESTART
			bool opt = quitOrRestart();
			if (opt) {
				delete _pSnake;
				int posX, posY;
				#ifdef __linux
					std::random_device _rd;
					std::mt19937 gen(_rd());
					std::uniform_int_distribution<int> distForRow(0, _gridNumberRow-1);
					std::uniform_int_distribution<int> distForCol(0, _gridNumberCol-1);
					posX = distForRow(gen);
					posY = distForCol(gen);
				#endif
				#ifdef WINVER
					srand(time(nullptr));
					posX = static_cast<int>(fmod(rand(), _gridNumberRow));
					posY = static_cast<int>(fmod(rand(), _gridNumberCol));
				#endif
				_pSnake = new snake(_gridNumberRow, _gridNumberCol, posX, posY);
				_score = 0;
				sprintf(infoString, "score: %d", _score);
			} else {
				run = false;
			}
			#else
				_pRend->exitUI();
				run = false;
			#endif
		}
		SDL_Delay(15);
	}
}

bool game::quitOrRestart() {
	const SDL_MessageBoxButtonData buttons[] = {
		{ SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 0, "quit" },
		{ SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 1, "restart" },
	};
	const SDL_MessageBoxColorScheme colorScheme = {
		{ /* .colors (.r, .g, .b) */
			/* [SDL_MESSAGEBOX_COLOR_BACKGROUND] */
			{ 255,   0,   0 },
			/* [SDL_MESSAGEBOX_COLOR_TEXT] */
			{   0, 255,   0 },
			/* [SDL_MESSAGEBOX_COLOR_BUTTON_BORDER] */
			{ 255, 255,   0 },
			/* [SDL_MESSAGEBOX_COLOR_BUTTON_BACKGROUND] */
			{   0,   0, 255 },
			/* [SDL_MESSAGEBOX_COLOR_BUTTON_SELECTED] */
			{ 255,   0, 255 }
		}
	};
	const SDL_MessageBoxData messageboxdata = {
		SDL_MESSAGEBOX_INFORMATION, /* .flags */
		_pWindow, /* .window */
		"", /* .title */
		"Want to quit or restart?", /* .message */
		SDL_arraysize(buttons), /* .numbuttons */
		buttons, /* .buttons */
		&colorScheme /* .colorScheme */
	};

	int buttonid;

	SDL_ShowMessageBox(&messageboxdata, &buttonid);

	if (buttonid == 0) {
		return false;
	} else {
		return true;
	}
}