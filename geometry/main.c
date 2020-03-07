#include "geometry.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* _input()
{
    char* input = malloc(sizeof(char) * 40);
    printf("Input WKT-like geometry:\n");
    fgets(input, 40, stdin);
    return input;
}

int main()
{
    char* input;
    char input_copy[40];
    char* parser;
    char* delim = "() ,";
    input = _input();
    strcpy(input_copy, input);
    parser = strtok(input, delim);
    if (strcmp(parser, "circle") == 0) {
        Circle circle;
        parser = strtok(NULL, delim);

        if (parser != NULL)
            circle.center.x = atoi(parser);
        else {
            printf("Error: invalid circle\n");
            return -1;
        }

        parser = strtok(NULL, delim);
        if (parser != NULL)
            circle.center.y = atoi(parser);
        else {
            printf("Error: invalid circle\n");
            return -1;
        }

        parser = strtok(NULL, delim);
        if (parser != NULL)
            circle.radius = atof(parser);
        else {
            printf("Error: invalid circle\n");
            return -1;
        }
        if (!isCircle(circle))
	{
            printf("Error: invalid circle\n");
            return -1;
        }
        printf("Perimeter: %.2f\n", circlePeri(circle));
        printf("Area: %.2f\n", circleArea(circle));
    } else if (strcmp(parser, "triangle") == 0) {
        Triangle tri;
        parser = strtok(NULL, delim);
        if (parser != NULL)
            tri.a.x = atoi(parser);
        else {
            printf("Error: invalid triangle\n");
            return -1;
        }

        parser = strtok(NULL, delim);
        if (parser != NULL)
            tri.a.y = atoi(parser);
        else {
            printf("Error: invalid triangle\n");
            return -1;
        }

        parser = strtok(NULL, delim);
        if (parser != NULL)
            tri.b.x = atoi(parser);
        else {
            printf("Error: invalid triangle\n");
            return -1;
        }

        parser = strtok(NULL, delim);
        if (parser != NULL)
            tri.b.y = atoi(parser);
        else {
            printf("Error: invalid triangle\n");
            return -1;
        }

        parser = strtok(NULL, delim);
        if (parser != NULL)
            tri.c.x = atoi(parser);
        else {
            printf("Error: invalid triangle\n");
            return -1;
        }

        parser = strtok(NULL, delim);
        if (parser != NULL)
            tri.c.y = atoi(parser);
        else {
            printf("Error: invalid triangle\n");
            return -1;
        }

        parser = strtok(NULL, delim);
        if (parser != NULL)
            tri.check.x = atoi(parser);
        else {
            printf("Error: invalid triangle\n");
            return -1;
        }

        parser = strtok(NULL, delim);
        if (parser != NULL)
            tri.check.y = atoi(parser);
        else {
            printf("Error: invalid triangle\n");
            return -1;
        }

        if (isTriangle(tri) == true) {
            printf("Perimeter: %.2f\n", triPeri(tri));
            printf("Area: %.2f\n", triArea(tri));
        } else
            printf("Error: invalid triangle\n");
    } else
        printf("Error: unknown shape '%s'", parser);
    return 0;
}
