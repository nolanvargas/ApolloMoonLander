#pragma once
#include "lander.h"
#include "point.h"
#include "ground.h"
#include "star.h"
#include "thrust.h"
#include <vector> // This may need to be changed

class Game
{
private:
	Lander lander;
	Point ptUpperRight;
	Ground ground;
	Thrust thrust;
	std::vector<Star> stars; // Vector of star objects

public:
		
	// Contructor
	Game(Point ptUpperRight);

	void reset();
	void input(/*ui*/); //ui draw maybe?
	void gamePlay(Thrust thrust);
	void display(Thrust thrust);

};

