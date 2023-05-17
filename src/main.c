#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <winuser.h>
#include "include/car.h"
#include "include/config.h"


void show_course(const char course[XDIST][YDIST]);

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
	show_course(course);
	while (!GetAsyncKeyState(VK_ESCAPE)) {
		if (GetAsyncKeyState(VK_UP) && car.xpos != 0) {
			system("cls");
			moveW(&car, course);
			show_course(course);
		}
		else if (GetAsyncKeyState(VK_DOWN) && car.xpos < XDIST - 1) {
			system("cls");
			moveS(&car, course);
			show_course(course);
		}
		else if (GetAsyncKeyState(VK_LEFT) && car.ypos != 0) {
			system("cls");
			moveA(&car, course);
			show_course(course);
		}
		else if (GetAsyncKeyState(VK_RIGHT) && car.ypos < YDIST - 1) {
			system("cls");
			moveD(&car, course);
			show_course(course);
		}
		else {}
		Sleep(TICK);
	}
	return 0;
}

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

