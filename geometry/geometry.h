#include <math.h>
#include <stdbool.h>
#ifndef GEOMETRY_H
#define GEOMETRY_H

typedef struct Point{
	double x;
	double y;
}Point;

typedef struct Circle{
	Point center;
	double radius;
}Circle;

typedef struct Triangle{
	Point a;
	Point b;
	Point c;
	Point check;
}Triangle;
double length(Point first, Point second);
bool isTriangle(Triangle tri);
bool isCircle(Circle circle);
double triPeri(Triangle tri);
double triArea(Triangle tri);
double circlePeri(Circle circle);
double circleArea(Circle circle);
double sqr(double x);

#endif

