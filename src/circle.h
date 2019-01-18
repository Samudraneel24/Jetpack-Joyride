#include "main.h"

#ifndef CIRCLE_H
#define CIRCLE_H


class Circle {
public:
    Circle() {}
    Circle(float x, float y, float radius, float speedx, float speedy, color_t color);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    float radius, speedx, speedy;
private:
    VAO *object;
};

#endif // CIRCLE_H
