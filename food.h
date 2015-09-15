#ifndef FOOD_H_INCLUDED
#define FOOD_H_INCLUDED

#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <SDL.h>

#include "math.h"
#include "globals.h"
#include <vector>


class Food{

private:
    Math* pos;
    int foodSize;

public:
    Food();
    void render();
    void catched();
    int getX(){return pos->x;}
    int getY(){return pos->y;}

};


#endif // FOOD_H_INCLUDED
