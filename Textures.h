#pragma once
#ifndef Game_h
#define Game_h
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Game.h"
#endif


class TexureManager {
    public:
        static SDL_Texture* LoadTexture(const char* file, SDL_Renderer* ren);
}