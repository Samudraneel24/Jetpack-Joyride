#include "main.h"
#include "circle.h"

#ifndef JUMP_H
#define JUMP_H


class Jump {
public:
    Jump() {}
    Jump(float y);
    void draw(glm::mat4 VP);
    int tick(float speedx);
    float x, y, radius, speedx, speedy;
    Circle C;
private:
    VAO *object;
};

#endif // JUMP_H
