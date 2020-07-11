#pragma once
#include <Particle.h>
class Attractor :public Particle
{
public:
	Attractor::Attractor(float m, float r, float xPosition, float yPosition)
	{

		mass = m;
		radius = r;
		xPos = xPosition;
		yPos = yPosition;
		if (mass > 0) {
			RGB[0] = 1.f;
			RGB[1] = 0.f;
			RGB[2] = 0.f;
		}
		else {
			RGB[0] = 0.f;
			RGB[1] = 0.f;
			RGB[2] = 1.f;
		}

	}
};