#define GLM_ENABLE_EXPERIMENTAL
#include "main.h"
#include "Lineintersection.h"
using namespace std;

bool onSegment(Point p, Point q, Point r)
{
 if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
 q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
 return true;
 return false;
}
// check if line joining p1, q1 intersects with 
// line joining p2, q2
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
 int o1 = orientation(p1, q1, p2);
 int o2 = orientation(p1, q1, q2);
 int o3 = orientation(p2, q2, p1);
 int o4 = orientation(p2, q2, q1);
 if (o1 != o2 && o3 != o4)
 return true;
 if (o1 == 0 && onSegment(p1, p2, q1)) return true;
 if (o2 == 0 && onSegment(p1, q2, q1)) return true;
 if (o3 == 0 && onSegment(p2, p1, q2)) return true;
 if (o4 == 0 && onSegment(p2, q1, q2)) return true;
 return false;
}

int orientation(Point p1, Point p2, Point p3)
{
 float val = (p2.y - p1.y) * (p3.x - p2.x) -
 (p2.x - p1.x) * (p3.y - p2.y);
 if (val <= 0.000001 && val>= -0.000001) return 0; // colinear
 return (val > 0)? 1: 2; // clock or counterclock wise
}
