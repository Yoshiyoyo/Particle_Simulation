#pragma once
#include <ParticleSystem.h>
#include <Windows.h>
#include <math.h>
ParticleSystem::ParticleSystem(QWidget *parent):QObject()
{
	srand(2343);
}
void ParticleSystem::ParticleButton()
{
	
	//vertices = new float[12 * 10];
	float m = rand()%10;
	DynamicParticle* a = new DynamicParticle(mass, mass*2, rand() % 120 - 60, rand() % 80 - 40);

	particles.push_front((Particle*)a);
	dynamicParticles.push_front(a);
	//DynamicParticle* b = new DynamicParticle(1.f, 5.f, 10.f, 10.f);
	//particles.push_front(*b);
}
void ParticleSystem::AttractorButton()
{
	Attractor* a = new Attractor(mass, mass * 2, rand() % 120 - 60, rand() % 80 - 40);

	particles.push_front((Particle*)a);
	attractors.push_front(a);

}
void ParticleSystem::RepulsorButton()
{
	Attractor* a = new Attractor(-mass, mass * 2, rand() % 120-60, rand() % 80 - 40);

	particles.push_front((Particle*)a);
	attractors.push_front(a);
}
void ParticleSystem::ClearButton()
{
	for (std::list<Particle*>::iterator it = particles.begin(); it != particles.end(); ++it)
	{
		delete *it;
	}
	particles.clear();
	attractors.clear();
	dynamicParticles.clear();
	generators.clear();

}

void ParticleSystem::GeneratorButton()
{
	Generator* a = new Generator(mass, mass * 2, rand() % 120-60, rand() % 80 - 40, .8, rand() % 2-1, rand() % 2 -1);

	particles.push_front((Particle*)a);
	generators.push_front(a);
}

void ParticleSystem::ChangeMass(int a)
{
	//ClearButton();
	mass =(float)a;
	//friction = 1-a/100.f;
}

float* ParticleSystem::getVertices()
{
	//float xTemp, yTemp, radTemp, xPlusR, xMinusR, yPlusR, yMinusR;
	float xTemp, yTemp;
	//Particle tempParticle;
	delete vertices;
	vertices = new float[particles.size()*2];

	


	int i = 0;
	for (std::list<Particle*>::iterator it = particles.begin(); it != particles.end(); ++it)
	{
		
		xTemp = (*it)->xPos;
		yTemp = (*it)->yPos;
		vertices[2 * i] = xTemp;
		vertices[2 * i + 1] = yTemp;
		/*radTemp = it->radius;

		xPlusR = xTemp + radTemp;
		xMinusR = xTemp - radTemp;

		yPlusR = yTemp + radTemp;
		yMinusR = yTemp - radTemp;


		//tempParticle = particles.;
		vertices[12* i] = xPlusR;
		vertices[12 * i + 1] = yPlusR;

		vertices[12 * i + 2] = xPlusR;
		vertices[12 * i + 3] = yMinusR;

		vertices[12 * i + 4] = xMinusR;
		vertices[12 * i + 5] = yMinusR;; //first triangle

		vertices[12 * i + 6] = xPlusR;
		vertices[12 * i + 7] = yPlusR;

		vertices[12 * i + 8] = xMinusR;
		vertices[12 * i + 9] = yMinusR;

		vertices[12 * i + 10] = xMinusR;
		vertices[12 * i + 11] = yPlusR;*/
		//particles.s
		i++;
	}
	return vertices;
}
float* ParticleSystem::getRadii()
{
	float* radii = new float[1 * particles.size()];
	int i = 0;
	for (std::list<Particle*>::iterator it = particles.begin(); it != particles.end(); ++it)
	{
		radii[i] = (*it)->radius;
		i++;
	}
	return radii;
	
}

float* ParticleSystem::getColors()
{
	float* colors = new float[3 * particles.size()];
	int i = 0;
	for (std::list<Particle*>::iterator it = particles.begin(); it != particles.end(); ++it){
		colors[3*i] = (*it)->RGB[0];
		colors[3*i+1] = (*it)->RGB[1];
		colors[3*i+2] = (*it)->RGB[2];
		i++;
	}
	return colors;

}
void ParticleSystem::PerformPhysics()
{
	LARGE_INTEGER frequency;        // ticks per second
	LARGE_INTEGER t2;         // ticks
	double elapsedTime;
	float temp;
	
	// get ticks per second
	QueryPerformanceFrequency(&frequency);

	// start timer
	QueryPerformanceCounter(&t2);

	// compute and print the elapsed time in millisec
	elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;


	float deltaX, deltaY, r;

	for (std::list<DynamicParticle*>::iterator particle = dynamicParticles.begin(); particle != dynamicParticles.end(); ++particle){
		for (std::list<Attractor*>::iterator attractor = attractors.begin(); attractor != attractors.end(); ++attractor) {
			deltaX = -((*particle)->xPos - (*attractor)->xPos);
			deltaY = -((*particle)->yPos - (*attractor)->yPos);
			r = sqrt(pow(deltaX, 2) + pow(deltaY, 2));



			if (r > 2) {
				(*particle)->xVel += (6.67 / 10 * (*attractor)->mass) / (pow(r, 2)) / elapsedTime * (deltaX / r)+ (6.67 / 10* (*particle)->mass) / (pow(r, 2)) / elapsedTime * (deltaX / r);
				(*particle)->yVel += (6.67 / 10 * (*attractor)->mass) / (pow(r, 2)) / elapsedTime * (deltaY / r)+ (6.67 / 10 * (*particle)->mass) / (pow(r, 2)) / elapsedTime * (deltaY / r);;
			}
		}
		(*particle)->xVel *= friction;
		(*particle)->yVel *= friction;
		(*particle)->xPos += (*particle)->xVel/elapsedTime;
		(*particle)->yPos += (*particle)->yVel/elapsedTime;
	}
	for (std::list<Generator*>::iterator generator = generators.begin(); generator != generators.end(); ++generator) {
		temp = (*generator)->generationFrequency / elapsedTime;
		if (rand() %100 < temp) {
			DynamicParticle *a = new DynamicParticle((*generator)->mass, (*generator)->mass * 2, (*generator)->xPos + (*generator)->xOffset, (*generator)->yPos + (*generator)->yOffset);
			a->xVel = (*generator)->initialParticleVelocityX;
			a->yVel = (*generator)->initialParticleVelocityY;
			particles.push_front(a);
			dynamicParticles.push_front(a);

		}


	}
	t1 = t2;
}
