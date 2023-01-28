#include <iostream> // cout and what not
#include <iomanip> //setw
#include <cmath> //sqrt
#include <cassert>//assert
#include <tuple>

using namespace std;

class ProcessKinematics
{
public:
	tuple<double, double> applyInertia(double x, \
		double y, double dx, double dy, double gravity);
	double applyGravity(double dy, double g);
	tuple<double, double> applyThrust(double thrust, \
		double weight, double dx, double dy, double angle);
	double radiansFromDegrees(double degrees);
	double degreesFromRadians(double radians);
	double totalVelocity(double dx, double dy);
};


