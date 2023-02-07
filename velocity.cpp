/***********************************************************************
 * Source File:
 *    Velocity : Represents the lunar lander velocity in the lunar lander game
 * Author:
 *    Antonio Saucedo
 * Summary:
 *    The speed the lunar lander is travelling.
 ************************************************************************/

#include "velocity.h"
#include <cmath>

Velocity::Velocity()
{
	dx = 0;
	dy = 0;
}

Velocity::Velocity(float dx, float dy)
{
	this->dx = dx;
	this->dy = dy;
}

float Velocity::getDx()
{
	return dx;
}

float Velocity::getDy()
{
	return dy;
}

float Velocity::getSpeed()
{
	return sqrt((dx * dx) + (dy * dy));
}

void Velocity::setDx(float dx)
{
	this->dx = dx;
}

void Velocity::setDy(float dy)
{
	this->dy = dy;
}
