#include "../include/car.h"

void moveW(Car* car, char board[XDIST][YDIST]) {
	board[car->xpos][car->ypos] = '.';
	car->xpos -= 1;
	board[car->xpos][car->ypos] = car->letter;
}

void moveD(Car* car, char board[XDIST][YDIST]) {
	board[car->xpos][car->ypos] = '.';
	car->ypos += 1;
	board[car->xpos][car->ypos] = car->letter;
}

void moveA(Car* car, char board[XDIST][YDIST]) {
	board[car->xpos][car->ypos] = '.';
	car->ypos -= 1;
	board[car->xpos][car->ypos] = car->letter;
}

void moveS(Car* car, char board[XDIST][YDIST]) {
	board[car->xpos][car->ypos] = '.';
	car->xpos += 1;
	board[car->xpos][car->ypos] = car->letter;
}
