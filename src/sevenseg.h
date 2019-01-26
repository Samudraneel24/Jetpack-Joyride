#include "main.h"
#include "rectangle.h"
#include <string>

using namespace std;

#ifndef SEVENSEG_H
#define SEVENSEG_H


class SevenSeg {
public:
    SevenSeg() {}
    SevenSeg(float x, float y);
    void draw(glm::mat4 VP);
    void tick(float speedx, char c);
    Rectangle R[7];
    string on;
    float x, y, speedx,  orgx, orgy;
    char c;
private:
    VAO *object;
};

#endif // SEVENSEG_H
