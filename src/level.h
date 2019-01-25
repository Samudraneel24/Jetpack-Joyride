#include "main.h"
#include "sevenseg.h"

#ifndef LEVEL_H
#define LEVEL_H


class Level {
public:
    Level() {}
    Level(float x, float y);
    void draw(glm::mat4 VP);
    void tick(float speedx, int Level);
    SevenSeg Character[9];
    float x, y, speedx;
private:
    VAO *object;
};

#endif // LEVEL_H
