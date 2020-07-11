#pragma once
#include "iostream"
#include <qobject.h>
#include <fstream>
#include <DynamicParticle.h>
#include <Attractor.h>
#include <Generator.h>
#include <list>
#include <cstdlib>
class  ParticleSystem :public QObject
{
	Q_OBJECT
public:
	float mass = 5.f;
	float friction = .99999;
	LARGE_INTEGER t1 = LARGE_INTEGER();
	std::list<Particle*> particles;
	float *vertices = nullptr;
	std::list<DynamicParticle*> dynamicParticles;
	std::list<Attractor*> attractors;
	std::list<Generator*> generators;
	explicit ParticleSystem(QWidget *parent = 0);
	std::list<Particle*> getParticles() {return particles;}
	float* getVertices();
	float* ParticleSystem::getRadii();
	float* ParticleSystem::getColors();
	void PerformPhysics();

public slots:
	void addParticle(){
	}
	void ClearButton();
	void AttractorButton();
	void RepulsorButton();
	void ParticleButton();
	void GeneratorButton();
	void ChangeMass(int a);





};