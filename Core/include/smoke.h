#ifndef SMOKE_H
#define SMOKE_H

#define SMOKE_FRAMETIME 33

#define SMOKE_GENTIME 400

#define SMOKE_NBPARTICLE 1000
#define SMOKE_LIFETIME_MIN 10000
#define SMOKE_LIFETIME_MAX 20000

#define SMOKE_SIZE_MIN 2
#define SMOKE_SIZE_MAX 3
#define SMOKE_VELOCITY_MIN 2
#define SMOKE_VELOCITY_MAX 2

#define SMOKE_RADIUS 2
#define SMOKE_CENTER Vec3(0,0,0)
#define SMOKE_SIZE_COEF 3

#define SMOKE_FRAME_MIN 10
#define SMOKE_FRAME_MAX 60
#define SMOKE_TEXTURE "Texture/tex2d_smoke.png"


#include "ParticuleGenerateur.h"
#include "App.h"

class App;
class Smoke : public ParticuleGenerateur
{
private:
    GLuint shaderID;
    GLuint textureID;

    float sizeMaxCoef;
    int itemPerFrameMax;
    int itemPerFrameMin;
    int updateNbItemTimer;
    int lastUpdateNbItem;

    void fillCGA(int &i, vector<Particule*>::iterator &it);
    void addParticle();
    void fillRandomParticule(Particule* pt);
    Vec3 getRandomCenteredPosition();
public:
    Smoke(char* _shaderName, char* _textureName, float _frameTime, float _radius,
               Vec3 _center, int _nbItem, float _lifeTimeMin, float _lifeTimeMax,
               float _sizeMin, float _sizeMax, float _velocityMin, float _velocityMax,
               float _sizeMaxCoef, int itemPerFrameMax,int itemPerFrameMin, int _updateNbItemTimer,
               int _nbItemPerFrame = 0
          );

    float getSizeMaxCoef() { return sizeMaxCoef; }
    void setSizeMaxCoef(float coef) { sizeMaxCoef = coef; }
    int getRandomItemPerFrame();

    void load(App* app);
    void unload(App* app);
    void render(App *app);

};



#endif // SMOKE_H
