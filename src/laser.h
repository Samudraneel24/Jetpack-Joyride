#include "main.h"

#ifndef LASER_H
#define LASER_H


class Laser {
public:
    Laser() {}
    Laser(float y);
    void draw(glm::mat4 VP);
    void tick(int lasercounter, float sign);
    float left, right, y;
    int on;
private:
    VAO *object;
};

#endif // LASER_H
