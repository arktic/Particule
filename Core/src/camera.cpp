#include "Camera.h"
#include <cstdio>
#include "Vectors.h"

#include "app.h"
#include "GlFramework.h"

Camera::Camera( double x, double y, double z, App* app )
    :pos(x, y, z), rot(1, 0, 0, 0),
     focus(0, 0, 0), focusOn(true){
}

Camera::~Camera(void)
{}

void Camera::rotate(float pitch, float roll, float yaw)
{
    rot = rot * Quaternion(pitch, roll, yaw);
}

/* Focuses the camera to always be looking at the given point
 * regardless of position */
void Camera::lookAt(const Vec3 &p)
{
    focus = Vec3(p);
    focusOn = true;
}

void Camera::disableFocus( const Quaternion &q )
{
    rot = Quaternion(q);
    focusOn = false;
}



void Camera::updateViewMatrix(App* app) {

   // GLMatrix matrix = rot.toMatrix();
    Vec3 forward(focus.x - pos.x, focus.y - pos.y, focus.z - pos.z);
    forward.normalize();
    //cout << "forwar" << forward.x << "  " << forward.y << " " << forward.z << endl;
    Vec3 upWorld(0,1,0); // default up (world up)

    /* get the side vector */
    Vec3 right = forward.crossProduct(upWorld);
    right.normalize();

    /* get the camera up vector */
    up = right.crossProduct(forward);
    up.normalize();
    GLMatrix matrixView;

    matrixView.m[0][0] = right.x;
    matrixView.m[0][1] = right.y;
    matrixView.m[0][2] = right.z;
    matrixView.m[0][3] = 0;

    matrixView.m[1][0] = up.x;
    matrixView.m[1][1] = up.y;
    matrixView.m[1][2] = up.z;
    matrixView.m[1][3] = 0;

    matrixView.m[2][0] = -forward.x;
    matrixView.m[2][1] = -forward.y;
    matrixView.m[2][2] = -forward.z;
    matrixView.m[2][3] = 0;

    matrixView.m[3][0] = 0;
    matrixView.m[3][1] = 0;
    matrixView.m[3][2] = 0;
    matrixView.m[3][3] = 1;


    GLMatrix matrix;
    matrix.m[0][0] = 1;
    matrix.m[1][0] = 0;
    matrix.m[2][0] = 0;
    matrix.m[3][0] = 0;

    matrix.m[0][1] = 0;
    matrix.m[1][1] = 1;
    matrix.m[2][1] = 0;
    matrix.m[3][1] = 0;

    matrix.m[0][2] = 0;
    matrix.m[1][2] = 0;
    matrix.m[2][2] = 1;
    matrix.m[3][2] = 0;

    matrix.m[0][3] = -pos.x;
    matrix.m[1][3] = -pos.y;
    matrix.m[2][3] = -pos.z;
    matrix.m[3][3] = 1.0f;

    app->setViewMatrix( matrixView * matrix * rot.toMatrix());
}

void Camera::moveForward(float speed) {
    Vec3 orientation(focus.x - pos.x,focus.y - pos.y,focus.z - pos.z);

    orientation.normalize();
    orientation*=speed;

    pos += orientation;
    cout << "newpos:" << pos.x << " " << pos.y << " " << pos.z << endl;
    focus += orientation;
}

void Camera::moveBackward(float speed) {
    moveForward(-speed);
}



void Camera::moveRightSide(float speed) {
    Vec3 orientation(focus.x - pos.x,focus.y - pos.y,focus.z - pos.z);
    Vec3 lateral = orientation.crossProduct(up);

    lateral.normalize();
    lateral*=speed;

    pos += lateral;
    cout << "newpos:" << pos.x << " " << pos.y << " " << pos.z << endl;
    if(!focusOn)
        focus += lateral;
}

void Camera::moveLeftSide(float speed) {
    moveRightSide(-speed);
}

Vec3 Camera::getPosition() {
    return pos;
}

void Camera::moveUp(float speed) {
    pos += (up*-speed);
    if(!focusOn)
        focus += (up*-speed);
}

void Camera::moveDown(float speed) {
    pos += (up*speed);
    if(!focusOn)
        focus += (up*speed);
}

void Camera::toggleFocus() {
    focusOn = !focusOn;
}
