#include "main.h"

#ifndef SQUARE_H
#define SQUARE_H


class Square {
public:
    Square() {}
    Square(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    double speedx, speedy;
private:
    VAO *object;
};

#endif // SQUARE_H
