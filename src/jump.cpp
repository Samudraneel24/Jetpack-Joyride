#define GLM_ENABLE_EXPERIMENTAL
#include <iostream>
#include <fstream>
#include <algorithm>
#include "jump.h"
#include "main.h"
#include "circle.h"
using namespace std;

Jump::Jump(float y) {
    this->y = y;
    this->radius = 0.4;
    this->speedx = 0.05;
    this->speedy = 0.0;
    this->C = Circle(14.0, y, 0.4, this->speedx , 0.0, COLOR_BLACK);
    this->Up = Rectangle(14.0 + 0.25, y + 0.25, 0.45, 0.1, 135, this->speedx, 0, COLOR_GREEN);
    this->Down = Rectangle(14.0 + 0.25, y + 0.15 ,0.5, 0.1, -135, this->speedx, 0, COLOR_GREEN);
}

void Jump::draw(glm::mat4 VP) {
	this->C.draw(VP);
    this->Up.draw(VP), this->Down.draw(VP);
}

int Jump::tick(float speedx) {
    if( (this->y > 1.0 + this->radius)){
        this->speedy -= 0.01;
        this->y = max((float)(1.0 + this->radius), (float)(this->y + this->speedy) );
    }
    if( abs(this->y - (1.0 + this->radius) ) <= 0.01){
        this->speedy *= -1.0;
        this->y = this->y + this->speedy;
    }
    this->C.position.y = this->y;
    this->Up.position.y = this->y;
    this->Down.position.y = this->y;
    this->speedx = 0.05 + speedx;
    this->C.speedx = this->speedx;
    this->Up.speedx = this->speedx;
    this->Down.speedx = this->speedx;
    this->C.tick();
    this->Up.tick(), this->Down.tick();
    if(this->C.position.x < -1.0)
        return 1;
    return 0;
}
