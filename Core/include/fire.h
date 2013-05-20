#ifndef FIRE_H
#define FIRE_H

#include "ParticuleGenerateur.h"
class Fire : public ParticuleGenerateur
{
private:
    void fillRandomParticule(Particule* pt);

    /* détermine le coéficient appliqué à l'atténuation de l'age (pour les bords) en plus de l'atténuation linéaire */
    float ageAtenuationFactor;

    /* détermine la limite de début de l'aténuation de l'age par rapport au centre du feu (en pourcentage) */
    float ageAtenuationLimit;
public:
    Fire(char* _shaderName, float _frameTime, int _nbItemPerFrame, float _radius,
               Vec3 _center, int _nbItem, float _lifeTimeMin, float _lifeTimeMax,
               float _sizeMin, float _sizeMax, float _velocityMin, float _velocityMax);
    void setAtenuation(float _ageAtenuationFactor, float _ageAtenuationLimit );
};

#endif // FIRE_H
