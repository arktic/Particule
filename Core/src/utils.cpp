#include "utils.h"

#include <windows.h>
#include "Vectors.h"
#include <cmath>
#include "GlFramework.h"
#include <limits>

void time_ms(int64_t* tms)
{
    SYSTEMTIME st;
    GetLocalTime(&st);
    *tms = int64_t(st.wDay*24*3600*1000+st.wHour*3600*1000+st.wMinute*60*1000+st.wSecond*1000+st.wMilliseconds);
    return;
}


int getBoundedRandom(int min, int max) {
    return (((float)rand()) / (double)RAND_MAX * (max - min)) + min;
}

float getBoundedRandom(float min, float max) {
    return (((float)rand()) / (double)RAND_MAX * (max - min)) + min;
}

Vec3 rotate(Vec3 p, float angle, int x, int y, int z) {
    GLfloat rAngle = M_PI * angle / 180.0f;
    GLfloat c = std::cos(rAngle);
    GLfloat s = std::sin(rAngle);

    GLfloat axisLen = std::sqrt(x * x + y * y + z * z);
    if(axisLen > std::numeric_limits<GLfloat>::epsilon())
    {
        x /= axisLen;
        y /= axisLen;
        z /= axisLen;
    }

    GLMatrix r;
    r.m[0][0] = x * x * (1.0f - c) + c;     r.m[0][1] = x * y * (1.0f - c) - z * s; r.m[0][2] = x * z * (1.0f - c) + y * s; r.m[0][3] = 0.0f;
    r.m[1][0] = y * x * (1.0f - c) + z * s; r.m[1][1] = y * y * (1.0f - c) + c;     r.m[1][2] = y * z * (1.0f - c) - x * s; r.m[1][3] = 0.0f;
    r.m[2][0] = z * x * (1.0f - c) - y * s; r.m[2][1] = y * z * (1.0f - c) + x * s; r.m[2][2] = z * z * (1.0f - c) + c;     r.m[2][3] = 0.0f;
    r.m[3][0] = 0.0f;                       r.m[3][1] = 0.0f;                       r.m[3][2] = 0.0f;                       r.m[3][3] = 1.0f;

    // application de r sur p
    Vec4 ps;
    ps.x = p.x; ps.y = p.y; ps.z = p.z; ps.w = 1;
    Vec4 pRot;
    pRot = r*ps;
    return Vec3(pRot.x, pRot.y, pRot.z);
}
