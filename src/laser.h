#include "main.h"

#ifndef LASER_H
#define LASER_H


class Laser {
public:
    Laser() {}
    Laser(float y);
    void draw(glm::mat4 VP);
    // void set_position(float x, float y);
    void tick();
private:
    VAO *object;
};

#endif // LASER_H
