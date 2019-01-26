#define GLM_ENABLE_EXPERIMENTAL
#include <iostream>
#include <fstream>
#include "viserion.h"
#include "main.h"
using namespace std;

Viserion::Viserion(float x, float y) {
    this->position = glm::vec3(x, y, 0);
    this->life = 3;
    GLfloat vertex_buffer_data1[] = {
      0.0f, 0.0f, 0.0f,         
      1.5, -1.5, 0.0,
      1, 0, 0,
      0, 0, 0,
      1, 0, 0,
      3, 2.25, 0,
      0, 0, 0,
      1, 0, 0,
      2, 3, 0,
      0, 0, 0,
      1, 0, 0,
      -1, 2, 0,
      -1, 2, 0,
      -2, 1.5, 0,
      -0.75, 1.5, 0,
    };

    GLfloat vertex_buffer_data2[] = {
      -1.3, 1.7, 0,
      -1.15, 1.7, 0,
      -1.05, 1.8, 0,
    };

    this->body = create3DObject(GL_TRIANGLES, 15, vertex_buffer_data1, COLOR_WHITE, GL_FILL);
    this->eye = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data2, COLOR_LIGHTBLUE, GL_FILL);
}

void Viserion::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (0.0 * M_PI / 180.0f), glm::vec3(0, 0, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->body);
    draw3DObject(this->eye);
}

void Viserion::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Viserion::tick(float speedx, float ycord) {
    if(this->position.x - speedx > 10.0)
        this->position.x -= speedx;
    if(ycord > this->position.y && this->position.y + 3.25 <= 8.0)
        this->position.y += 0.02;
    if(ycord < this->position.y && this->position.y - 1.75 >= 1.0)
        this->position.y -= 0.02;
}

int Viserion::check_col(Point a, Point b, Point c, Point d){
    int coll = 0;
    Point p, q;
    p.x = -2.0 + this->position.x, p.y = 1.5 + this->position.y;
    q.x = -1 + this->position.x, q.y = 2 + this->position.y;
    if(doIntersect(p, q, a, b))
        coll = 1;
    if(doIntersect(p, q, c, b))
        coll = 1;
    if(doIntersect(p, q, a, d))
        coll = 1;
    if(doIntersect(p, q, c, d))
        coll = 1;
    p.x = 0 + this->position.x, p.y = 0 + this->position.y;
    q.x = -1 + this->position.x, q.y = 2 + this->position.y;
    if(doIntersect(p, q, a, b))
        coll = 1;
    if(doIntersect(p, q, c, b))
        coll = 1;
    if(doIntersect(p, q, a, d))
        coll = 1;
    if(doIntersect(p, q, c, d))
        coll = 1;
    p.x = 0 + this->position.x, p.y = 0 + this->position.y;
    q.x = 2 + this->position.x, q.y = 3 + this->position.y;
    if(doIntersect(p, q, a, b))
        coll = 1;
    if(doIntersect(p, q, c, b))
        coll = 1;
    if(doIntersect(p, q, a, d))
        coll = 1;
    if(doIntersect(p, q, c, d))
        coll = 1;
    p.x = 0 + this->position.x, p.y = 0 + this->position.y;
    q.x = 3 + this->position.x, q.y = 2.25 + this->position.y;
    if(doIntersect(p, q, a, b))
        coll = 1;
    if(doIntersect(p, q, c, b))
        coll = 1;
    if(doIntersect(p, q, a, d))
        coll = 1;
    if(doIntersect(p, q, c, d))
        coll = 1;
    p.x = 0 + this->position.x, p.y = 0 + this->position.y;
    q.x = 1.5 + this->position.x, q.y = -1.5 + this->position.y;
    if(doIntersect(p, q, a, b))
        coll = 1;
    if(doIntersect(p, q, c, b))
        coll = 1;
    if(doIntersect(p, q, a, d))
        coll = 1;
    if(doIntersect(p, q, c, d))
        coll = 1;
    return coll;
}
