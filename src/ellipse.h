#include "main.h"

#ifndef ELLIPSE_H
#define ELLIPSE_H


class Ellipse {
public:
    Ellipse() {}
    Ellipse(float x, float y, float a, float b, float speedx, float speedy, color_t color);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    float a, b;
    double speedx, speedy;
private:
    VAO *object;
};

#endif // ELLIPSE_H
