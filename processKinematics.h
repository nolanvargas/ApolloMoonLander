/***********************************************************************
 * Header File:
 *    ProcessKinematics : A class with kinematic calculations
 * Author:
 *    Antonio Saucedo, Thomas Vargas
 * Summary:
 *    The methods in this class will perform calculations on the
 *	  given inputs to produce new kinematic variables
 ************************************************************************/



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


