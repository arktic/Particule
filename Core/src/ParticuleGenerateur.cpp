
#include "ParticuleGenerateur.h"
#include "Particule.h"
#include "Vectors.h"
#include "utils.h"


#include <vector>
#include <stdlib.h>
#include <cmath>
#include <iostream>
#include "GlFramework.h"
#include "GlWindow.h"
#include <GL/glew.h>
using namespace std;


ParticuleGenerateur::ParticuleGenerateur
( char* _shaderName, char* _textureName, int64_t _frameTime, int _nbItemPerFrame, float _radius     ,  Vec3 _center , int _nbItem  , float _lifeTimeMin,
   float _lifeTimeMax,  float _sizeMin, float _sizeMax, float _velocityMin, float _velocityMax
 ):
        lastFrameTime(0),
        frameTime(_frameTime),
        nbItemPerFrame(_nbItemPerFrame),
        radius(_radius),
        center(_center),
        nbItem(_nbItem),
        nbAlive(0),
        lifeTimeMin(_lifeTimeMin),
        lifeTimeMax(_lifeTimeMax),
        velocityMin(_velocityMin),
        velocityMax(_velocityMax),
        sizeMin(_sizeMin),
        sizeMax(_sizeMax),
        alive(),
        dead()
{
    shaderName = _shaderName;
    textureName = _textureName;
    vertices = new GLfloat[3*nbItem];
    velocity = new GLfloat[3*nbItem];
    colors = new GLfloat[4*nbItem];
    ages = new GLfloat[nbItem];
    agesRatio = new GLfloat[nbItem];
    sizes = new GLfloat[nbItem];

    elapsedTime = 0;
    time_ms(&lastFrameTime);

    for(int i =0 ; i <nbItem ; i++){
        Particule* pt = new Particule();
        dead.push_back(pt);
        colors[3*i] = 1;//((float)rand())/RAND_MAX;
        colors[3*i +1 ] = 1;// ((float)rand())/RAND_MAX;
        colors[3*i +2 ] = 1;// ((float)rand())/RAND_MAX;
        colors[3*i +3 ] = 1;
        ages[i] = 0;
        agesRatio[i] = 0;
        sizes[i] = 0;
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
    delete vertices;
    delete velocity;
    delete colors;
    delete ages;
    delete agesRatio;
    delete sizes;
}

void ParticuleGenerateur::update() {

    int64_t tMs;
    time_ms(&tMs);
    elapsedTime = tMs - lastFrameTime;

    if( elapsedTime >  frameTime) {
        updateParticle(elapsedTime);
        addParticle();

        lastFrameTime = tMs;
    }
}


Vec3 ParticuleGenerateur::getRandomPosition() {
    float angle = getBoundedRandom((float) 0, (float) M_PI*2);
    float rayon = ( ((float)rand())/RAND_MAX) * radius;
    Vec3 v(cos(angle) * rayon, 0, sin(angle) * rayon);
    v += center;
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
    return getBoundedRandom((float)sizeMin,(float)sizeMax);
}

void ParticuleGenerateur::fillCGA(int &i,vector<Particule*>::iterator &it){
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


void ParticuleGenerateur::fillRandomParticule(Particule* pt){
    pt->set(getRandomLifeTime(),getRandomSize(),getRandomPosition(),getRandomVelocity(),0);
}

void ParticuleGenerateur::addParticle(){
    int nbPtcBroughtBackToLife = 0;
    while(dead.size() > 0 && nbPtcBroughtBackToLife < nbItemPerFrame) {
        Particule* pt = dead.back();
        dead.pop_back();
        fillRandomParticule(pt);
        alive.push_back(pt);
        nbAlive++;
        nbPtcBroughtBackToLife++;
    }
}

void ParticuleGenerateur::updateParticle(int &elapsedTime){
    int i=0;
    for(vector<Particule*>::iterator it = alive.begin(); it  < alive.end(); ++it) {
        (*it)->live(elapsedTime);

        if(!(*it)->isAlive()) {
            dead.push_back(*it);
            alive.erase(it);
            nbAlive--;
        }
        else {
            fillCGA(i,it);
        }
        i++;
    }
}
