#include "fire.h"
#include <iostream>

Fire::Fire
    (
        char* _shaderName   , float _frameTime  , int _nbItemPerFrame   , float _radius,
        Vec3 _center        , int _nbItem       , float _lifeTimeMin    , float _lifeTimeMax,
        float _sizeMin      , float _sizeMax    , float _velocityMin    , float _velocityMax
    ):
    ParticuleGenerateur
        (
            _shaderName     ,_frameTime     , _nbItemPerFrame       , _radius,
            _center         ,_nbItem        , _lifeTimeMin          , _lifeTimeMax,
            _sizeMin        ,_sizeMax       , _velocityMin          , _velocityMax
        )
{
    ageAtenuationFactor = 0.65;
    ageAtenuationLimit = 0.35;
}

void Fire::fillRandomParticule(Particule* pt) {
    Vec3 pos = getRandomPosition();
    Vec3 c_to_pos = getCenter()-pos;
    float lifeTime = getRandomLifeTime();
    float dcenter = c_to_pos.length();
    if(dcenter > ageAtenuationLimit*getRadius() && dcenter > 1)
        lifeTime = lifeTime* (getRadius()/dcenter)*ageAtenuationFactor;

    pt->set(lifeTime,getRandomSize(),pos , getRandomVelocity(),0); // age is set to 0 by default
}

void Fire::setAtenuation(float _ageAtenuationFactor, float _ageAtenuationLimit ){
    ageAtenuationFactor = _ageAtenuationFactor;
    ageAtenuationLimit = _ageAtenuationLimit;
}
