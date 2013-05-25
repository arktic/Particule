
#include "smoke.h"
#include <iostream>
#include "utils.h"

Smoke::Smoke
    (char* _shaderName   , char* _textureName,  float _frameTime  , float _radius,
        Vec3 _center        , int _nbItem       , float _lifeTimeMin    , float _lifeTimeMax,
        float _sizeMin      , float _sizeMax    , float _velocityMin    , float _velocityMax,
        float _sizeMaxCoef
    , int _itemPerFrameMax, int _itemPerFrameMin, int _updateNbItemTimer, int _nbItemPerFrame   ):
    ParticuleGenerateur
        (
            _shaderName     , _textureName , _frameTime     , _nbItemPerFrame       , _radius,
            _center         ,_nbItem        , _lifeTimeMin          , _lifeTimeMax,
            _sizeMin        ,_sizeMax       , _velocityMin          , _velocityMax
        )
{
    sizeMaxCoef = _sizeMaxCoef;
    itemPerFrameMax = _itemPerFrameMax;
    itemPerFrameMin = _itemPerFrameMin;

    lastUpdateNbItem = 0;
    updateNbItemTimer = _updateNbItemTimer;
    nbItemPerFrame = getRandomItemPerFrame();
}

void Smoke::fillCGA(int &i, vector<Particule*>::iterator &it)
{
    Vec3 pos = (*it)->getPosition();
    vertices[3*i  ]   = pos.x;
    vertices[3*i+1] = pos.y;
    vertices[3*i+2] = pos.z;

    pos = (*it)->getVelocity();

    velocity[3*i]   = pos.x;
    velocity[3*i+1] = pos.y;
    velocity[3*i+2] = pos.z;

    agesRatio[i] = (*it)->getAge()/((*it)->getLifeTime());
    ages[i] = (*it)->getAge();
    sizes[i] = (float)(*it)->getSize();
}

void Smoke::addParticle(){
    int nbPtcBroughtBackToLife = 0;
    lastUpdateNbItem += elapsedTime;
    if(lastUpdateNbItem > updateNbItemTimer)
    {
        nbItemPerFrame = getRandomItemPerFrame();
        lastUpdateNbItem = 0;

    while(dead.size() > 0 && nbPtcBroughtBackToLife < nbItemPerFrame) {
        Particule* pt = dead.back();
        dead.pop_back();
        fillRandomParticule(pt);
        alive.push_back(pt);
        nbAlive++;
        nbPtcBroughtBackToLife++;
    }
    }
}

int Smoke::getRandomItemPerFrame() {
    return getBoundedRandom(itemPerFrameMin, itemPerFrameMax);
}

void Smoke::fillRandomParticule(Particule* pt){
    pt->set(getRandomLifeTime(),radius*5,getRandomCenteredPosition(),getRandomVelocity(),0);
}

Vec3 Smoke::getRandomCenteredPosition() {
    Vec3 out;
    out.x = getBoundedRandom(center.x-2, center.x+2);
    out.y = getBoundedRandom(center.y, center.y);
    out.z = getBoundedRandom(center.z-2, center.z+2);
    return out;
}
