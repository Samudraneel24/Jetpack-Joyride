#include "main.h"
#include "rectangle.h"

#ifndef BARRY_H
#define BARRY_H


class Barry {
public:
    Barry() {}
    Barry(float x, float y);
    void draw(glm::mat4 VP);
    void tick(float screen_length, float screen_height);
    float x, y, speedx, speedy, length, height;
    Rectangle R;
private:
    VAO *object;
};

#endif // BARRY_H
