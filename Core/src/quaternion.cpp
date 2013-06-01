#include <iostream>
#include <cmath>
#include <iostream>
#include <cstdlib>

#include "quaternion.h"
#include "Vectors.h"


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
        s /= nrm;
        x /= nrm;
        y /= nrm;
        z /= nrm;
    }

    std::cout << "normalize avec une norme de zero impossible!";
    exit(-1);
}



std::ostream& operator<<(std::ostream& out, Quaternion& quat) {
    out << "<" << quat.getS() << ":" << quat.getX() << ":" << quat.getY() << ":" << quat.getZ() << ">"  << std::endl;
    return out;
}


ostream& operator<<(ostream& out, const Quaternion& quat) {
    out << "<" << quat.getS() << ":" << quat.getX() << ":" << quat.getY() << ":" << quat.getZ() << ">" << std::endl;
    return out;
}
