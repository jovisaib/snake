#include "math.h"


Math::Math(float x, float y){
    this->x = x;
    this->y = y;
}


void Math::add(Math* vec){
    this->x += vec->x;
    this->y += vec->y;
}


void Math::setVect(float x, float y){
    this->x = x;
    this->y = y;
}
