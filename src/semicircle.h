#include "main.h"

#ifndef SEMICIRCLE_H
#define SEMICIRCLE_H


class Semicircle {
public:
    Semicircle() {}
    Semicircle(float x, float y, float radius, float speedx, float speedy, float rotation, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    float radius;
    double speedx, speedy;
private:
    VAO *object;
};

#endif // SEMICIRCLE_H
