#include "utils.h"

#include <windows.h>

void time_ms(int64_t* tms)
{
    SYSTEMTIME st;
    GetLocalTime(&st);
    *tms = int64_t(st.wDay*24*3600*1000+st.wHour*3600*1000+st.wMinute*60*1000+st.wSecond*1000+st.wMilliseconds);
    return;
}


int getBoundedRandom(int min, int max) {
    return (rand() / (double)RAND_MAX * (max - min)) + min;
}

float getBoundedRandom(float min, float max) {
    return (rand() / (double)RAND_MAX * (max - min)) + min;
}
