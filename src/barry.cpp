#define GLM_ENABLE_EXPERIMENTAL
#include <iostream>
#include <fstream>
#include <algorithm>
#include "barry.h"
#include "main.h"
using namespace std;

Barry::Barry(float x, float y) {
    this->x = x, this->y = y;
    this->speedx = this->speedy = 0.0;
    this->length = 0.5, this->height = 1.0;
    R = Rectangle(x, y, 0.5, 1.0, 0.0, 0.0, 0.0, COLOR_BLUE);
}

void Barry::draw(glm::mat4 VP) {
    R.draw(VP);
}

void Barry::tick(float screen_length, float screen_height) {
    this->x -= this->speedx;
    if(this->y + this->height >= screen_height && this->speedy > 0)
        this->speedy = 0.0;
    if(this->y > 1.0 && this->y + this->speedy < 1.0){
        this->y = 1.0;
        this->speedy = 0.0;
    }
    this->y += this->speedy;
    if(this->y + this->height >= screen_height)
        this->speedy = 0.0;
    this->y = min(this->y, (float)(screen_height - this->height) );
    this->x = min(this->x, (float)(screen_length/2.0 - this->length) );
    this->R.position.x = this->x;
    this->R.position.y = this->y;
    this->R.speedx = this->speedx;
    this->R.speedy = this->speedy;   
    R.tick();
}
