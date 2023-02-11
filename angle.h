/***********************************************************************
 * Header File:
 *    Angle : Represents an angle with its properties
 * Author:
 *    Antonio Saucedo, Thomas Vargas
 * Summary:
 *    An angle has a value of radians. This classa has the functionality
 *    to convert radians to degrees and accept degrees as input
 ************************************************************************/

#pragma once
class Angle
{
private:
	double radians;
	double convertToDegrees(double input_degrees) const;
	double convertToRadians(double input_radians) const;
	void normalize();

public:
	Angle() : radians(0.0f) {};
	Angle(double rad) : radians(rad) {}
	Angle(const Angle& other) : radians(other.radians) {};
	double getDegrees() const;
	double getRadians() const;
	void setRadians(double new_radians);
	void setDegrees(double new_degrees);
	void display() const;
};
