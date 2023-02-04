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
