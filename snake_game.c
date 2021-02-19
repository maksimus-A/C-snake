
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h> // for sleeping smh
#include <conio.h>

#define XHEAD       X[0]
#define YHEAD       Y[0]
#define XTAIL       X[snake_size-1]
#define YTAIL       Y[snake_size-1]

#define BORDER      "* "
#define FOOD        'o'
#define FPS         60
#define FPS_1frame        (float)1000/FPS

enum Directions {
        right=0,
        left=1,
        up=2,
        down=3
}direction;


int main(void) {
    srand(time(0)); // Initialization of seed using time

	int rows=20, cols=20, ticks=4;
	int input1=0, input2=0, input3=0;
	/*
	printf("Type NOTHING DOESN'T FUCKING WORK FUCKING SHIT C MAN to use defaults.\n----------------\n\n");
	printf("Enter number of rows (default 10): ");
	scanf("%d", &input1);
	printf("Enter number of columns (default 10): ");
	scanf("%d", &input2);
	printf("Enter ticks per second (default 2): ");
	scanf("%d", &input3);*/

	/* If user inputs nothing just use defaults, otherwise use user's input */
	if (input1 > 0) { // if user input SOMETHING!
        rows = input1;
	}
	if (input2 > 0) {
        cols = input2;
	}
	if (input3 > 0) {
        ticks = input3;
	}

	char grid[rows][cols];
	for (int i=0; i < rows; i++) {
		for (int j=0; j < cols; j++) {
			grid[i][j] = ' ';
		}
	}
	/*
	Make snake, place snake, start ticking ?
	*/
	//char snake[rows * cols]; // bc snake can be as big as board max

	// Place da snek
	int snake_size = 1;
    int X[cols];
    int Y[rows];

    direction = 0; // right
    //XHEAD = rand() % cols;
    //YHEAD = rand() % rows;
    XHEAD = 2;
    YHEAD = 2;

    int foodX, foodY;
    foodX = rand() % cols;
    foodY = rand() % rows;

    grid[XHEAD][YHEAD] = '+';

    print_grid(rows, cols, grid);
	char playing = 1;

    int seconds = 0;
	while (playing) {
        // 1 for loop should supposedly be 1 second
		for (int frames=1; frames <= FPS; frames++) {
            Sleep(FPS_1frame);// basically controls framemrate
            /* Should check keyboard input  to set direction */
            if ( _kbhit() ) { // if there is keyboard input detected
                //printf("KEY DETECTED\n");
                int key_code = _getch(); // get the character code
                printf("KEY:%d\n", key_code);
                switch (key_code) { // the real value
                    case 87:
                        // code for arrow up
                        printf("HIT UP NIGGA!!!\n");
                        direction = 2;
                        break;
                    case 83:
                        // code for arrow down
                        printf("HIT DOWN NIGGA!!!\n");
                        direction = 3;
                        break;
                    case 68:
                        // code for arrow right
                        printf("HIT RIGHT NIGGA!!!\n");
                        direction = 0;
                        break;
                    case 65:
                        // code for arrow left
                        printf("HIT LEFT NIGGA!!!\n");
                        direction = 1;
                        break;
                    }
                if (key_code == 224) {// if the first value is esc
                    printf("ARROW KEY!!!");

                }
            }

            int update = frames % (FPS/ticks);
            // I need game to update only 2 times per second, this is how ?
            if (update == 0) {
                system("cls");
                printf("CLEARED SCREEN!\n");
                /* Check if hit food */
                /* Check if hit wall or self */
                move_snek(rows, cols, grid, X, Y, snake_size, direction);
                print_grid(rows, cols, grid);
                printf("XHEAD: %d\n", XHEAD);
                //printf("X: %d Y: %d\n", XHEAD, YHEAD);
            }
		}
		seconds ++;
		if (seconds > 4) playing = 0;
	}
	return 0;
}

void print_grid(int rows, int cols, char grid[rows][cols]) {
    // There will be some strange stuff bc im brute forcing border of asteriks or smnthn
    // Top of border
    for (int j=0; j < cols+2; j++) {
        printf("%s", BORDER);
    }
    printf("\n");
	 for (int i=0; i < rows; i++ ){
            printf("%c ", '*'); // Left side *
        	for (int j=0; j < cols; j++ ){
           		 printf("%c ",grid[i][j]);
        	}
            printf(" %c", '*'); // Right side *
        	printf("\n");
   	 }
   	 // Bottom of border
    for (int j=0; j < cols+2; j++) {
        printf("%s", BORDER);
    }
   	 printf("\n");

}

void move_snek(int rows, int cols, char grid[rows][cols], int X[cols], int Y[rows], int snake_size, int direction) {

    /* Actually moving snake */
    // ---------------------
    if (direction == 0) { // RIGHT
        grid[YHEAD][XHEAD+1] = '+';
        grid[YTAIL][XTAIL] = ' ';
        printf("Snek originally %d\n", XHEAD);
        XHEAD++;
        if (snake_size != 1) XTAIL--;
        //X[snake_size-1] -= 1;
        printf("Moved da snek to %d\n", XHEAD);
    }
    else if (direction == 1) { // LEFT
        grid[YHEAD][XHEAD-1] = '+';
        grid[YTAIL][XTAIL] = ' ';
        printf("Snek originally %d\n", XHEAD);
        XHEAD--;
        //if (snake_size != 1) XTAIL++;
        //X[snake_size-1] -= 1;
        printf("Moved da snek to %d\n", XHEAD);
    }
    else if (direction == 2) { // UP
        grid[YHEAD-1][XHEAD] = '+';
        grid[YTAIL][XTAIL] = ' ';
        printf("Snek originally %d\n", YHEAD);
        YHEAD--;
        //if (snake_size != 1) YTAIL--;
        //X[snake_size-1] -= 1;
        printf("Moved da snek to %d\n", YHEAD);
    }
    else if (direction == 3) { // DOWN
        grid[YHEAD+1][XHEAD] = '+';
        grid[YTAIL][XTAIL] = ' ';
        printf("Snek originally %d\n", YHEAD);
        YHEAD++;
        //if (snake_size != 1) YTAIL--;
        //X[snake_size-1] -= 1;
        printf("Moved da snek to %d\n", YHEAD);
    }
    // ---------------------
}
