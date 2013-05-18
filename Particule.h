class Particule {
protected:
	int lifeTime;
	int age;
	int size;
	vec3 position;
	vec3 speed;
public:
	Particule();
	Particule(int lifeTime, int size, vec3 pos, vec3 speed);

	void Render();
	bool isALive();
	int getAge() const;
	void setAge(int age);
	int getLifeTime() const;
	void setLifeTime(int lifeTime);
	vec3 getPosition() const;
	void setPosition(vec3 position);
	int getSize() const;
	void setSize(int size);
	vec3 getSpeed() const;
	void setSpeed(vec3 speed);
};
