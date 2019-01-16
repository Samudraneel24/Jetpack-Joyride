#include "main.h"

#ifndef FIRE_H
#define FIRE_H


class Fire {
public:
    Fire() {}
    Fire(float leftx, float lefty, float rightx, float righty, float speedx, float speedy);
    void draw(glm::mat4 VP);
    void tick(float speedx, float speedy);
    float leftx, lefty, rightx, righty, len, angle, speedx, speedy;
private:
    VAO *object;
};

#endif // FIRE_H
