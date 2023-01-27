/***********************************************************************
 * Header File:
 *    Velocity : Represents the lunar lander velocity in the lunar lander game
 * Author:
 *    Antonio Saucedo
 * Summary:
 *    The speed the lunar lander is travelling.
 ************************************************************************/

#pragma once
class Velocity
{
private:
	float dx;
	float dy;

public:

	// Constructors
	Velocity();
	Velocity(float dx, float dy);

	float getDx();
	float getDy();
	float getSpeed();
	void setDx(float dx);
	void setDy(float dy);
	void add(float acceleration, float time);
};
