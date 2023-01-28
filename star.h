#pragma once
#include "point.h"
#include "uiDraw.h"

class Star
{
private:
	Point pt;
	char phase;

public:

	// Constructor
	Star();
	void reset(int width, int height);
	void draw(ogstream gout);
};

