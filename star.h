/***********************************************************************
 * Header File:
 *    Thrust : Represents the stars in the lunar lander game
 * Author:
 *    Antonio Saucedo
 * Summary:
 *    When the lunar lander game is running, the stars display in the
 *    dackground.
 ************************************************************************/

#pragma once
#include "point.h"
#include "uiDraw.h"

class Star
{
public:
	// Constructor
	char phase;
	Point pt;
	Star();

	void reset(int width, int height);
	void draw(ogstream gout);
};
