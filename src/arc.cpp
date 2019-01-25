#define GLM_ENABLE_EXPERIMENTAL
#include <iostream>
#include <fstream>
#include <algorithm>
#include "arc.h"
#include "main.h"
using namespace std;

Arc::Arc(float x, float y) {
    this->x = x, this->y = y;
    this->radius = 4.0;
    this->Large = Semicircle(x, y, 4.0, 0.0, 0.0, 0.0, COLOR_PINK);
    this->Small = Semicircle(x, y, 3.5, 0.0, 0.0, 0.0, COLOR_BACKGROUND);
}

void Arc::draw(glm::mat4 VP) {
    Large.draw(VP), Small.draw(VP);
}

void Arc::tick(float speedx) {
    Large.speedx = Small.speedx = speedx;
    Large.tick(), Small.tick();
}

float Arc::Get_y(float x){
    float xcord = x - this->x;
    float ycord = sqrt(this->radius*this->radius - xcord*xcord);
    return ycord + this->y;
}
