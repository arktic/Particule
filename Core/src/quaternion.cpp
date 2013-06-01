#include <iostream>
#include <cmath>
#include <iostream>
#include <cstdlib>

#include "quaternion.h"
#include "Vectors.h"
#include "GlFramework.h"


using namespace std;


Quaternion::Quaternion(float _s, float _x, float _y, float _z) {
    s=_s;
    x=_x;
    y=_y;
    z=_z;
}



/*Quaternion& Quaternion::operator+(const Quaternion& toAdd) const {
    Quaternion* quat = new Quaternion(this->getS() + toAdd.getS(),
                                      this->getS() + toAdd.getS(),
                                      this->getS() + toAdd.getS(),
                                      this->getS() + toAdd.getS(),);
    return *quat;
}*/


Quaternion& Quaternion::operator*(const Quaternion &toAdd) const {
    Vec3 v1(x,y,z);
    Vec3 v2(toAdd.getX(),toAdd.getY(),toAdd.getZ());

    Vec3 v;
    v=v2*s+v1*toAdd.getS()+v1.crossProduct(v2);


    Quaternion *ret = new Quaternion(toAdd.getS()*s - v1.dotProduct(v2), v.x, v.y, v.z);
    return *ret;
}

Quaternion& Quaternion::conjug() const {
    Quaternion * quat = new Quaternion(s,-x,-y,-z);
    return *quat;
}


Quaternion& Quaternion::inverse() const {
    float normecar= this->normeCarre();
    if(normecar!=0) {
        Quaternion * quat = new Quaternion(s/normecar,-x/normecar,-y/normecar,-z/normecar);
        return * quat;
    }

    std::cout << "inverse avec une norme de zero impossible!";
    exit(-1);
}


float Quaternion::norme() const {
    return (float) sqrt(s*s + x*x + y*y + z*z);
}

float Quaternion::normeCarre() const {
    return s*s + x*x + y*y + z*z;
}


Quaternion& Quaternion::normalize() {
    float nrm = norme();
    if(nrm != 0) {
        float d = 1/nrm;
        s *= nrm;
        x *= nrm;
        y *= nrm;
        z *= nrm;
    }

//    std::cout << "normalize avec une norme de zero impossible!";
//    exit(-1);
}



std::ostream& operator<<(std::ostream& out, Quaternion& quat) {
    out << "<" << quat.getS() << ":" << quat.getX() << ":" << quat.getY() << ":" << quat.getZ() << ">"  << std::endl;
    return out;
}


ostream& operator<<(ostream& out, const Quaternion& quat) {
    out << "<" << quat.getS() << ":" << quat.getX() << ":" << quat.getY() << ":" << quat.getZ() << ">" << std::endl;
    return out;
}



Quaternion::Quaternion(float angle, Vec3 v) {
    s = (float) cos(angle/2);
    float sinus = (float) sin(angle/2);

    x = v.x*sinus;
    y = v.y*sinus;
    z = v.z*sinus;
}


GLMatrix Quaternion::toMatrix() const {
    GLMatrix * mat = new GLMatrix();
    mat->m[0][0] = 1 - 2*y*y - 2*z*z;
    mat->m[0][1] = 2*x*y - 2*s*z;
    mat->m[0][2] = 2*x*z + 2*s*y;
    mat->m[0][3] = 0;

    mat->m[1][0] = 2*x*y + 2*s*z;
    mat->m[1][1] = 1-2*x*x - 2*z*z;
    mat->m[1][2] = 2*y*z - 2*s*x;
    mat->m[1][3] = 0;

    mat->m[2][0] = 2*x*z - 2*s*y;
    mat->m[2][1] = 2*y*z + 2*s*x;
    mat->m[2][2] = 1 - 2*x*x - 2*y*y;
    mat->m[2][3] = 0;

    mat->m[0][3] = 0;
    mat->m[1][3] = 0;
    mat->m[2][3] = 0;
    mat->m[3][3] = 1;

    return * mat;
 }

/* Construit un quaternion de rotation suivant le modèle pitch/roll/yaw */
Quaternion::Quaternion( float pitch, float roll, float yaw )
{

    float p = pitch * M_PI_2 / 180.0;
    float y = yaw   * M_PI_2 / 180.0;
    float r = roll  * M_PI_2 / 180.0;

    float sinp = sin(p);
    float siny = sin(y);
    float sinr = sin(r);
    float cosp = cos(p);
    float cosy = cos(y);
    float cosr = cos(r);

    this->s = cosr * cosp * cosy + sinr * sinp * siny;
    this->x = sinr * cosp * cosy - cosr * sinp * siny;
    this->y = cosr * sinp * cosy + sinr * cosp * siny;
    this->z = cosr * cosp * siny - sinr * sinp * cosy;

    normalize();
}
