#define GLM_ENABLE_EXPERIMENTAL
#include <iostream>
#include <fstream>
#include <algorithm>
#include "lifeball.h"
#include "main.h"
#include "circle.h"
using namespace std;

Lifeball::Lifeball(float y) {
    this->y = y;
    this->radius = 0.4;
    this->speedx = 0.05;
    this->speedy = 0.0;
    this->C = Circle(14.0, y, 0.4, this->speedx , 0.0, COLOR_TRUERED);
}

void Lifeball::draw(glm::mat4 VP) {
	this->C.draw(VP);
}

int Lifeball::tick(float speedx) {
    if( (this->y > 1.0 + this->radius)){
        this->speedy -= 0.01;
        this->y = max((float)(1.0 + this->radius), (float)(this->y + this->speedy) );
    }
    if( abs(this->y - (1.0 + this->radius) ) <= 0.01){
        this->speedy *= -1.0;
        this->y = this->y + this->speedy;
    }
    this->C.position.y = this->y;
    this->speedx = 0.05 + speedx;
    this->C.speedx = this->speedx;
    this->C.tick();
    if(this->C.position.x < -1.0)
        return 1;
    return 0;
}
