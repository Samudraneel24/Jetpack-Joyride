#define GLM_ENABLE_EXPERIMENTAL
#include <iostream>
#include <fstream>
#include "fire.h"
#include "main.h"
#include "circle.h"
#include "rectangle.h"
using namespace std;
#define sqr(x) ((x)*(x))

Circle S1, S2;
Rectangle R;

Fire::Fire(float leftx, float lefty, float rightx, float righty, float speedx, float speedy) {
    this->leftx = leftx;
    this->lefty = lefty;
    this->righty = righty;
    this->rightx = rightx;
    this->speedx = speedx;
    this->speedy = speedy;
    this->len = sqrt( sqr(rightx - leftx) + sqr(righty - lefty));
    this->angle = asin( (righty - lefty) / this->len );
    float degree_angle = (this->angle*180.0)/M_PI;
    S1 = Circle(leftx, lefty, 0.2, 0.0, 0.0, COLOR_GREY );
    S2 = Circle(rightx, righty, 0.2, 0.0, 0.0, COLOR_GREY );
    R = Rectangle(leftx + 0.2*sin(this->angle), lefty - 0.2*cos(this->angle), this->len, 0.4, degree_angle, 0.0, 0.0, COLOR_YELLOW);
}

void Fire::draw(glm::mat4 VP) {
	R.draw(VP);
    S1.draw(VP);
    S2.draw(VP);
}

void Fire::tick(float speedx, float speedy) {
	R.tick();
    S1.tick();
    S2.tick();
    S1.speedx = speedx, S1.speedy = speedy;
    S2.speedx = speedx, S2.speedy = speedy;
    R.speedx = speedx, R.speedy = speedy;
    this->rightx = S2.position.x + S2.radius;
}
