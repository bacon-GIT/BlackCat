#pragma once
#ifndef Game_h
#define Game_h
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Player.h"
#endif


class Game {
    public: 
        Game();
        ~Game();
        
        void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
        void handleEvents();
        void update();
        void render();
        void clean();
        bool running() { return isRunning; };

        Player player;
        SDL_Rect srcR, destR;

    private:
        bool isRunning;

        // Engine Variables
        SDL_Texture *img = NULL;
        SDL_Window *win = NULL;
        SDL_Renderer *renderer = NULL;
};
