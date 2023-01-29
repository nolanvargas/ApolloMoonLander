#include "lander.h"
#include "point.h"
#include "thrust.h"
#include "processKinematics.h"
#include <tuple>

ProcessKinematics pk;

void Lander::reset() {
	status = 0;
}

bool Lander::isDead() {
	return status;
}

bool Lander::isFlying() {
	return 1;
}

bool Lander::isLanded() {
	return 1;
}

Point Lander::getPosition() {
	return pt;
}

int Lander::getFuel() {
	return fuel;
}

double Lander::getAngle()
{
	return angle;
}

void Lander::coast() {
	pt.addY(-1.0);
}

void Lander::land() {
	//I dont know
}
void Lander::crash() {
	//boom
}

void Lander::input(int x) {
	if (x == 4) {
		//cout << pt.getX() << endl;
		//cout << pt.getY() << endl;
		double _x, _y;
		std::tie( _x, _y) = pk.applyThrust(thrust, weight, v.getDx(), v.getDy(), angle);
		v.setDx(_x);
		v.setDy(_y);
		fuel -= 10;
	}
	else if (x == 4) {
		pt.addY(-1.0);
	}
	if (x == 2) {
		angle += 0.1;
		fuel -= 1;
	}
	else if (x == 1) {
		angle -= 0.1;
		fuel -= 1;
	}
	
}

void Lander::updatePosition() {
	//cout << pt.getX() << endl;
	//cout << pt.getY() << endl;
	//cout << v.getDx() << endl;
	//cout << v.getDy() << endl;
	v.setDy(pk.applyGravity(v.getDy(), (g / 10)));
	double _x, _y;
	tie(_x, _y) = pk.applyInertia(pt.getX(), pt.getY(), v.getDx(), v.getDy(), g);
	pt.setX(_x);
	pt.setY(_y);

}

double Lander::getSpeed()
{
	return v.getSpeed();
}
