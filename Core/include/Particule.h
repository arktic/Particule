#ifndef _PARTICULE_H_
#define _PARTICULE_H_

#include "Vectors.h"

/* Cette classe repésente une particule */

class Particule {
protected:
	// durée de vie de cette particule. i.e. âge maximum avant sa mort
	float lifeTime;
	// âge de la particule
    int age;
	//taille de la particule
	int size;
	Vec3 position;
	Vec3 velocity;
public:
	Particule();
	Particule(float lifeTime, int size, Vec3 pos, Vec3 velocity);

	void Render();
	
	/* Renvoie vrai si cette particule est en vie 
		(i.e. que son âge n'a pas encore atteint son lifeTime) */
    bool isAlive();

	/* getters & setters */
    int getAge() const;
    void setAge(int age);
	float getLifeTime() const;
	void setLifeTime(float lifeTime);
	Vec3 getPosition() const;
	void setPosition(Vec3 position);
    float getSize() const;
	void setSize(int size);
	Vec3 getVelocity() const;
	void setVelocity(Vec3 velocity);
    void live(int elapsedTime);

    void set(float _lifeTime, int _size, Vec3 _pos, Vec3 _velocity, int _age= 0);
};

#endif