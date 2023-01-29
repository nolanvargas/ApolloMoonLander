/***********************************************************************
 * Source File:
 *    Star : Represents the stars in the lunar lander game
 * Author:
 *    Antonio Saucedo
 * Summary:
 *    When the lunar lander game is running, the stars display in the
 *    dackground.
 ************************************************************************/

#pragma once
#include "star.h"

Star::Star()
{
	Point pt();
	phase = random(0, 208);
}

void Star::reset(int width, int height)
{
	pt = Point(random(0, width), random(0, height));
}

void Star::draw(ogstream gout)
{
	phase++;
	gout.drawStar(pt, phase);
}
