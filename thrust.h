/***********************************************************************
 * Header File:
 *    Thrust : Represents the engine thrust in the lunar lander game
 * Author:
 *    Antonio Saucedo, Thomas Vargas
 * Summary:
 *    When the lunar lander is rotating and using thrusters.
 ************************************************************************/

#pragma once

#include "uiInteract.h"

class Thrust
{
private:
	bool mainEngine;
	bool clockwise;
	bool counterClockwise;

public:

	// Constructor
	Thrust();

	bool isMain();
	bool isClock();
	bool isCounter();
	void set(Interface UI);
};

