#include "main.h"
#include "sevenseg.h"
#include "semicircle.h"

#ifndef LIFE_H
#define LIFE_H


class Life {
public:
    Life() {}
    Life(float x, float y);
    glm::vec3 position;
    void set_position(float x, float y);
    void draw(glm::mat4 VP);
    void tick(float screen_zoom);
    Semicircle Left, Right;
    float speedx, speedy, orgx, orgy;
private:
    VAO *object;
};

#endif // LIFE_H
