#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <winuser.h>
#include "include/car.h"
#include "include/config.h"
#include "include/obstacles.h"

void show_course(const char course[XDIST][YDIST]);
void clear_screen(void);

int main(void) {
	
	//Preparatives
	char course[XDIST][YDIST];
	memset(course, FILL, sizeof course);
	Car car = {
		.letter = CCHARACTER,
		.xpos = FIRSTX,
		.ypos = FIRSTY
	};
	course[FIRSTX][FIRSTY] = car.letter;
	//game
	srand((unsigned int) time(NULL));
	show_course(course);
	while (!GetAsyncKeyState(VK_ESCAPE)) {
		if (GetAsyncKeyState(VK_UP) && car.xpos != 0) {
			clear_screen();
			moveW(&car, course);
			show_course(course);
		}
		else if (GetAsyncKeyState(VK_DOWN) && car.xpos < XDIST - 1) {
			clear_screen();
			moveS(&car, course);
			show_course(course);
		}
		else if (GetAsyncKeyState(VK_LEFT) && car.ypos != 0) {
			clear_screen();
			moveA(&car, course);
			show_course(course);
		}
		else if (GetAsyncKeyState(VK_RIGHT) && car.ypos < YDIST - 1) {
			clear_screen();
			moveD(&car, course);
			show_course(course);
		}
		else if (GetAsyncKeyState(VK_NUMPAD0)) {
			clear_screen();
			memset(course, ' ', sizeof course);
			course[car.xpos][car.ypos] = CCHARACTER;
			show_course(course);
		}
		else if (GetAsyncKeyState(VK_RIGHT) && car.ypos == YDIST - 1) {
			course[car.xpos][car.ypos] = CARPATH;
			car.ypos = 0;
		}
		else if (GetAsyncKeyState(VK_LEFT) && car.ypos == 0) {
			course[car.xpos][car.ypos] = CARPATH;
			car.ypos = YDIST - 1;
		}
		else if (GetAsyncKeyState(VK_UP) && car.xpos == 0) {
			course[car.xpos][car.ypos] = CARPATH;
			car.xpos = XDIST - 1;
		}
		else if (GetAsyncKeyState(VK_DOWN) && car.xpos == XDIST - 1) {
			course[car.xpos][car.ypos] = CARPATH;
			car.xpos = 0;
		}
		else {}

		Sleep(TICK);
	}
	return 0;
}

/**
 * Prints a 2D course.
 *
 * @param const course, won't be modified.
 * @return void
 */
void show_course(const char course[XDIST][YDIST]) {
	char row[YDIST * 3 + 1];
	puts("----------------------------------------------------------------------------------------------------------------------");
	for (unsigned int i = 0; i < XDIST; ++i) {
		memset(row, ' ', YDIST * 3);
		short int pos = -1;
		for (unsigned int j = 0; j < YDIST; ++j) {
			row[++pos] = course[i][j];
			pos += 2;
		}
		row[YDIST * 3] = '\0';
		puts(row);
	}
	puts("----------------------------------------------------------------------------------------------------------------------");
}

/**
 * This sets the cursor at the top left corner.
 *
 * @param void.
 * @return void
 */
void clear_screen(void) {
	COORD cursor_pos = {.X = 0, .Y = 0};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor_pos);
}
