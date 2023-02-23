//A program to ``fold`` long input lines into two or more shorter lines after the last non-blank character that occurs before the nth column of input.
//Make sure the program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column.

//I think the nth column should be a constant. To break it into smaller lines we need to add a newline character to the line.
//I will first implement a function to just break it after it reaches the nth column. Now that I am done with the basics, Let me add make it so that it terminates at the first blank character it finds. Maybe I need to do it in reverse so that its easier

#include "get_line.h"

#define COLUMNSIZE 24

void fold(char line[MAXSIZE], char folded[MAXSIZE], int len){
  int i;
  int current_col = COLUMNSIZE;
  for(i = 0; i < len; ++i){
    if(i == current_col){
      folded[i] = '\n';
    }
    if(i%COLUMNSIZE == 0 && i != 0){
      current_col += COLUMNSIZE;
    }
    else{
      folded[i] = line[i];
    }
  }
  folded[i] = 0;
}

int main(){
	char line[MAXSIZE];int i;char folded[MAXSIZE];
	while((i = get_line(line)) != -1){
		fold(line,folded,i);
		printf("%s\n",folded);
	}
	return 0;
}
