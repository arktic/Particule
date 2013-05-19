#ifndef UTILS_H
#define UTILS_H

#include "stdint.h"

void time_ms(int64_t* tms);


int getBoundedRandom(int min, int max);
float getBoundedRandom(float min, float max);


#endif