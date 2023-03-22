#include "Textures.h"

SDL_Texture* TexureManager::LoadTexture(const char* texture, SDL_Renderer* ren) {
    return IMG_LoadTexture(ren, texture);
}