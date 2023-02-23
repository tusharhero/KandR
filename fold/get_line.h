
#include <stdio.h>
#define MAXSIZE 1000

int get_line(char line[MAXSIZE]){ // and return the length of the line.
	char c; int i = 0;
	while( (c = getchar()) != '\n' && i < MAXSIZE){
		line[i] = c;
		++i;
		if(c == EOF){
			i = -1;
			break;
		}
	}
	line[i] = 0; // terminate the line.
	return i;
}
