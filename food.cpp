#include "food.h"
#include "game.h"

Food::Food(){
    foodSize = 8;
    pos = new Math(0.0f, 0.0f);
    catched();
}


void Food::render(){
    SDL_Rect fillRect = {(int)pos->x, (int)pos->y, foodSize, foodSize};
    SDL_SetRenderDrawColor(Game::getInstance()->getRenderer(), 200, 176, 200, 255);
    SDL_RenderFillRect(Game::getInstance()->getRenderer(), &fillRect);
}


void Food::catched(){
    // rand()%(max-min + 1) + min;
    //srand(time(NULL));
    int randomX = (rand()%(((SCR_WIDTH/foodSize)-1)-0 + 1) + 0)*foodSize;
    int randomY = (rand()%(((SCR_HEIGHT/foodSize)-1)-0 + 1) + 0)*foodSize;
    pos->x = randomX;
    pos->y = randomY;
}
