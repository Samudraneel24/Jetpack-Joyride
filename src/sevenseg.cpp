#define GLM_ENABLE_EXPERIMENTAL
#include <iostream>
#include <fstream>
#include "sevenseg.h"
#include "main.h"
using namespace std;

SevenSeg::SevenSeg(float x, float y) {
    this->on = "1111111";
    for(int i=0; i<7;i++)
        this->R[i] = Rectangle(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, COLOR_BLACK);
    this->x = x, this->y = y;
}

void SevenSeg::draw(glm::mat4 VP) {
    for(int i=0; i<7; i++)
        if(this->on[i] == '1')
            this->R[i].draw(VP);
}

void SevenSeg::tick(float speedx, char c) {
    this->speedx = speedx;
    this->c = c;
    if(c == '0' || c == 'o')
        this->on = "1111110";
    else if(c == '1')
        this->on = "0001100";
    else if(c == '2')
        this->on = "0110111";
    else if(c == '3')
        this->on = "0011111";
    else if(c == '4')
        this->on = "1001101";
    else if(c == '5' || c == 's')
        this->on = "1011011";
    else if(c == '6')
        this->on = "1111011";
    else if(c == '7')
        this->on = "0001110";
    else if(c == '8')
        this->on = "1111111";
    else if(c == '9')
        this->on = "1011111";
    else if(c == 'c')
        this->on = "1110010";
    else if(c == 'r')
        this->on = "1100010";
    else if(c == 'e')
        this->on = "1110011";
    else if(c == '-')
        this->on = "0000001";
    // if(c == '1' || c == '2' || c == '3' || c == '7' || c == '-')
    //     this->on[0] = 0;
    // if(c == '1' || c == '3' || c == '4' || c == '5' || c == 's' || c == '7' || c == '9'  || c == '-')
    //     this->on[1] = 0;
    // if(c == '1' || c == '4' || c == '7' || c == 'r' || c == '-')
    //     this->on[2] = 0;
    // if(c == '2' || c == 'c' || c == 'r' || c == 'e' || c == '-')
    //     this->on[3] = 0;
    // if(c == '5' || c == '6' || c == 'c' || c == 'r' || c == 'e' || c == '-' || c == 's')
    //     this->on[4] = 0;
    // if(c == '1' || c == '4' || c == '-')
    //     this->on[5] = 0;
    // if(c == '0' || c == '1' || c == '7' || c == 'c' || c == 'r' || c == 'o')
    //     this->on[6] = 0;
    if(this->on[0] == '1')
        this->R[0] = Rectangle(x, y, 0.2, 0.03, -90.0, 0.0, 0.0, COLOR_BLACK);
    if(this->on[1] == '1')
        this->R[1] = Rectangle(x, y - 0.2, 0.2, 0.03, -90.0, 0.0, 0.0, COLOR_BLACK);
    if(this->on[2] == '1')
        this->R[2] = Rectangle(x, y - 0.4, 0.2, 0.03, 0.0, 0.0, 0.0, COLOR_BLACK);
    if(this->on[3] == '1')
        this->R[3] = Rectangle(x + 0.2 - 0.03, y - 0.2, 0.2, 0.03, -90.0, 0.0, 0.0, COLOR_BLACK);
    if(this->on[4] == '1')
        this->R[4] = Rectangle(x + 0.2 - 0.03, y, 0.2, 0.03, -90.0, 0.0, 0.0, COLOR_BLACK);
    if(this->on[5] == '1')
        this->R[5] = Rectangle(x, y, 0.2, 0.03, 0.0, 0.0, 0.0, COLOR_BLACK);
    if(this->on[6] == '1')
        this->R[6] = Rectangle(x, y - 0.2, 0.2, 0.03, 0.0, 0.0, 0.0, COLOR_BLACK);
    for(int i=0; i<7; i++)
        if(this->on[i] == 1){
            this->R[i].speedx = this->speedx;
            this->R[i].tick();
        }
}
