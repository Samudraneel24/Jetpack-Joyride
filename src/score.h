#include "main.h"
#include "sevenseg.h"

#ifndef SCORE_H
#define SCORE_H


class Score {
public:
    Score() {}
    Score(float x, float y);
    void draw(glm::mat4 VP);
    void tick(float speedx, int score);
    SevenSeg Character[12];
    float x, y, speedx;
private:
    VAO *object;
};

#endif // SCORE_H
