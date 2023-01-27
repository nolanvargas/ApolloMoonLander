/***********************************************************************
 * Header File:
 *    Thrust : Represents the engine thrust in the lunar lander game
 * Author:
 *    Antonio Saucedo
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

	void rotation();
	void mainEngineThrust();
	bool isMain();
	bool isClock();
	bool isCounter();
	void set(Interface UI);
};

