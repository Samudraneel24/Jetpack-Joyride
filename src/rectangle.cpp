#define GLM_ENABLE_EXPERIMENTAL
#include <iostream>
#include <fstream>
#include "rectangle.h"
#include "main.h"
using namespace std;

Rectangle::Rectangle(float x, float y, float len, float width, float angle, float speedx, float speedy, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = angle;
    this->len = len;
    this->width = width;
    this->speedy = speedy;
    this->speedx = speedx;
    GLfloat vertex_buffer_data[] = {
      0.0f, 0.0f, 0.0f,         
      len, 0.0f, 0.0f,          
      0.0f, width, 0.0f,         
      len, 0.0f, 0.0f,          
      0.0f, width, 0.0f,
      len, width, 0.0f,
    };

    this->object = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, color, GL_FILL);
}

void Rectangle::draw(glm::mat4 VP) {
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

void Rectangle::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Rectangle::tick() {
    this->position.x -= this->speedx;
    if(this->position.y  + this->width >= 8.0 && this->speedy > 0)
        this->speedy = 0.0;
    if(this->position.y > 1.0 && this->position.y + this->speedy < 1.0){
        this->position.y = 1.0;
        this->speedy = 0.0;
    }
    this->position.y += this->speedy;
    if(this->position.y + this->width >= 8.0)
        this->speedy = 0.0;
}
