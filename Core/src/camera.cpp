#include "camera.h"


Camera::Camera() : phi(0.0), theta(0.0), orientation(), Vaxe(0, 1, 0), deplacementLateral(), position(), target()
{

}

Camera::Camera(float positionX, float positionY, float positionZ, float targetX, float targetY, float targetZ, float axeX, float axeY, float axeZ) :
               phi(0.0), theta(0.0), orientation(), Vaxe(axeX, axeY, axeZ), deplacementLateral(),
               position(positionX, positionY, positionZ), target(targetX, targetY, targetZ)
{
    orientation = target - position;
    orientation.normalize();

    deplacementLateral = Vaxe.crossProduct(orientation);
    deplacementLateral.normalize();
}

Camera::~Camera()
{

}

void Camera::orienter(int xRel, int yRel)
{
    // Récupération des angles

    phi += -yRel * 0.5;
    theta += -xRel * 0.5;


    // Limitation de l'angle phi

    if(phi > 89.0)
        phi = 89.0;

    else if(phi < -89.0)
        phi = -89.0;


    // Conversion des angles en radian

    float phiRadian = phi * M_PI / 180;
    float thetaRadian = theta * M_PI / 180;


    // Si l'axe vertical est l'axe X

    if(Vaxe.x == 1.0)
    {
        // Calcul des coordonnées sphériques

        orientation.x = sin(phiRadian);
        orientation.y = cos(phiRadian) * cos(thetaRadian);
        orientation.z = cos(phiRadian) * sin(thetaRadian);
    }


    // Si c'est l'axe Y

    else if(Vaxe.y == 1.0)
    {
        // Calcul des coordonnées sphériques

         orientation.x = cos(phiRadian) * sin(thetaRadian);
         orientation.y = sin(phiRadian);
         orientation.z = cos(phiRadian) * cos(thetaRadian);
    }


    // Sinon c'est l'axe Z

    else
    {
        // Calcul des coordonnées sphériques

        orientation.x = cos(phiRadian) * cos(thetaRadian);
        orientation.y = cos(phiRadian) * sin(thetaRadian);
        orientation.z = sin(phiRadian);
    }


    // Calcul de la normale

    deplacementLateral = Vaxe.crossProduct(orientation);
    deplacementLateral.normalize();


    // Calcul du point ciblé pour OpenGL

    target = position + orientation;
}


void Camera::moveForward(float speed)
{
    position = position + orientation * speed;
    target = position + orientation;
}

void Camera::moveBackward(float speed)
{
    position = position - orientation * speed;
    target = position + orientation;
}

void Camera::moveLeftSide(float speed)
{
    position = position + deplacementLateral * speed;
    target = position + orientation;
}

void Camera::moveRightSide(float speed)
{
    position = position - deplacementLateral * speed;
    target = position + orientation;
}
