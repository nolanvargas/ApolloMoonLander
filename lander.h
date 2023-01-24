#pragma once
class Lander
{
private:
	int status;
	Point pt;
	Velocity v;
	double angle;
	Point ptUpperRight;
	int fuel; //Makes sense to make it an integer
	double weight;
	double thrust;
	double g; //Gravity

public:

	// Constructor
	Lander(ptUpperRight);
	void reset();
	bool isDead();
	bool isFlying();
	bool isLanded();
	Point getPosition();
	int getFuel();
	void draw(thrust, gout);
	void input(thrust);
	void coast();
	void land();
	void crash();

};

