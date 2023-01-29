#pragma once
#include "point.h"
#include "velocity.h"
#include "thrust.h"

class Lander
{
private:
	int status; //1 for dead 0 for alive
	Point pt;
	Velocity v;
	double angle = 0;
	Point ptUpperRight; // Size of the screen
	int fuel = 5000; //Makes sense to make it an integer
	const double weight = 15103.00;
	const double thrust = 45000.00;
	const double g = -1.625; //Gravity

public:

	// Constructor
	Lander(Point location, Point screen) : 
		pt(location), 
		ptUpperRight(screen)
	{
		status = 0;
	};
	void reset();
	bool isDead();
	bool isFlying();
	bool isLanded();
	Point getPosition();
	double getAngle();
	int getFuel();
	//void draw(thrust, gout);
	void input(int thrustHere);
	void coast();
	void land();
	void crash();
	void updatePosition();
	double getSpeed();

};

