#include "main.h"
#include "semicircle.h"

#ifndef ARC_H
#define ARC_H

class Arc {
public:
    Arc() {}
    Arc(float x, float y);
    void draw(glm::mat4 VP);
    void tick(float speedx);
    float Get_y(float x);
    float x, y, speedx, speedy, radius;
    Semicircle Large, Small;
private:
    VAO *object;
};

#endif // ARC_H
