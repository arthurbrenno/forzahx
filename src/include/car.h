#ifndef CAR_H
#define CAR_H

#include "config.h"

typedef struct {
	unsigned int xpos;				// 4 bytes
	unsigned int ypos;				// 4 bytes
	unsigned char letter;           // 1 byte
	unsigned char _[3];             // 3 bytes padding
} Car;

void moveW(Car* car, char board[XDIST][YDIST]);
void moveD(Car* car, char board[XDIST][YDIST]);
void moveA(Car* car, char board[XDIST][YDIST]);
void moveS(Car* car, char board[XDIST][YDIST]);
#endif