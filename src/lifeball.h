#include "main.h"
#include "circle.h"

#ifndef Lifeball_H
#define Lifeball_H


class Lifeball {
public:
    Lifeball() {}
    Lifeball(float y);
    void draw(glm::mat4 VP);
    int tick(float speedx);
    float x, y, radius, speedx, speedy;
    Circle C;
private:
    VAO *object;
};

#endif // Lifeball_H
