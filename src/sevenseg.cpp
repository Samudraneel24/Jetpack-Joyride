#define GLM_ENABLE_EXPERIMENTAL
#include <iostream>
#include <fstream>
#include "sevenseg.h"
#include "main.h"
using namespace std;

SevenSeg::SevenSeg(float x, float y) {
    for(int i=0; i<7;i++){
        this->on[i] = 1;
        this->R[i] = Rectangle(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, COLOR_BLACK);
    }
    this->x = x, this->y = y;
}

void SevenSeg::draw(glm::mat4 VP) {
    for(int i=0; i<7; i++)
        if(this->on[i] == 1)
            this->R[i].draw(VP);
}

void SevenSeg::tick(float speedx, char c) {
    this->speedx = speedx;
    this->c = c;
    for(int i=0; i<7; i++)
        this->on[i] = 1;
    if(c == '1' || c == '2' || c == '3' || c == '7' || c == '-')
        this->on[0] = 0;
    if(c == '1' || c == '3' || c == '4' || c == '5' || c == 's' || c == '7' || c == '9'  || c == '-')
        this->on[1] = 0;
    if(c == '1' || c == '4' || c == '7' || c == 'r' || c == '-')
        this->on[2] = 0;
    if(c == '2' || c == 'c' || c == 'r' || c == 'e' || c == '-')
        this->on[3] = 0;
    if(c == '5' || c == '6' || c == 'c' || c == 'r' || c == 'e' || c == '-' || c == 's')
        this->on[4] = 0;
    if(c == '1' || c == '4' || c == '-')
        this->on[5] = 0;
    if(c == '0' || c == '1' || c == '7' || c == 'c' || c == 'r' || c == 'o')
        this->on[6] = 0;
    if(this->on[0] == 1)
        this->R[0] = Rectangle(x, y, 0.2, 0.03, -90.0, 0.0, 0.0, COLOR_BLACK);
    if(this->on[1] == 1)
        this->R[1] = Rectangle(x, y - 0.2, 0.2, 0.03, -90.0, 0.0, 0.0, COLOR_BLACK);
    if(this->on[2] == 1)
        this->R[2] = Rectangle(x, y - 0.4, 0.2, 0.03, 0.0, 0.0, 0.0, COLOR_BLACK);
    if(this->on[3] == 1)
        this->R[3] = Rectangle(x + 0.2, y - 0.2, 0.2, 0.03, -90.0, 0.0, 0.0, COLOR_BLACK);
    if(this->on[4] == 1)
        this->R[4] = Rectangle(x + 0.2, y, 0.2, 0.03, -90.0, 0.0, 0.0, COLOR_BLACK);
    if(this->on[5] == 1)
        this->R[5] = Rectangle(x, y, 0.2, 0.03, 0.0, 0.0, 0.0, COLOR_BLACK);
    if(this->on[6] == 1)
        this->R[6] = Rectangle(x, y - 0.2, 0.2, 0.03, 0.0, 0.0, 0.0, COLOR_BLACK);
    for(int i=0; i<7; i++)
        if(this->on[i] == 1){
            this->R[i].speedx = this->speedx;
            this->R[i].tick();
        }
}
