#define GLM_ENABLE_EXPERIMENTAL
#include <iostream>
#include <fstream>
#include "laser.h"
#include "main.h"
using namespace std;

Laser::Laser(float y) {
    float left = 1.0, right = 12.0;
    
}

void Laser::draw(glm::mat4 VP) {
//     Matrices.model = glm::mat4(1.0f);
//     glm::mat4 translate = glm::translate (this->position);    // glTranslatef
//     glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
//     // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
//     // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
//     Matrices.model *= (translate * rotate);
//     glm::mat4 MVP = VP * Matrices.model;
//     glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
//     draw3DObject(this->object);
}

// void Laser::set_position(float x, float y) {
//     this->position = glm::vec3(x, y, 0);
// }

void Laser::tick() {
    // this->position.x -= speedx;
    // if(this->position.y+speedy >= 1.0 && this->position.y+speedy <= 7.2){
    //     this->position.y += speedy;
    // }
    // if(this->position.y > 1.0 && this->position.y + speedy < 1.0){
    //     this->position.y = 1.0;
    //     speedy = 0.0;
    // }
}
