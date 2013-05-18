/* Cette classe repésente une particule */

class Particule {
protected:
	// durée de vie de cette particule. i.e. âge maximum avant sa mort
	float lifeTime;
	// âge de la particule
	float age;
	//taille de la particule
	int size;
	vec3 position;
	vec3 velocity;
public:
	Particule();
	Particule(float lifeTime, int size, vec3 pos, vec3 velocity);

	void Render();
	
	/* Renvoie vrai si cette particule est en vie 
		(i.e. que son âge n'a pas encore atteint son lifeTime) */
	bool isALive();

	/* getters & setters */
	float getAge() const;
	void setAge(float age);
	float getLifeTime() const;
	void setLifeTime(float lifeTime);
	vec3 getPosition() const;
	void setPosition(vec3 position);
	int getSize() const;
	void setSize(int size);
	vec3 getVelocity() const;
	void setVelocity(vec3 velocity);
};
