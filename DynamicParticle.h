#pragma once
#include <Particle.h>
class DynamicParticle :public Particle
{
public:
	DynamicParticle::DynamicParticle(float m, float r, float xPosition, float yPosition)
	{
		mass = m;
		radius = r;
		xPos = xPosition;
		yPos = yPosition;
		xVel = 0.f;
		yVel = 0.f;
	}
	float xVel, yVel;
};
