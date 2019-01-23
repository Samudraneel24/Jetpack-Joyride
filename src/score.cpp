#define GLM_ENABLE_EXPERIMENTAL
#include <iostream>
#include <fstream>
#include <algorithm>
#include "score.h"
#include "main.h"
#include "sevenseg.h"
using namespace std;

Score::Score(float x, float y) {
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
    this->Character[9] = SevenSeg(this->x + 2.7, this->y);
    this->Character[10] = SevenSeg(this->x + 3.0, this->y);
    this->Character[11] = SevenSeg(this->x + 3.3, this->y);
}

void Score::draw(glm::mat4 VP) {
    for(int i=0; i < 12; i++)
        this->Character[i].draw(VP);
}

void Score::tick(float speedx, int score) {
    int dig;
    char c[6];
    for(int i=0; i<6; i++){
        dig = score%10;
        c[i] = dig + '0';
        score/=10;
    }
    this->speedx = speedx;
    this->Character[0].tick(speedx, 's');
    this->Character[1].tick(speedx, 'c'); 
    this->Character[2].tick(speedx, 'o'); 
    this->Character[3].tick(speedx, 'r'); 
    this->Character[4].tick(speedx, 'e'); 
    this->Character[5].tick(speedx, '-'); 
    this->Character[6].tick(speedx, c[5]); 
    this->Character[7].tick(speedx, c[4]); 
    this->Character[8].tick(speedx, c[3]); 
    this->Character[9].tick(speedx, c[2]); 
    this->Character[10].tick(speedx, c[1]); 
    this->Character[11].tick(speedx, c[0]); 
    // this->Character[0] = SevenSeg(this->x, this->y, 's');
    // this->Character[1] = SevenSeg(this->x + 0.3, this->y, 'c');
    // this->Character[2] = SevenSeg(this->x + 0.6, this->y, 'o');
    // this->Character[3] = SevenSeg(this->x + 0.9, this->y, 'r');
    // this->Character[4] = SevenSeg(this->x + 1.2, this->y, 'e');
    // this->Character[5] = SevenSeg(this->x + 1.5, this->y, '-');
    // this->Character[6] = SevenSeg(this->x + 1.8, this->y, c[5]);
    // this->Character[7] = SevenSeg(this->x + 2.1, this->y, c[4]);
    // this->Character[8] = SevenSeg(this->x + 2.4, this->y, c[3]);
    // this->Character[9] = SevenSeg(this->x + 2.7, this->y, c[2]);
    // this->Character[10] = SevenSeg(this->x + 3.0, this->y, c[1]);
    // this->Character[11] = SevenSeg(this->x + 3.3, this->y, c[0]);
}
