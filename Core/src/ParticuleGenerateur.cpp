
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
    vertices = new GLfloat[3*nbItem];
    velocity = new GLfloat[3*nbItem];
    colors = new GLfloat[3*nbItem];
    ages = new GLfloat[nbItem];
    agesRatio = new GLfloat[nbItem];
    sizes = new GLfloat[nbItem];

    for(int i =0 ; i <nbItem ; i++){
        Particule* pt = new Particule();
        dead.push_back(pt);
        colors[3*i] = 1;//((float)rand())/RAND_MAX;
        colors[3*i +1 ] = 1;// ((float)rand())/RAND_MAX;
        colors[3*i +2 ] = 1;// ((float)rand())/RAND_MAX;
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
    int elapsedTime = tMs - lastFrameTime;
    if( elapsedTime >  frameTime) {
        //std::cout << "FT: " << frameTime << "--eslpasedTIme:  "<< elapsedTime << std::endl;
        int i=0;
        for(vector<Particule*>::iterator it = alive.begin(); it  < alive.end(); ++it) {
            (*it)->live(elapsedTime);
            //std::cout << "age of " << i << ": " << (*it)->getAge() << "  max: " << (*it)->getLifeTime() << std::endl;
            if(!(*it)->isAlive()) {
                dead.push_back(*it);
                alive.erase(it);
                nbAlive--;
            }
            else {
                Vec3 pos = (*it)->getPosition();
                vertices[3*i]   = pos.x;
                vertices[3*i+1] = pos.y;
                vertices[3*i+2] = pos.z;
             //   std::cout << "adding  " << i << ": " << pos.x << "," << pos.y << "," << pos.z << std::endl;

                pos = (*it)->getVelocity();

                velocity[3*i]   = pos.x;
                velocity[3*i+1] = pos.y;
                velocity[3*i+2] = pos.z;

                agesRatio[i] = (*it)->getAge()/((*it)->getLifeTime());
                ages[i] = (*it)->getAge();
                sizes[i] = (float)(*it)->getSize();
            }
            i++;
        }

       // std::cout << "elapsedTime: " << elapsedTime <<std::endl;
        int nbPtcBroughtBackToLife = 0;
        while(dead.size() > 0 && nbPtcBroughtBackToLife < nbItemPerFrame) {
            Particule* pt = dead.back();
            dead.pop_back();
            Vec3 pos = getRandomPosition();
            Vec3 c_to_pos = center-pos;
            float lifeTime = getRandomLifeTime();
            float dcenter = c_to_pos.length();
            if(dcenter > 0.35*radius && dcenter > 1)
                lifeTime = lifeTime* (radius/dcenter)*0.65;
            pt->set(lifeTime,getRandomSize(),pos , getRandomVelocity(),0); // age is set to 0 by default
            alive.push_back(pt);
            nbAlive++;

            nbPtcBroughtBackToLife++;
        }

        lastFrameTime = tMs;
    }



    return;
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


GLfloat* ParticuleGenerateur::getVertices(){
    return vertices;
}

int ParticuleGenerateur::getNbAlive(){
    return nbAlive;
}
GLfloat* ParticuleGenerateur::getVelocity(){
    return velocity;
}

GLfloat* ParticuleGenerateur::getColors(){
    return colors;
}

GLfloat* ParticuleGenerateur::getAgesRatio(){
    return agesRatio;
}

GLfloat* ParticuleGenerateur::getAges(){
    return ages;
}

GLfloat* ParticuleGenerateur::getSizes(){
    return sizes;
}

Vec3 ParticuleGenerateur::getCenter(){
    return center;
}

GLfloat ParticuleGenerateur::getRadius() {
    return radius;
}
