/*
Black Cat Demo
Author: Josh Bacon
Date of Last Edit: 03/14/2023
*/

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "Game.h"

Game *game = nullptr;

int main(int argc, char** argv) {
    
    // Frame Math
    const int FPS = 60;
    const int frame_delay = 1000 / FPS;
    Uint32 frame_start;
    int frame_time;

    game = new Game();
    game->init("BlackCatEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1600, 900, false);

    while (game->running()) {
        frame_start = SDL_GetTicks();
        game->handleEvents();
        game->update();
        game->render();
        frame_time = SDL_GetTicks() - frame_start;
    
        if (frame_delay > frame_time) {
            SDL_Delay(frame_delay - frame_time);
        }
    }
    game->clean();
    
    return 0;
}