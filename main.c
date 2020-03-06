#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include "geometry.h"

int main(){
	char input[30];
	char* delim = "( ,";
	printf("Input WKT-like geometry:\n");
	scanf("%s", input);
	char* parser = strtok(input, delim);
	printf("%s", parser);
	if (strcmp(parser, "circle") == 0){
		printf("\n");
		Circle circle;
		parser = strtok(NULL, delim);
	//	circle.center.x = atoi(parser[0]);
	//	circle.center.y = atoi(parser[3]);
		printf("%s", parser);
		parser = strtok(NULL, delim);
		printf("%s", parser);
		
		printf("%s", parser);
		parser = strtok(NULL, delim);
	}
	return 0;
}
