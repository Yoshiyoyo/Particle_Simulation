#pragma once
#include <openglwindow.h>
class Particle
{
public:
	//GL_FLOAT xPos;
	Particle::Particle()
	{
		RGB = new float[3]{ .5f,.5f,.5f };
	}
	Particle::Particle(float m, float r, float xPosition, float yPosition)
	{
		mass = m;
		radius = r;
		xPos = xPosition;
		yPos = yPosition;
	}
	float mass, radius, yPos, xPos;
	float* RGB;
};