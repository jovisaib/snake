#ifndef MATH_H_INCLUDED
#define MATH_H_INCLUDED

class Math{
private:
    //Math(){};


public:
    float x, y;

    Math(float x, float y);

    void add(Math* vec);
    void setVect(float x, float y);

};


#endif // MATH_H_INCLUDED
