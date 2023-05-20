#ifndef OBSTACLES_H
#define OBSTACLES_H

#include "config.h"

/**
 * Generates a vertical barrier
 *
 * @param course, random number
 * @return Inited GIF Handler or NULL for error
 */
void o_gen_vbarrier(char course[XDIST][YDIST], int rand);

#endif