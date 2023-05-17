#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "include/car.h"
#include "include/config.h"


void show_course(const char course[XDIST][YDIST]);

int main(void) {
	
	//Preparatives

	char course[XDIST][YDIST];
	memset(course, FILL, sizeof course);
	Car car = {
		.letter = 'C',
		.xpos = FIRSTX,
		.ypos = FIRSTY
	};
	course[FIRSTX][FIRSTY] = car.letter;

	//unsigned char input = '0';
	//game
	
	unsigned char in = '0';
	while (in != 27) {
		system("cls");
		show_course(course);
		in = (char)_getch();
		switch (in) {
		case 'w':
		case 'W':
			if (car.xpos != 0) {
				moveW(&car, course);
			}
			break;
		case 'd':
		case 'D':
			if (car.ypos < YDIST - 1) {
				moveD(&car, course);
			}
			break;
		case 'a':
		case 'A':
			if (car.ypos != 0) {
				moveA(&car, course);
			}
			break;
		case 's':
		case 'S':
			if (car.xpos < XDIST - 1) {
				moveS(&car, course);
			}
			break;
		default:
			break;
		}
	}
	return 0;
}

void show_course(const char course[XDIST][YDIST]) {
	char row[YDIST * 3 + 1];
	printf("-------------------------------------------------------------------------------------------------------------------\n");
	for (int i = 0; i < XDIST; ++i) {
		memset(row, ' ', YDIST * 3);
		unsigned short int pos = 0;
		for (int j = 0; j < YDIST; ++j) {
			row[pos++] = course[i][j];
			pos += 2;
		}
		row[YDIST * 3] = '\0';
		printf("%s\n", row);
	}
	printf("-------------------------------------------------------------------------------------------------------------------\n");
}

