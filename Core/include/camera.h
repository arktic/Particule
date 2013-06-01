#ifndef CAMERA_H
#define CAMERA_H

#include "Quaternion.h"
#include "Vectors.h"
#include "app.h"


class App;

class Camera {
public:
    Camera(double x, double y, double z,App* app);
    ~Camera();
    void rotate(float pitch, float roll, float yaw);
    void lookAt(const Vec3 &p);
    void disableFocus(const Quaternion &q);

    void updateViewMatrix(App* app);

    Vec3 getPosition();

    void moveForward(float speed);
    void moveBackward(float speed);
    void moveLeftSide(float speed);
    void moveRightSide(float speed);
    void moveUp(float speed);
    void moveDown(float speed);
    void toggleFocus();

private:
    Quaternion rot;
    Vec3 pos;
    Vec3 focus;
    Vec3 up;
    bool focusOn;
};


#endif
