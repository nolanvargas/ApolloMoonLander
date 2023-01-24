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
	void setDy(float y);
	void add(acceleration, time);

};

