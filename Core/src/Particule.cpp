#include "Particule.h"

#include "Vectors.h"

#include "iostream"

Particule::Particule() : lifeTime(), age(), size(), position(), velocity() {
}


Particule::Particule(float LifeTime, int Size, Vec3 pos, Vec3 Velocity) : 
lifeTime(LifeTime), age(), size(Size), position(pos), velocity(Velocity)
{
}


int Particule::getAge() const {
	return age;
}

void Particule::setAge(int age) {
	this->age = age;
}

float Particule::getLifeTime() const {
	return lifeTime;
}

void Particule::setLifeTime(float lifeTime) {
	this->lifeTime = lifeTime;
}

Vec3 Particule::getPosition() const {
	return position;
}

void Particule::setPosition(Vec3 position) {
	this->position = position;
}

int Particule::getSize() const {
	return size;
}

void Particule::setSize(int size) {
	this->size = size;
}

Vec3 Particule::getVelocity() const {
	return velocity;
}

void Particule::setVelocity(Vec3 velocity) {
	this->velocity = velocity;
}

bool Particule::isAlive() {
    return age <= lifeTime;
}


void Particule::set(float lifeTime, int size, Vec3 pos, Vec3 velocity, int _age) {
    setLifeTime(lifeTime);
    setSize(size);
    setPosition(pos);
    setVelocity(velocity);
    age=_age;
}


void Particule::live(int elapsedTime) {
    setAge(getAge() + elapsedTime);
}


