#pragma once
#include "ground.h"
#include "lander.h"
#include "star.h"
#include <vector>

class Game
{
private:
	Point ptLM;           // location of the LM on the screen
	Point ptUpperRight;   // size of the screen
	Ground ground;
	Lander mL;

	bool playing;
	int timer;
	Thrust thrust;
	std::vector<Star> stars; // Vector of star objects

public:
		
	// Contructor
	Game(const Point& ptUpperRight) :
		ptLM(ptUpperRight.getX() / 2.0, ptUpperRight.getY() / 2.0),
		ground(ptUpperRight), mL(Point(ptUpperRight.getX() - 100, ptUpperRight.getY() - 100), ptUpperRight),
		timer(100), playing(false)
	{

		for (int i = 0; i <= 100; i++) {
			Star star;
			star.reset(ptUpperRight.getX() - 20.0, ptUpperRight.getY() - 20.0);
			stars.push_back(star);
		};
	};

	void reset();
	void input(const Interface* pUI); //ui draw maybe?
	void gamePlay(Thrust thrust);
	void display(Thrust thrust, const Interface* pUI);

};

