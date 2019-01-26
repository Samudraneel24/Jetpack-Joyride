#include "main.h"
#include "ellipse.h"

#ifndef BARRY_H
#define BARRY_H


class Barry {
public:
    Barry() {}
    Barry(float x, float y);
    glm::vec3 position;
    void set_position(float x, float y);
    void draw(glm::mat4 VP, int fire_on);
    void tick(float screen_length, float screen_height);
    float x, y, speedx, speedy, length, height, Baseheight;
    Ellipse Body, Head , Firetop;
private:
    VAO *object;
};

#endif // BARRY_H
