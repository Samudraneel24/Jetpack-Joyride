#include "main.h"

#ifndef RECTANGLE_H
#define RECTANGLE_H


class Rectangle {
public:
    Rectangle() {}
    Rectangle(float x, float y, float len, float width, float angle, float speedx, float speedy, color_t color);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    double speedx, speedy;
    float rotation, width, len;
private:
    VAO *object;
};

#endif // RECTANGLE_H
