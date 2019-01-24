#include "main.h"
#include "rectangle.h"

#ifndef BOOMERANG_H
#define BOOMERANG_H


class Boomerang {
public:
    Boomerang() {}
    Boomerang(float x, float y);
    void draw(glm::mat4 VP);
    int tick(float background_speedx);
    float x, y, speedx, speedy, angle;
    Rectangle Top, Centre1, Centre2, Bottom;
private:
    VAO *object;
};

#endif // BOOMERANG_H
