#include "main.h"
#include "rectangle.h"

#ifndef SEVENSEG_H
#define SEVENSEG_H


class SevenSeg {
public:
    SevenSeg() {}
    SevenSeg(float x, float y);
    void draw(glm::mat4 VP);
    void tick(float speedx, char c);
    Rectangle R[7];
    int on[7];
    float x, y, speedx;
    char c;
private:
    VAO *object;
};

#endif // SEVENSEG_H
