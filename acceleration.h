#pragma once
class Acceleration
{
private:
	float ddx;
	float ddy;

public:

	// Constructors
	Acceleration();
	Acceleration(float ddx, float ddy);

	float getDdx();
	float getDdy();
	void setDdx(float ddx);
	void setDdy(float ddy);
	
};

