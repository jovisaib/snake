#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

#include <SDL.h>
#include <vector>

#include "globals.h"
#include "math.h"
#include "food.h"


class Snake{

private:
    Snake(){};

    std::vector<Snake*> tail;

    Math* pos;
    Math* vel;
    Food* food;
    int snakeSize;
    long lastTime;

    char getDir();
    bool collide();
    void reestore();
    void renderTail();
    int getX(){return pos->x;}
    int getY(){return pos->y;}

public:

    Snake(Food* food);
    Snake(int x, int y);

    void movement(SDL_Event e);
    void render();
    void update();
};


#endif // SNAKE_H_INCLUDED
