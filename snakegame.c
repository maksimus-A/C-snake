#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int rows=10, cols=10, ticks=2;
	printf("Enter number of rows (default 10):");
	scanf("%d", &rows);
	printf("Enter number of columns (default 10):");
	scanf("%d", &cols);
	printf("Enter ticks per second (default 2:");
	scanf("%d", &ticks);
	
	char grid[rows][cols];
	for (int i=0; i < rows; i++) {
		for (int j=0; j < columns; j++) {
			grid[i][j] = ' ';
		}
	}
	// print_grid(rows, cols, grid);			
	/*
	Make snake, place snake, start ticking ?	
	*/	
	char snake[rows * cols]; // bc snake can be as big as board max
	// Place da snek
	
	char playing = 1;
	while playing {
		/*	*/
	}	
	return 0;	
}

void print_grid(int rows, int cols, char grid[rows][cols]) {
	 for (int i=0; i < rows; i++ ){
        	for (int j=0; j < cols; j++ ){
           		 printf("%c ",grid[i][j]); // 0x2E hex value for .
        	}
        	printf("\n"); 
   	 }   
   	 printf("\n"); 
	
}
