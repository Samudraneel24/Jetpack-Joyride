#define GLM_ENABLE_EXPERIMENTAL
#include <iostream>
#include <fstream>
#include "ellipse.h"
#include "main.h"
using namespace std;

Ellipse::Ellipse(float x, float y, float a, float b, float speedx, float speedy, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->speedx = speedx;
    this->speedy = speedy;
    const int n = 100;
    GLfloat vertex_buffer_data[9*n] ;
    float angle = ( 2.0*M_PI / float(n));
    float theta = 0.0;
    for(int i=0;i<n;i++){
        vertex_buffer_data[9*i] = 0.0f;
        vertex_buffer_data[9*i + 1] = 0.0f;
        vertex_buffer_data[9*i + 2] = 0.0f;
        vertex_buffer_data[9*i + 3] = a*cos(theta);
        vertex_buffer_data[9*i + 4] = b*sin(theta);
        vertex_buffer_data[9*i + 5] = 0.0f;
        theta += angle;
        if(i == n-1){
            vertex_buffer_data[9*i + 6] = a;
            vertex_buffer_data[9*i + 7] = 0.0f;
            vertex_buffer_data[9*i + 8] = 0.0f;
        }
        else{
            vertex_buffer_data[9*i + 6] = a*cos(theta);
            vertex_buffer_data[9*i + 7] = b*sin(theta);
            vertex_buffer_data[9*i + 8] = 0.0f;
        }
        
    }
    this->object = create3DObject(GL_TRIANGLES, 3*n, vertex_buffer_data, color, GL_FILL);
}

void Ellipse::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (0.0 * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Ellipse::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Ellipse::tick() {
    this->position.x += this->speedx;
    this->position.y += this->speedy;
}

