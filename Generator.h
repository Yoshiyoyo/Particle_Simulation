#pragma once
#include <Particle.h>
class Generator :public Particle
{
public:
	Generator::Generator(float m, float r, float xPosition, float yPosition, float genFreq, float partVelX,float partVelY)
	{

		mass = m;
		radius = r;
		xPos = xPosition;
		yPos = yPosition;
		RGB[0] = 0.f;
		RGB[1] = 1.f;
		RGB[2] = 1.f;
		generationFrequency = genFreq;
		
		
		if (partVelX == 0)
			initialParticleVelocityX = 1;
		else
			initialParticleVelocityX = partVelX;
		if (partVelY == 0)
			initialParticleVelocityY = 1;
		else
			initialParticleVelocityY = partVelY;
		xOffset = 0.1f;
		yOffset = 0.1f;
	}
	float generationFrequency;
	float initialParticleVelocityX;
	float initialParticleVelocityY;
	float xOffset;
	float yOffset;
};