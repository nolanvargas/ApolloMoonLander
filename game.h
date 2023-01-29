#pragma once
#include "uiInteract.h"
#include "uiDraw.h"
#include "point.h"
#include "ground.h"
#include "lander.h"
#include "star.h"
#include "thrust.h"
#include <vector> // This may need to be changed

class Game
{
private:
	Point ptLM;           // location of the LM on the screen
	Point ptUpperRight;   // size of the screen
	unsigned char phase;  // phase of the star's blinking
	Ground ground;
	Point ptStar;
	Lander mL;

	Thrust thrust;
	std::vector<Star> stars; // Vector of star objects

public:
		
	// Contructor
	Game(const Point& ptUpperRight) :
		ptStar(ptUpperRight.getX() - 20.0, ptUpperRight.getY() - 20.0),
		ptLM(ptUpperRight.getX() / 2.0, ptUpperRight.getY() / 2.0),
		ground(ptUpperRight), mL(Point(250.0, 250.0), ptUpperRight)
	{

		phase = random(0, 255);
	};

	void reset();
	void input(const Interface* pUI); //ui draw maybe?
	void gamePlay(Thrust thrust);
	void display(Thrust thrust, const Interface* pUI);

};

