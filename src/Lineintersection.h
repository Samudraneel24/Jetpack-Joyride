#include "main.h"
#define GLM_ENABLE_EXPERIMENTAL

#ifndef LINEINTERSECTION_H
#define LINEINTERSECTION_H

struct Point{
	float x, y;
};

bool onSegment(Point p, Point q, Point r);
bool doIntersect(Point p1, Point q1, Point p2, Point q2);
int orientation(Point p1, Point p2, Point p3);

#endif // LINEINTERSECTION_H