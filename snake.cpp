#include "snake.h"
#include "game.h"
#include "iostream"


Snake::Snake(Food* food){
    pos = new Math(0.0f, 0.0f);
    vel = new Math(8.0f, 0.0f);
    snakeSize = 8;
    this->food = food;

    reestore();
}


Snake::Snake(int x, int y){
    pos = new Math(x, y);
    snakeSize = 8;
}


void Snake::render(){
    renderTail();
    for(unsigned int i=0; i<tail.size(); i++)
        tail[i]->renderTail();
}

void Snake::renderTail(){
    SDL_Rect fillRect = {(int)pos->x, (int)pos->y, snakeSize, snakeSize};
    SDL_SetRenderDrawColor(Game::getInstance()->getRenderer(), 111, 222, 255, 255);
    SDL_RenderFillRect(Game::getInstance()->getRenderer(), &fillRect);
}

void Snake::update(){

    if (SDL_GetTicks() - lastTime > 100) {
        if(tail.size()==1){
            tail[0]->pos->x = pos->x;
            tail[0]->pos->y = pos->y;
        }else{

            for(unsigned int i=tail.size()-1; i>0; i--){
                tail[i]->pos->x = tail[i-1]->getX();
                tail[i]->pos->y = tail[i-1]->getY();

                if(i==1){
                    tail[0]->pos->x = pos->x;
                    tail[0]->pos->y = pos->y;
                }
            }
        }

        lastTime = SDL_GetTicks();
        pos->add(vel);
    }

    if((pos->x==food->getX()) && (pos->y==food->getY())){
        food->catched();
        tail.push_back(new Snake(tail[0]->getX(), tail[0]->getY()));
    }

    if(collide()){
        reestore();
    }
}

void Snake::movement(SDL_Event e){
    if(e.key.keysym.scancode==SDL_SCANCODE_UP && getDir()!='d'){
        vel->setVect(0, -snakeSize);
    }
    if(e.key.keysym.scancode==SDL_SCANCODE_LEFT && getDir()!='r'){
        vel->setVect(-snakeSize, 0);
    }
    if(e.key.keysym.scancode==SDL_SCANCODE_DOWN && getDir()!='u'){
        vel->setVect(0,snakeSize);
    }
    if(e.key.keysym.scancode==SDL_SCANCODE_RIGHT && getDir()!='l'){
        vel->setVect(snakeSize, 0);
    }
}


bool Snake::collide(){
    //screen limits
    if(pos->x<0 || pos->x>(SCR_WIDTH-snakeSize))
      return true;
    if(pos->y<0 || pos->y>(SCR_HEIGHT-snakeSize))
      return true;

    //tail collision
    for(unsigned int i=0; i<tail.size(); i++)
        if((tail[i]->getX() == pos->x) && (tail[i]->getY() == pos->y))
            return true;
    return false;
}


char Snake::getDir(){
    char dir=' ';
    if(vel->x == -snakeSize) dir='l';
    if(vel->x == snakeSize) dir='r';
    if(vel->y == -snakeSize) dir='u';
    if(vel->y == snakeSize) dir='d';
    return dir;
}

void Snake::reestore(){
    tail.clear();
    pos->setVect(0, 0);
    vel->setVect(0, snakeSize);
    lastTime = SDL_GetTicks();
    for(unsigned int i=0; i<1; i++)
        tail.push_back(new Snake(pos->x-snakeSize, pos->y-snakeSize));
}
