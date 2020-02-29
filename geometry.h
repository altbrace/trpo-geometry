typedef struct Point{
	int x;
	int y;
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
