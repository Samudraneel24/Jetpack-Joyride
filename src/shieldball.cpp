#define GLM_ENABLE_EXPERIMENTAL
#include <iostream>
#include <fstream>
#include <algorithm>
#include "shieldball.h"
#include "main.h"
#include "circle.h"
using namespace std;

Shieldball::Shieldball(float y) {
    this->y = y;
    this->radiusA = 0.5;
    this->radiusB = 0.4;
    this->radiusC = 0.3;
    this->speedx = 0.05;
    this->speedy = 0.0;
    this->A = Circle(14.0, y, this->radiusA, this->speedx , 0.0, COLOR_BLACK);
    this->B = Circle(14.0, y, this->radiusB, this->speedx , 0.0, COLOR_GREEN);
    this->C = Circle(14.0, y, this->radiusC, this->speedx , 0.0, COLOR_BLACK);
}

void Shieldball::draw(glm::mat4 VP) {
	this->A.draw(VP), this->B.draw(VP), this->C.draw(VP);
}

int Shieldball::tick(float speedx) {
    if( (this->y > 1.0 + this->radiusA)){
        this->speedy -= 0.01;
        this->y = max((float)(1.0 + this->radiusA), (float)(this->y + this->speedy) );
    }
    if( abs(this->y - (1.0 + this->radiusA) ) <= 0.01){
        this->speedy *= -1.0;
        this->y = this->y + this->speedy;
    }
    this->A.position.y = this->y;
    this->B.position.y = this->y;
    this->C.position.y = this->y;
    this->speedx = 0.05 + speedx;
    this->A.speedx = this->speedx;
    this->B.speedx = this->speedx;
    this->C.speedx = this->speedx;
    this->A.tick(), this->B.tick(), this->C.tick();
    if(this->C.position.x < -1.0)
        return 1;
    return 0;
}
