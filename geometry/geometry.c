#include "geometry.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

double sqr(double x)
{
    return pow(x, 2);
}

double length(Point first, Point second)
{
    double l = sqrt(sqr(second.x - first.x) + sqr(second.y - first.y));
    return l;
}

bool isTriangle(Triangle tri)
{
    double ab = length(tri.a, tri.b);
    double bc = length(tri.b, tri.c);
    double ac = length(tri.a, tri.c);
    int x = tri.a.x;
    int y = tri.a.y;
    int x1 = tri.check.x;
    int y1 = tri.check.y;
    if (ab < bc + ac && bc < ac + ab && ac < ab + bc && x == x1 && y == y1)
        return true;
    return false;
}

double triPeri(Triangle tri)
{
    double ab = length(tri.a, tri.b);
    double bc = length(tri.b, tri.c);
    double ac = length(tri.a, tri.c);

    return ab + bc + ac;
}

double circlePeri(Circle circle)
{
    return 2 * M_PI * circle.radius;
}

double triArea(Triangle tri)
{
    double h_peri = triPeri(tri) / 2;
    double ab = length(tri.a, tri.b);
    double bc = length(tri.b, tri.c);
    double ac = length(tri.a, tri.c);
    double area = sqrt(h_peri * (h_peri - ab) * (h_peri - bc) * (h_peri - ac));
    return area;
}

double circleArea(Circle circle)
{
    return sqr(circle.radius) * M_PI;
}

bool isCircle(Circle circle)
{
    if (circle.radius <= 0)
        return false;
    return true;
}
