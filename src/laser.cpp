#define GLM_ENABLE_EXPERIMENTAL
#include <iostream>
#include <fstream>
#include "laser.h"
#include "main.h"
#include "semicircle.h"
#include "rectangle.h"
using namespace std;

Rectangle left_rect, right_rect, beam;
Semicircle left_sem, right_sem;

Laser::Laser(float y) {
    left = 1.0, right = 11.5;
	this->y = y;
	this->left = left, this->right = right;
	this->on = 0;
    left_sem = Semicircle(left, y+0.2, 0.2, 0.0, 0.0, 90, COLOR_GREY);
    left_rect = Rectangle(left, y, 0.8, 0.4, 0.0, 0.0, 0.0, COLOR_GREY);
    beam = Rectangle(left + 0.8, y, right - left - 0.8, 0.4, 0.0, 0.0, 0.0, COLOR_ORANGE);
    right_rect = Rectangle(right, y, 0.8, 0.4, 0.0, 0.0, 0.0, COLOR_GREY);
    right_sem = Semicircle(right+0.8, y+0.2, 0.2, 0.0, 0.0, 270, COLOR_GREY);
}

void Laser::draw(glm::mat4 VP) {
	left_sem.draw(VP);
	left_rect.draw(VP);
	if(this->on == 1)
		beam.draw(VP);
	right_rect.draw(VP);
	right_sem.draw(VP);
}

void Laser::tick(int lasercounter) {
	left_sem.tick();
    left_rect.tick();
    beam.tick();
    right_rect.tick();
    right_sem.tick();
    if(lasercounter == 100)
    	this->on = 1;
    else if(lasercounter == 400){
    	this->on = 0;
    	left_sem.speedy = -0.01;
    	right_sem.speedy = -0.01;
    	left_rect.speedy = -0.01;
    	right_rect.speedy = -0.01;
    }
    else if(lasercounter == 500){
    	this->on = 1;
    	beam.position.y = left_rect.position.y;
    	left_sem.speedy = 0;
    	right_sem.speedy = 0;
    	left_rect.speedy = 0;
    	right_rect.speedy = 0;
    }
}
