class Particule {
protected:
	float lifeTime;
	float age;
	int size;
	vec3 position;
	vec3 speed;
public:
	Particule();
	Particule(int lifeTime, int size, vec3 pos, vec3 speed);

	void Render();
	bool isALive();
	float getAge() const;
	void setAge(float age);
	float getLifeTime() const;
	void setLifeTime(float lifeTime);
	vec3 getPosition() const;
	void setPosition(vec3 position);
	int getSize() const;
	void setSize(int size);
	vec3 getSpeed() const;
	void setSpeed(vec3 speed);
};
