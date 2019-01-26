#define GLM_ENABLE_EXPERIMENTAL
#include <iostream>
#include <fstream>
#include "shield.h"
#include "main.h"
using namespace std;

Shield::Shield(float x, float y) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    this->speedy = this->speedx = 0;
    GLfloat vertex_buffer_data[] = {
        -0.2, -0.2, 0,
        0, -1.2, 0,
        0.2, -0.2, 0,
        0.2, 0.2, 0,
        1.2, 0, 0,
        0.2, -0.2, 0,
        0.2, 0.2, 0,
        0, 1.2, 0,
        -0.2, 0.2, 0,
        -0.2, 0.2, 0,
        -1.2, 0 , 0,
        -0.2, -0.2, 0,
    };

    this->object = create3DObject(GL_TRIANGLES, 12, vertex_buffer_data, COLOR_GREEN, GL_FILL);
}

void Shield::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Shield::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Shield::tick(float xcord, float ycord) {
    this->position.x = xcord ;
    this->position.y = ycord;
    this->rotation += 5;
    if(this->rotation >= 360)
        this->rotation -= 360;
}
