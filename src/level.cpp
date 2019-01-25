#define GLM_ENABLE_EXPERIMENTAL
#include <iostream>
#include <fstream>
#include <algorithm>
#include "level.h"
#include "main.h"
#include "sevenseg.h"
using namespace std;

Level::Level(float x, float y) {
    this->x = x;
    this->y = y;
    this->Character[0] = SevenSeg(this->x, this->y);
    this->Character[1] = SevenSeg(this->x + 0.3, this->y);
    this->Character[2] = SevenSeg(this->x + 0.6, this->y);
    this->Character[3] = SevenSeg(this->x + 0.9, this->y);
    this->Character[4] = SevenSeg(this->x + 1.2, this->y);
    this->Character[5] = SevenSeg(this->x + 1.5, this->y);
    this->Character[6] = SevenSeg(this->x + 1.8, this->y);
    this->Character[7] = SevenSeg(this->x + 2.1, this->y);
    this->Character[8] = SevenSeg(this->x + 2.4, this->y);
}

void Level::draw(glm::mat4 VP) {
    for(int i=0; i < 9; i++)
        this->Character[i].draw(VP);
}

void Level::tick(float speedx, int Level) {
    int dig;
    char c[6];
    for(int i=0; i<3; i++){
        dig = Level%10;
        c[i] = dig + '0';
        Level/=10;
    }
    this->speedx = speedx;
    this->Character[0].tick(speedx, 'l');
    this->Character[1].tick(speedx, 'e'); 
    this->Character[2].tick(speedx, 'v'); 
    this->Character[3].tick(speedx, 'e'); 
    this->Character[4].tick(speedx, 'l'); 
    this->Character[5].tick(speedx, '-'); 
    this->Character[6].tick(speedx, c[2]); 
    this->Character[7].tick(speedx, c[1]); 
    this->Character[8].tick(speedx, c[0]); 
}
