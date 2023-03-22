#ifndef Game_h
#define Game_h
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
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

    private:
        bool isRunning;
        SDL_Texture *img = NULL;
        SDL_Window *win = NULL;
        SDL_Renderer *renderer = NULL;
        int move_speed = 100;
};