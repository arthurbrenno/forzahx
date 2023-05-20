#include "../include/obstacles.h"

#include <stdio.h>

void o_gen_vbarrier(char course[XDIST][YDIST], int rand) {
	unsigned int j = YDIST - 1;
	for (unsigned int i = 0; i < XDIST; ++i) {
;		course[i][j] = OBSTACLE;
	}
	if (rand < XDIST && rand >= 0) {
		course[rand][j] = FILL;
		course[rand + 1][j] = FILL;
		course[rand + 2][j] = FILL;
	}
	else if (rand == XDIST - 1) {
		course[rand][j] = FILL;
		course[rand - 1][j] = FILL;
		course[rand - 2][j] = FILL;
	}
	else {}
}
