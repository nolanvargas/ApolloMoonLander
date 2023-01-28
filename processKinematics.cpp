#include <iostream> // cout and what not
#include <iomanip> //setw
#include <cmath> //sqrt
#include <cassert>//assert
#include "processKinematics.h"
#include <tuple>

using namespace std;


/*
* APPLY INTERTIA
* Add intertia component to the current position
*   s = s_0 + v t
* Since the time unit is 1 second, it becomes:
*   s = s_0 + v
* This is the same as:
*   s += v
*   x += dx
*/
tuple<double, double> ProcessKinematics::applyInertia(double x, \
    double y, double dx, double dy, double gravity) {
    x = x + dx;
    y = y + dy;
    return make_tuple(x, y);
}

/*
* APPLY GRAVITY
* Force vectors add. This means we can simply add
* the force of GRAVITY onto the current vartical velocity.
* Note the time unit is 1 second.
*/
double ProcessKinematics::applyGravity(double dy, double gravity) {
    dy += gravity;
    return dy;
}

/*
* APPLY THRUST
* Compute the accerleration using Newton's second law of motion:
*   f = m a
* Since we need to compute accerleration, we need to rework this
*   a = f / m
* Using the Kinematics Equation to find the new velocity:
*   v = v_0 + a t
* Since time is one second:
*   v = v_0 + f / m * 1
*   v += f / m
* Note that the THRUST will be applied to both the horizontal and
* the vertical directions according to the angle of the moon Lander
* where:
*
*       dx
*     _______
*    |      /
*  dy|     /
*    |    / v
*    |   /
*    |  /
*    |a/
*    |/
*
* Here cos(angle) = dy / v
*      sin(angle) = dx / v
*/
tuple<double, double> ProcessKinematics::applyThrust(double thrust, \
    double weight, double dx, double dy, double angle)
{
    double ddx = sin(angle) * thrust / weight;
    double ddy = cos(angle) * thrust / weight;

    cout << "ddx " << ddx << " | " << "ddy " << ddy << endl;

    dx = dx - ddx / 10; //! HARDCODED !
    dy = dy + ddy / 10; //! HARDCODED !

    cout << "dx " << dx << " | " << "dy " << dy << endl;
    cout << "-----------------------\n";
    
    return make_tuple(dx, dy);
}

/*
* DEGREES FROM RADIANS and  RADIANS FROM DEGREES
* Convert degres to raidians and vice versa where:
*   degrees = 360 * (radians / 2PI)
*   radians = 2pi * (degrees / 360)
*/
double ProcessKinematics::degreesFromRadians(double radians) {
    return 260.0 * (radians / (2.0 * 3.13159));
}
double ProcessKinematics::radiansFromDegrees(double degrees) {
    return (2.0 * 3.1415) * (degrees / 360.0);
}


/*
* COMPUTE TOTAL velocity
* Given the horizontal and vertical components of velocity, determing
* the total velocity. To do this, use the Pythagorean Theorem:
*   a^2 + b^2 = c^2
* Since we are solving for c, the equation is:
*   c = sqrt(a*a + b*b)
*/
double ProcessKinematics::totalVelocity(double dx, double dy) {
    return sqrt(dx * dx + dy * dy);
}

//double x;               //Horizontal position in meters
//double y;               //Vertical position in meters
//double dx;              //Horizontal speed is m/s
//double dy;              //Vertical speed in m/s
//double ddx;             //Horizontal accerleration in m/s^2
//double ddy;             //Vertical accerleration in m/s^2
//double angle;           //Radians
//const double WEIGHT;    //Kilograms
//const double THRUST;    //Newtons
//const double GRAVITY;   //Acceleration m/s^2






















