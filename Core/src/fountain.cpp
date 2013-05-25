
#include "fountain.h"
#include "utils.h"

Fountain::Fountain(
    char* _shaderName   , char* _textureName, int64_t _frameTime  , int _nbItemPerFrame   , float _radius,
    Vec3 _center        , int _nbItem       , float _lifeTimeMin    , float _lifeTimeMax,
    float _sizeMin      , float _sizeMax    , float _velocityMin    , float _velocityMax, Vec3 _direction
):
ParticuleGenerateur
    (
        _shaderName     , _textureName, _frameTime     , _nbItemPerFrame       , _radius,
        _center         ,_nbItem        , _lifeTimeMin          , _lifeTimeMax,
        _sizeMin        ,_sizeMax       , _velocityMin          , _velocityMax
        ), direction(_direction)
{
}



Vec3
Fountain::getRandomVelocity() {
    return Vec3(direction)* getBoundedRandom(velocityMin, velocityMax);
}




