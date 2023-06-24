#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "snake.h"
#include "render.h"
#include "game.h"

//int WinMain(int argc, char** argv[])
#ifdef __linux
int main(int argc, char* argv[])
#endif
#ifdef WINVER
int WinMain(int argc, char* argv[])
#endif
{
    int res;
    res = SDL_Init(SDL_INIT_EVERYTHING);

    if (res) {
        cout << "Error in Init!!!" << endl;
    } else {
        cout << "Init Success!!!" << endl;
    }

   game* pGame = new game(700, 640, 32, 32);
   pGame->start();

   SDL_Quit();

    return EXIT_SUCCESS;
}
