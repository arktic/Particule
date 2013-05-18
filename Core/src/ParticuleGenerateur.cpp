
#include "ParticuleGenerateur.h"

#include "Particule.h"
#include "Vectors.h"

/*
ParticuleGenerateur::ParticuleGenerateur() :
    ParticuleGenerateur(DEFAULT_RADIUS, DEFAULT_CENTER, DEFAULT_NB_ITEM,
        (float) DEFAULT_LIFETIME_MIN, (float) DEFAULT_LIFETIME_MAX, (float) DEFAULT_SIZE_MIN,
        (float) DEFAULT_SIZE_MAX)
{

}*/


ParticuleGenerateur::ParticuleGenerateur
(  float _radius     ,  Vec3i _center , int _nbItem  , float _lifeTimeMin,
   float _lifeTimeMax,  float _sizeMin, float _sizeMax
 ):
        radius(_radius),
        center(_center),
        nbItem(_nbItem),
        lifeTimeMin(_lifeTimeMin),
        lifeTimeMax(_lifeTimeMax),
        nbAlive(),
        sizeMin(_sizeMin),
        sizeMax(_sizeMax),
        alive(_nbItem,(Particule*)NULL)
{
    //particles();
	//particles.reserve(nbItem);
}


ParticuleGenerateur::~ParticuleGenerateur() {
}



