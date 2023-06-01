#include "headers/game.h"
#include "sources/game.cpp"
const int WIDTH = 800;
const int HEIGHT = 600;
Game *game = nullptr;

int main(int argc, const char* argv[]){
    game = new Game();
    game->init("Game cua nam", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, true);
    while(game->running()){
        game->eventHandle();
        game->update();
        game->render();
    };
    game->clean();
    return 0; 
};
