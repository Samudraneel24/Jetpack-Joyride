#define GLM_ENABLE_EXPERIMENTAL
#include <iostream>
#include <fstream>
#include <algorithm>
#include "boomerang.h"
#include "main.h"
using namespace std;

Boomerang::Boomerang(float x, float y) {
    this->angle = 0.0;
    this->speedx = 0.00;
    this->speedy = -0.025;
    this->x = x, this->y = y;
    Centre1 = Rectangle(x, y, 1.0, 0.2, 45.0, 0.0, this->speedy, COLOR_TRUERED);
    Centre2 = Rectangle(x, y, 0.8, 0.2, -45.0, 0.0, this->speedy, COLOR_TRUERED);
    Top = Rectangle(x , y , 0.8, 0.2, 45.0, 0.0, 0.0, COLOR_BLACK);
    Bottom = Rectangle(x , y , 0.6, 0.2, -45.0, 0.0, 0.0, COLOR_BLACK);
}

void Boomerang::draw(glm::mat4 VP) {
    Centre1.draw(VP);
    Centre2.draw(VP);
    Top.draw(VP);
    Bottom.draw(VP);
}

int Boomerang::tick(float speedx) {
    speedx *= -1.0;    this->speedx = 2.0*(this->y - 5.3)*this->speedy;
    Centre1.speedx = Centre2.speedx = Top.speedx = Bottom.speedx = -1.0*(this->speedx);
    Centre1.speedy = Centre2.speedy = Top.speedy = Bottom.speedy = this->speedy;
    Centre1.rotation += 4.0;
    Centre2.rotation += 4.0;
    Top.rotation += 4.0;
    Bottom.rotation += 4.0;
    Centre1.tick(), Centre2.tick(), Top.tick(), Bottom.tick();
    this->x = Centre1.position.x, this->y = Centre1.position.y;
    if(this->x > 15.0 && this->y < 3.0)
        return 1;
    return 0;
}
