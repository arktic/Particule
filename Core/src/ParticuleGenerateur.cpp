
#include "ParticuleGenerateur.h"
#include "Particule.h"
#include "Vectors.h"
#include "utils.h"


#include <vector>
#include <stdlib.h>
#include <cmath>
#include <iostream>





ParticuleGenerateur::ParticuleGenerateur
( float _frameTime, int _nbItemPerFrame, float _radius     ,  Vec3 _center , int _nbItem  , float _lifeTimeMin,
   float _lifeTimeMax,  float _sizeMin, float _sizeMax, float _velocityMin, float _velocityMax
 ):
        lastFrameTime(0),
        frameTime(_frameTime),
        nbItemPerFrame(_nbItemPerFrame),
        radius(_radius),
        center(_center),
        nbItem(_nbItem),
        nbAlive(),
        lifeTimeMin(_lifeTimeMin),
        lifeTimeMax(_lifeTimeMax),
        velocityMin(_velocityMin),
        velocityMax(_velocityMax),
        sizeMin(_sizeMin),
        sizeMax(_sizeMax),
        alive(),
        dead()
{

    for(int i =0 ; i <nbItem ; i++){
        Particule* pt = new Particule();
        dead.push_back(pt);
    }
}


ParticuleGenerateur::~ParticuleGenerateur() {
    for(vector<Particule*>::iterator it = dead.begin(); it < dead.end(); ++it){
        delete (*it);
        *it = NULL;
    }
    for(vector<Particule*>::iterator it = alive.begin(); it < alive.end(); ++it){
        delete (*it);
        *it = NULL;
    }
}

void ParticuleGenerateur::update() {

    int64_t tMs;
    time_ms(&tMs);
    int elapsedTime = tMs - lastFrameTime;
    if( elapsedTime >  frameTime) {
        int i=0;
        for(vector<Particule*>::iterator it = alive.begin(); it  < alive.end(); ++it) {
            (*it)->live(elapsedTime);
            std::cout << "age of " << i << ": " << (*it)->getAge() << "  max: " << (*it)->getLifeTime() << std::endl;
            if(!(*it)->isAlive()) {
                dead.push_back(*it);
                alive.erase(it);
            }
            i++;
        }

        std::cout << "elapsedTime: " << elapsedTime <<std::endl;
        int nbPtcBroughtBackToLife = 0;
        while(dead.size() > 0 && nbPtcBroughtBackToLife < nbItemPerFrame) {
            Particule* pt = dead.back();
            dead.pop_back();

            pt->set(getRandomLifeTime(),getRandomSize(), getRandomPosition(), getRandomVelocity()); // age is set to 0 by default
            alive.push_back(pt);

            nbPtcBroughtBackToLife++;
        }


        lastFrameTime = tMs;
    }



    return;
}


Vec3 ParticuleGenerateur::getRandomPosition() {
    float angle = getBoundedRandom(0,M_PI * 2);
    float rayon = (rand()/RAND_MAX) * radius;
    Vec3 v(cos(angle) * rayon, 0, sin(angle) * rayon);
    return v;
}


Vec3 ParticuleGenerateur::getRandomVelocity() {
    Vec3 v(0,1,0);
    v*=getBoundedRandom(velocityMin, velocityMax);
    return v;
}



float ParticuleGenerateur::getRandomLifeTime() {
    return getBoundedRandom(lifeTimeMin,lifeTimeMax);
}

float ParticuleGenerateur::getRandomSize() {
    return getBoundedRandom(sizeMin,sizeMax);
}




