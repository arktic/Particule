#ifndef UTILS_H
#define UTILS_H

#include "stdint.h"
#include "Vectors.h"

void time_ms(int64_t* tms);


int getBoundedRandom(int min, int max);
float getBoundedRandom(float min, float max);
Vec3 rotate(Vec3 ,float , int , int , int );

#endif