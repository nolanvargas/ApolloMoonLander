/***********************************************************************
 * Header File:
 *    Lander : Represents the lunar lander
 * Author:
 *    Antonio Saucedo, Thomas Vargas
 * Summary:
 *    This is the lunar lander module
 ************************************************************************/

#pragma once
#include "velocity.h"
#include "thrust.h"
#include "angle.h"

class Lander
{
private:
	Point pt;
	Point startingPt;
	Velocity v;
	Angle angle;
	Point ptUpperRight; // Size of the screen
	unsigned int fuel = 5000; //Makes sense to make it an integer
	const double weight = 15103.00;
	const double thrust = 15000.00;
	const double g = -1.625; //Gravity
	bool dead;
	bool landed;

public:

	// Constructor
	Lander(Point location, Point screen) : 
		pt(location), 
		startingPt(location),
		ptUpperRight(screen)
	{
		dead = false;
		landed = false;
	};
	
	int status; //0 for flying, 1 for dead, 2 for landed
	void handleInput(const Interface* pUI);
	void reset();
	bool isDead();
	bool isFlying();
	bool isLanded();
	Point getPosition();
	double getAngle();
	int getFuel();
	void land();
	void crash();
	void updatePosition();
	double getSpeed();

};

