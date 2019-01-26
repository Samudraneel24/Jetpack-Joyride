#define GLM_ENABLE_EXPERIMENTAL
#include <iostream>
#include <fstream>
#include "lives.h"
#include "main.h"
using namespace std;

Life::Life(float x, float y) {
    this->position = glm::vec3(x, y, 0);
    GLfloat vertex_buffer_data[] = {
      0, 0, 0,         
      0.8, 0, 0,
      0.4, -0.6, 0,
    };
    this->object = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data, COLOR_TRUERED, GL_FILL);
    this->Left = Semicircle(x + 0.2, y, 0.2, 0, 0, 0, COLOR_TRUERED );
    this->Right = Semicircle(x + 0.6, y, 0.2, 0, 0, 0, COLOR_TRUERED );
}

void Life::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (0.0 * M_PI / 180.0f), glm::vec3(0, 0, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    this->Left.draw(VP), this->Right.draw(VP);
}

void Life::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Life::tick() {
    this->Left.tick(), this->Right.tick();
}

