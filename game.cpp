#include "game.h"

Game* Game::instance = NULL;


Game* Game::getInstance(){
    if (!instance) {
        instance = new Game();
    }
    return instance;
}


int Game::init(){
    loop = false;

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
        return -1;

    window = SDL_CreateWindow("Simple Snake",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        SCR_WIDTH, SCR_HEIGHT,
        SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == NULL || window == NULL)
        return -1;

    food = new Food();
    snake = new Snake(food);

    return 0;
}


void Game::render(){
    SDL_SetRenderDrawColor(renderer, 44, 143, 158, 255);
    SDL_RenderClear(renderer);

    snake->render();
    food->render();

    SDL_RenderPresent(renderer);
}


void Game::update(){
    snake->update();

}


void Game::clean(){
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = NULL;
	renderer = NULL;
	SDL_Quit();
}


void Game::event(){
    while(SDL_PollEvent(&e) != 0){
        if(e.type == SDL_QUIT)
            loop = true;

        if (e.type == SDL_KEYDOWN){
            if(e.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                loop = true;

            snake->movement(e);
        }
    }
}


int Game::run(){
    if(init()<0)
        return -1;

    while(!loop){
        event();
        update();
        render();
    }
    clean();

    return 0;
}
