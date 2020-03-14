#include "geometry.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* input()
{
    char* input = malloc(sizeof(char) * 40);
    printf("Input WKT-like geometry:\n");
    fgets(input, 40, stdin);
    return input;
}

int main()
{
    char* figure;
    char* lexeme;
    char* delim = "() ,";
    figure = input();
    lexeme = strtok(figure, delim);
    if (strcmp(lexeme, "circle") == 0) {
        Circle circle;
        lexeme = strtok(NULL, delim);
        if (lexeme != NULL)
            circle.center.x = atof(lexeme);
        else {
            printf("Error: invalid circle\n");
            return -1;
        }

        lexeme = strtok(NULL, delim);
        if (lexeme != NULL)
            circle.center.y = atof(lexeme);
        else {
            printf("Error: invalid circle\n");
            return -1;
        }

        lexeme = strtok(NULL, delim);
        if (lexeme != NULL)
            circle.radius = atof(lexeme);
        else {
            printf("Error: invalid circle\n");
            return -1;
        }
        if (!isCircle(circle)) {
            printf("Error: invalid circle\n");
            return -1;
        }
        printf("Perimeter: %.2f\n", circlePeri(circle));
        printf("Area: %.2f\n", circleArea(circle));
    } else if (strcmp(lexeme, "triangle") == 0) {
        Triangle tri;
        lexeme = strtok(NULL, delim);
        if (lexeme != NULL)
            tri.a.x = atof(lexeme);
        else {
            printf("Error: invalid triangle\n");
            return -1;
        }

        lexeme = strtok(NULL, delim);
        if (lexeme != NULL)
            tri.a.y = atof(lexeme);
        else {
            printf("Error: invalid triangle\n");
            return -1;
        }

        lexeme = strtok(NULL, delim);
        if (lexeme != NULL)
            tri.b.x = atof(lexeme);
        else {
            printf("Error: invalid triangle\n");
            return -1;
        }

        lexeme = strtok(NULL, delim);
        if (lexeme != NULL)
            tri.b.y = atof(lexeme);
        else {
            printf("Error: invalid triangle\n");
            return -1;
        }

        lexeme = strtok(NULL, delim);
        if (lexeme != NULL)
            tri.c.x = atof(lexeme);
        else {
            printf("Error: invalid triangle\n");
            return -1;
        }

        lexeme = strtok(NULL, delim);
        if (lexeme != NULL)
            tri.c.y = atof(lexeme);
        else {
            printf("Error: invalid triangle\n");
            return -1;
        }

        lexeme = strtok(NULL, delim);
        if (lexeme != NULL)
            tri.check.x = atof(lexeme);
        else {
            printf("Error: invalid triangle\n");
            return -1;
        }

        lexeme = strtok(NULL, delim);
        if (lexeme != NULL)
            tri.check.y = atof(lexeme);
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
        printf("Error: unknown shape '%s'\n", lexeme);
    return 0;
}
