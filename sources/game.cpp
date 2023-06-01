#include "../headers/game.h"

Game::Game()
{
    isRunning = false;
    window = nullptr;
    renderer = nullptr;
};
Game::~Game() {};

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flag = 0;
    if(fullscreen) flag = SDL_WINDOW_FULLSCREEN;
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Subsystem Initialise!" << std::endl;
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flag);
        if(window) {
            std::cout << "Create window" << std::endl;
        };
        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Create renderer" << std::endl;
        };
        isRunning = true;
    } else {
        isRunning = false;
    };
};
void Game::eventHandle() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            {
                isRunning = false;
                break;
            };
        default:
            {
                break;   
            };
    }
};
void Game::update() {};
void Game::render() {
    SDL_RenderClear(renderer); // del old render
    // 
    SDL_RenderPresent(renderer);
};
void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Clean the game!" << std::endl;
};
