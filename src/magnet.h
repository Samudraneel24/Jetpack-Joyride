#include "main.h"

#ifndef MAGNET_H
#define MAGNET_H


class Magnet {
public:
    Magnet() {}
    Magnet(float x, float y);
    void draw(glm::mat4 VP);
    void tick(float speedx, float speedy);
    float x, y, speedx, speedy;
private:
    VAO *object;
};

#endif // MAGNET_H
