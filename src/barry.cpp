#define GLM_ENABLE_EXPERIMENTAL
#include <iostream>
#include <fstream>
#include <algorithm>
#include "barry.h"
#include "main.h"
using namespace std;

Barry::Barry(float x, float y) {
    this->Baseheight = y;
    this->x = x, this->y = y;
    this->speedx = this->speedy = 0.0;
    this->length = 1.5, this->height = 1.1;
    this->position = glm::vec3(x, y, 0);
    Head = Ellipse(x, y + 0.25, 0.4, 0.5, 0, 0, COLOR_BLUE);
    Body = Ellipse(x, y, 0.75, 0.35, 0.0, 0.0, COLOR_BLACK);
    Firetop = Ellipse(x, y - 0.5, 0.2, 0.15, 0.0, 0.0, COLOR_FIRE);
    GLfloat vertex_buffer_data[] = {
      -0.2, -0.5, 0,
      0.2, -0.5, 0,
      0, -0.9, 0,
    };
    this->object = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data, COLOR_FIRE, GL_FILL);
}

void Barry::draw(glm::mat4 VP, int fire_on) {
    Head.draw(VP), Body.draw(VP);
    if(fire_on == 1){
        Firetop.draw(VP);
        Matrices.model = glm::mat4(1.0f);
        glm::mat4 translate = glm::translate (this->position);    // glTranslatef
        glm::mat4 rotate    = glm::rotate((float) (0.0 * M_PI / 180.0f), glm::vec3(0, 0, 1));
        // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
        // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
        Matrices.model *= (translate * rotate);
        glm::mat4 MVP = VP * Matrices.model;
        glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
        draw3DObject(this->object);
    }
}

void Barry::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Barry::tick(float screen_length, float screen_height) {
    this->y += this->speedy;
    this->x += this->speedx;
    if(this->y + 0.75 >= screen_height ){
        this->speedy = 0;
        this->y = screen_height - 0.75;
    }
    if(this->y - 0.35 < 1.0){
        this->y = 1.35;
        this->speedy = 0;
    }
    if(this->x - 0.75 < 0){
        this->x = 0.75;
    }
    if(this->x + 0.75 > screen_length/2.0)
        this->x = screen_length/2.0 - 0.75;
    this->Body.position.x = this->x;
    this->Body.position.y = this->y;
    this->Head.position.x = this->x;
    this->Head.position.y = this->y + 0.25;
    this->Firetop.position.x = this->x;
    this->Firetop.position.y = this->y - 0.5;
    this->position.x = this->x;
    this->position.y = this->y;
    this->Body.speedx = this->speedx;
    this->Body.speedy = this->speedy;  
    this->Head.speedx = this->speedx;
    this->Head.speedy = this->speedy;
    this->Head.tick(), this->Body.tick();   
}
