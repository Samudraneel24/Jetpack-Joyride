#include "main.h"
#include "circle.h"
#include "rectangle.h"

#ifndef SHIELDBALL_H
#define SHIELDBALL_H

class Shieldball {
public:
    Shieldball() {}
    Shieldball(float y);
    void draw(glm::mat4 VP);
    int tick(float speedx);
    float x, y, radiusA, radiusB, radiusC, speedx, speedy;
    Circle A, B, C;
private:
    VAO *object;
};

#endif // SHIELDBALL_H
