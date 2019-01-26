#include "main.h"
#include "Lineintersection.h"

#ifndef VISERION_H
#define VISERION_H


class Viserion {
public:
    Viserion() {}
    Viserion(float x, float y);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick(float speedx, float ycord);
    int check_col(Point a, Point b, Point c, Point d);
    float speedx, speedy;
    int life;
private:
    VAO *body;
    VAO *eye;
};

#endif // VISERION_H
