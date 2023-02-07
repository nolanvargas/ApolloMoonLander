/***********************************************************************
 * Source File:
 *    Thrust : Represents the engine thrust in the lunar lander game
 * Author:
 *    Antonio Saucedo
 * Summary:
 *    When the lunar lander is rotating and using thrusters.
 ************************************************************************/

#include "thrust.h"

Thrust::Thrust()
{
	mainEngine = false;
	clockwise = false;
	counterClockwise = false;
}

bool Thrust::isMain()
{
	return mainEngine;
}

bool Thrust::isClock()
{
	return clockwise;
}

bool Thrust::isCounter()
{
	return counterClockwise;
}

void Thrust::set(Interface UI)
{
	mainEngine = UI.isUp();
	clockwise = UI.isRight();
	counterClockwise = UI.isLeft();
}
