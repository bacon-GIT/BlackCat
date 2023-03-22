#include <iostream>
#include "Game.h"
#include "Log.h"


Log::Logger gameLogger("BC.log", true, 5);

Game::Game() {
}
Game::~Game() {
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
    // Load engine
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
			gameLogger.ERROR("Video not initialized");
    }

    win = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);
    if (win) {
        gameLogger.INFO("Window Initalized");
    }
	renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    if (renderer) {
        gameLogger.INFO("Renderer Initalized");
    }
}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_KEYDOWN:
                switch( event.key.keysym.sym ){
                    case SDLK_LEFT:
                        destR.x -= player.move_speed;
                        std::cout << "Here" << std::endl;
                        break;
                    case SDLK_RIGHT:
                        destR.x += player.move_speed;
                        break;
                    case SDLK_UP:
                        destR.y -= player.move_speed;
                        break;
                    case SDLK_DOWN:
                        destR.y += player.move_speed;
                        break;
                    default:
                        break;
                }
        default:
            break;
    }
}

void Game::update() {
    destR.w = 125;
    destR.h = 230;

}

void Game::render() {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, img, NULL, &destR);
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(win);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    gameLogger.INFO("Cleanup Complete");
}

