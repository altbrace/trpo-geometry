#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include "geometry.h"

int main(){
	char input[40];
	char* parser;
	char* delim = "() ,";
	printf("Input WKT-like geometry:\n");
	fgets(input, 40, stdin);
	parser = strtok(input, delim);
	if (strcmp(parser, "circle") == 0){
		Circle circle;
		parser = strtok(NULL, delim);
		circle.center.x = atoi(parser);
		parser = strtok(NULL, delim);
		circle.center.y = atoi(parser);
		parser = strtok(NULL, delim);
		circle.radius = atof(parser);
	}
	return 0;


}
