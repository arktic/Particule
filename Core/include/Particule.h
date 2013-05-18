#ifndef _PARTICULE_H_
#define _PARTICULE_H_

#include "Vectors.h"

/* Cette classe repésente une particule */

class Particule {
protected:
	// durée de vie de cette particule. i.e. âge maximum avant sa mort
	float lifeTime;
	// âge de la particule
	float age;
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
	bool isALive();

	/* getters & setters */
	float getAge() const;
	void setAge(float age);
	float getLifeTime() const;
	void setLifeTime(float lifeTime);
	Vec3 getPosition() const;
	void setPosition(Vec3 position);
	int getSize() const;
	void setSize(int size);
	Vec3 getVelocity() const;
	void setVelocity(Vec3 velocity);
};

#endif