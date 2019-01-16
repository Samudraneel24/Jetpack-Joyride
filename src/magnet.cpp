#define GLM_ENABLE_EXPERIMENTAL
#include <iostream>
#include <fstream>
#include "magnet.h"
#include "main.h"
#include "semicircle.h"
#include "rectangle.h"
using namespace std;

Semicircle Small, Large;
Rectangle Up1, Up2, Down1, Down2;

Magnet::Magnet(float x, float y) {
    this->x = x;
    this->y = y;
    Large = Semicircle(x, y, 0.8, 0.0, 0.0, 270, COLOR_TRUERED);
    Small = Semicircle(x, y, 0.4, 0.0, 0.0, 270, COLOR_BACKGROUND);
    Up2 = Rectangle(x - 0.4, y + 0.4, 0.4, 0.4, 0.0, 0.0, 0.0, COLOR_TRUERED);
    Up1 = Rectangle(x - 0.8, y + 0.4, 0.4, 0.4, 0.0, 0.0, 0.0, COLOR_GREY);
    Down2 = Rectangle(x - 0.4, y - 0.8, 0.4, 0.4, 0.0, 0.0, 0.0, COLOR_TRUERED);
    Down1 = Rectangle(x - 0.8, y - 0.8, 0.4, 0.4, 0.0, 0.0, 0.0, COLOR_GREY);
}

void Magnet::draw(glm::mat4 VP) {
	Large.draw(VP);
    Small.draw(VP);
    Up1.draw(VP);
    Up2.draw(VP);
    Down1.draw(VP);
    Down2.draw(VP);
}

void Magnet::tick(float speedx, float speedy) {
	Large.tick();
    Small.tick();
    Up1.tick();
    Up2.tick();
    Down1.tick();
    Down2.tick();
    Large.speedx = speedx, Large.speedy = speedy;
    Small.speedx = speedx, Small.speedy = speedy;
    Up1.speedx = speedx, Up1.speedy = speedy;
    Up2.speedx = speedx, Up2.speedy = speedy;
    Down1.speedx = speedx, Down1.speedy = speedy;
    Down2.speedx = speedx, Down2.speedy = speedy;
    this->x = Large.position.x;
    this->y = Large.position.y;
}
