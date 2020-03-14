#include "geometry.h"
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
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

bool isNumber(char* string){
	int ln = strlen(string);
	if (string[0] == '.' || string[ln-1] == '.') return false;
	if (string[ln] == '\n') string[ln] = '\0';
	for (int i=0; i<ln; i++){
		if (!isdigit(string[i]) && string[i] != '.'){
			return false;
		}
	}
	return true;
}

int main()
{
    char* figure;
    char* lexeme;
    char backup[40];
    char* delim = "() ,";
    figure = input();
    strcpy(backup, figure);
    lexeme = strtok(figure, delim);
    if (strcmp(lexeme, "circle") == 0) {
	if (backup[6] != '(' || backup[strlen(backup)-2] != ')'){
		printf("Error: invalid circle\n");
		return -1;
	}
        Circle circle;
        lexeme = strtok(NULL, delim);
        if (lexeme != NULL && isNumber(lexeme))
            circle.center.x = atof(lexeme);
        else {
            printf("Error: invalid circle\n");
            return -1;
        }

        lexeme = strtok(NULL, delim);
        if (lexeme != NULL && isNumber(lexeme))
            circle.center.y = atof(lexeme);
        else {
            printf("Error: invalid circle\n");
            return -1;
        }

        lexeme = strtok(NULL, delim);
        if (lexeme != NULL && isNumber(lexeme))
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
	if (backup[8] != '(' || backup[strlen(backup)-2] != ')'){
		printf("Error: invalid triangle\n");
		return -1;
	}
        Triangle tri;
        lexeme = strtok(NULL, delim);
        if (lexeme != NULL && isNumber(lexeme))
            tri.a.x = atof(lexeme);
        else {
            printf("Error: invalid triangle\n");
            return -1;
        }

        lexeme = strtok(NULL, delim);
        if (lexeme != NULL && isNumber(lexeme))
            tri.a.y = atof(lexeme);
        else {
            printf("Error: invalid triangle\n");
            return -1;
        }

        lexeme = strtok(NULL, delim);
        if (lexeme != NULL && isNumber(lexeme))
            tri.b.x = atof(lexeme);
        else {
            printf("Error: invalid triangle\n");
            return -1;
        }

        lexeme = strtok(NULL, delim);
        if (lexeme != NULL && isNumber(lexeme))
            tri.b.y = atof(lexeme);
        else {
            printf("Error: invalid triangle\n");
            return -1;
        }

        lexeme = strtok(NULL, delim);
        if (lexeme != NULL && isNumber(lexeme))
            tri.c.x = atof(lexeme);
        else {
            printf("Error: invalid triangle\n");
            return -1;
        }

        lexeme = strtok(NULL, delim);
        if (lexeme != NULL && isNumber(lexeme))
            tri.c.y = atof(lexeme);
        else {
            printf("Error: invalid triangle\n");
            return -1;
        }

        lexeme = strtok(NULL, delim);
        if (lexeme != NULL && isNumber(lexeme))
            tri.check.x = atof(lexeme);
        else {
            printf("Error: invalid triangle\n");
            return -1;
        }

        lexeme = strtok(NULL, delim);
        if (lexeme != NULL && isNumber(lexeme))
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
