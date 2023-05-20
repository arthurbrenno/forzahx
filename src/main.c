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
	
	char course[XDIST][YDIST];
	memset(course, FILL, sizeof course);

	Car car = {
		.letter = CCHARACTER,
		.xpos = FIRSTX,
		.ypos = FIRSTY
	};

	course[FIRSTX][FIRSTY] = car.letter;
	
	
	srand((unsigned int) time((void *) 0));
	show_course(course);
	int wins = 0;
	o_gen_vbarrier(course, rand() % XDIST);
	
	while (!GetAsyncKeyState(VK_ESCAPE)) {
		if (course[car.xpos][car.ypos + 1] == OBSTACLE) {
			wins = 0;
			course[car.xpos][car.ypos] = FILL;
			car.ypos = 0;
		}
		//this will determine if the barrier is going to be changed
		int rand_barrier = rand() % 30;

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
		else if (GetAsyncKeyState(VK_RIGHT) && car.ypos == YDIST - 1) {
			course[car.xpos][car.ypos] = CARPATH;
			car.ypos = 0;
			wins++;
			system("cls");
			printf("\nWINS: %d", wins);
			Sleep(1200);
			system("cls");
			show_course(course);
		}
		else {}
		
		//if the rand_barrier variable equals the magic number, then gen the barrier
		if (rand_barrier == 7) {
			o_gen_vbarrier(course, rand() % XDIST);
		}

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
