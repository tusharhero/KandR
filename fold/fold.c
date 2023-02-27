//A program to ``fold`` long input lines into two or more shorter lines after the last non-blank character that occurs before the nth column of input.
//Make sure the program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column.

//I think the nth column should be a constant. To break it into smaller lines we need to add a newline character to the line.
//I will first implement a function to just break it after it reaches the nth column. Now that I am done with the basics, Let me add make it so that it terminates at the first blank character it finds. Maybe I need to do it in reverse so that its easier

#include "get_line.h"

#define COLUMNSIZE 8

void fold(char line[MAXSIZE], char folded[MAXSIZE], int len){
  int extrapartialcolumn = len%COLUMNSIZE;
  int currentcolumn = len- extrapartialcolumn;
  int isitfolded  =  0;
  for(int i = len; i >= 0; i--){
    if (line[i] == ' ' && isitfolded == 0) {
      folded[i] = '\n';
      isitfolded = 1;
    }
    else{
      folded[i] = line[i];
    }
    if ((len - extrapartialcolumn)%i == 0) {
      currentcolumn -= COLUMNSIZE;
      isitfolded = 0;
    }
  }
}

int main(){
	char line[MAXSIZE];int i;char folded[MAXSIZE];
	while((i = get_line(line)) != -1){
		fold(line,folded,i);
		printf("%s\n",folded);
	}
	return 0;
}
