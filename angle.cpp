#include "angle.h"
#include <cmath>
#include <iostream>
#include <iomanip>

double Angle::convertToDegrees(double input_radians) const
{
	return (input_radians * (180 / 3.141f));
}

double Angle::convertToRadians(double input_degrees) const
{
	return (input_degrees * 3.141f/180);
}

void Angle::normalize()
{
	radians = fmod(radians, 2 * 3.141592f);
	if (radians < 0) {
		radians += 2 * 3.141f;
	}
}

double Angle::getDegrees() const
{
	return convertToDegrees(radians);
}

double Angle::getRadians() const
{
	return radians;
}

void Angle::setRadians(double new_radians)
{
	radians = new_radians;
	normalize();
}

void Angle::setDegrees(double new_degrees)
{
	radians = convertToRadians(new_degrees);
	normalize();
}

void Angle::display() const
{
	std::cout << std::fixed << std::setprecision(1) << convertToDegrees(radians) << std::endl;
}
