#ifndef QUATERNION_H
#define QUATERNION_H

#include <iostream>


//using namespace std;

class Quaternion {
    float s,x,y,z;



public:

    Quaternion(float _s, float _x, float _y, float _z);




    /* construit un quaternion de rotation d'angle angle et de vecteur v.
    Note : v doit être nomaliser */
    //Quaternion(float angle, Vec3 v);

    //Quaternion& operator+(const Quaternion& toAdd) const;
    Quaternion& operator*(const Quaternion &toAdd) const;

    //Quaternion& operator*(const float f) const;




    /* retourne le conjugué d'un quaternion.  */
    Quaternion& conjug() const;

    /* inverse ce quaternion et le retourne*/
    Quaternion& inverse() const;

    /* retourne la norme de ce quaternion */
    float norme() const ;

    /* retourne la norme au carré de ce quaternion */
    float normeCarre() const;

    /* normalise ce quaternion et le retourne */
    Quaternion& normalize();


    /* retourne la matrice associée à ce quaternion */
    //mat44 toMatrix() const;



    Quaternion& addX(float _x) { x +=_x 	;	return *this;}
    Quaternion& addY(float _y) { y +=_y 	;	return *this;}
    Quaternion& addZ(float _z) { z +=_z 	;	return *this;}
    Quaternion& addS(float _s) { s +=_s 	;	return *this;}



    //getters & setters
    float getS() const {		return s;		}

    void setS(float s) { 		this->s = s; 	}

    float getX() const {		return x;		}

    void setX(float x) {		this->x = x;	}

    float getY() const {		return y;		}

    void setY(float y) {		this->y = y;	}

    float getZ() const {		return z;		}

    void setZ(float z) {		this->z = z;	}



    friend std::ostream& operator<<(std::ostream& out, Quaternion& quat);
    friend std::ostream& operator<<(std::ostream& out, const Quaternion& quat);

};



#endif
