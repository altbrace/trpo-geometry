#include <stdio.h>
#include <math.h>
#include <geometry.h>

double length(Point first, Point second){
	double l = sqrt(sqr(second.x-first.x)+sqr(second.y-first.y));
	return l;
}

double triPeri(Triangle tri){
	double ab = length(tri.a, tri.b);
	double bc = length(tri.b, tri.c);
	double ac = length(tri.a, tri.c);

	return ab+bc+ac;
}

double circlePeri(Circle circle){
	return 2*M_PI*circle.radius;
}

double triArea(Triangle tri){
	double h_peri = triPeri(tri)/2;	
	double ab = length(tri.a, tri.b);
	double bc = length(tri.b, tri.c);
	double ac = length(tri.a, tri.c);
	double area = sqrt(h_peri*(h_peri-ab)*(h_peri-bc)*(h_peri-ac));
	return area;
}

double circleArea(Circle circle){
	return sqr(circle.radius)*M_PI;
}

