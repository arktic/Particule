#ifndef FIRE_H
#define FIRE_H

#include "ParticuleGenerateur.h"
#include "App.h"

#define FIRE_FRAMETIME 33
#define FIRE_ITEMPERFRAME 1000
#define FIRE_NBPARTICLE 9000

#define FIRE_LIFETIME_MIN 1000
#define FIRE_LIFETIME_MAX 3000

#define FIRE_SIZE_MIN 2
#define FIRE_SIZE_MAX 4

#define FIRE_VELOCITY_MIN 1
#define FIRE_VELOCITY_MAX 3

#define FIRE_RADIUS 4
#define FIRE_CENTER Vec3(0,0,0)

class App;
class Fire : public ParticuleGenerateur
{
private:
    GLuint shaderID;
    GLuint textureID;

    /* variable shader */
    GLint   t             ;
    GLint   ivelocity     ;
    GLint   ageRatio      ;
    GLint   position      ;
    GLint   size          ;

    /* variable uniforme */
    Vec3    camPos        ;
    GLint   mvp           ;
    GLint   c             ;
    GLint   radius        ;
    GLint   eyePosition   ;
    GLint   viewport[4]   ;
    GLint   viewportWidth ;

    /* détermine le coéficient appliqué à l'atténuation de l'age (pour les bords) en plus de l'atténuation linéaire */
    float ageAtenuationFactor;

    /* détermine la limite de début de l'aténuation de l'age par rapport au centre du feu (en pourcentage) */
    float ageAtenuationLimit;

    void fillRandomParticule(Particule* pt);

public:
    Fire(char* _shaderName, char* _textureName, float _frameTime, int _nbItemPerFrame, float _radius,
               Vec3 _center, int _nbItem, float _lifeTimeMin, float _lifeTimeMax,
               float _sizeMin, float _sizeMax, float _velocityMin, float _velocityMax);
    ~Fire();

    void setAtenuation(float _ageAtenuationFactor, float _ageAtenuationLimit );
    void setAtenuationFactor(float _ageAtenuationFactor ) { ageAtenuationFactor = _ageAtenuationFactor ;}
    void setAtenuationLimit(float _ageAtenuationLimit ) { ageAtenuationLimit = _ageAtenuationLimit ;}

    float getAgeAtenuationFactor() { return ageAtenuationFactor;}
    float getAgeAtenuationLimit() { return ageAtenuationLimit;}

    void load(App *app);
    void unload(App *app);
    void render(App *app);
    void fillCGA(int &i, vector<Particule*>::iterator &it);
};

#endif // FIRE_H
