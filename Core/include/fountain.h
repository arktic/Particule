#ifndef FOUNTAIN_H
#define FOUNTAIN_H



#include "ParticuleGenerateur.h"
#include "Vectors.h"
#include "App.h"

#define FOUNTAIN_FRAMETIME 33
#define FOUNTAIN_ITEMPERFRAME 100
#define FOUNTAIN_NBPARTICLE 20000

#define FOUNTAIN_LIFETIME_MIN 1000
#define FOUNTAIN_LIFETIME_MAX 3000

#define FOUNTAIN_SIZE_MIN 10
#define FOUNTAIN_SIZE_MAX 10

#define FOUNTAIN_VELOCITY_MIN 10
#define FOUNTAIN_VELOCITY_MAX 10

#define FOUNTAIN_RADIUS 1
#define FOUNTAIN_CENTER Vec3(0,0,0)

#define FOUNTAIN_DIRECTION Vec3(0,1,1)

class App;
class Fountain : public ParticuleGenerateur {

private:
    GLuint shaderID;
    GLuint textureID;

    /* variables shader uniformes */
    GLint mvp           ;
    GLint eyePosition   ;
    GLint viewportWidth ;
    GLint viewport[4]   ;
    Vec3  camPos;

    /* variables shaders */
    GLint t             ;
    GLint ivelocity     ;
    GLint position      ;
    GLint size          ;

    Vec3 direction;

    Vec3 getRandomVelocity();

public:
    Fountain( char* _shaderName, char* _textureName, int64_t _frameTime, int _nbItemPerFrame, float _radius     ,  Vec3 _center , int _nbItem  , float _lifeTimeMin,
       float _lifeTimeMax,  float _sizeMin, float _sizeMax, float _velocityMin, float _velocityMax,
     Vec3 _direction);

    Vec3 getDirection() { return direction; }
    void setDirection(Vec3 dir) { direction = dir; }

    void load(App* app);
    void unload(App* app);
    void render(App *app);

};

#endif // FOUNTAIN_H
