#include "main.h"

#ifndef SHIELD_H
#define SHIELD_H


class Shield {
public:
    Shield() {}
    Shield(float x, float y);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick(float xcord, float ycord);
    float speedx, speedy;
    float rotation;
private:
    VAO *object;
};

#endif // SHIELD_H
