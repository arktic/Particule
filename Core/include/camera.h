#ifndef DEF_CAMERA
#define DEF_CAMERA

#include "Vectors.h"

class Camera
{
private:

    float phi;
    float theta;
    Vec3 orientation;

    Vec3 Vaxe;
    Vec3 deplacementLateral;

    Vec3 position;
    Vec3 target;

public:

    Camera();
    Camera(float positionX, float positionY, float positionZ, float targetX, float targetY, float targetZ, float VaxeX, float VaxeY, float VaxeZ);
    ~Camera();

    void setTarget();
    void orienter(int xRel, int yRel);
    void moveForward(float speed);
    void moveBackward(float speed);
    void moveLeftSide(float speed);
    void moveRightSide(float speed);

    Vec3 getPosition() {return position;}
    Vec3 getTarget(){return target; }
    Vec3 getVaxe() {return Vaxe;}

/*

camera
scene de rendu
reglage via qT
*/

};

#endif
