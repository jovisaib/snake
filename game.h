#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SDL.h>


#include "globals.h"
#include "snake.h"
#include "food.h"



class Game{
private:
    Game(){};
    static Game* instance;

    SDL_Renderer* renderer;
    SDL_Window* window;
    SDL_Event e;

    Snake* snake;
    Food* food;

    bool loop;

public:
    static Game* getInstance();
    ~Game();

    int init();
    int run();
    void render();
    void update();
    void event();
    void clean();
    SDL_Renderer* getRenderer(){return renderer;}
};


#endif // GAME_H_INCLUDED
