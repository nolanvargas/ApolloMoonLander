#pragma once
class Thrust
{
private:
	bool mainEngine;
	bool clockwise;
	bool counterClockwise;

public:

	// Constructor
	Thrust();

	void rotation();
	void mainEngineThrust();
	bool isMain();
	bool isClock();
	bool isCounter();
	void set(UI);
};

