#include "lander.h"
#include "processKinematics.h"

ProcessKinematics pk;

void Lander::reset() {
	landed = false;
	dead = false;
	pt = startingPt;
	angle = Angle();
	fuel = 5000;
	v = Velocity();
}

bool Lander::isDead() {
	return dead;
}

bool Lander::isFlying() {
	if (!dead) return true;
	return false;
}

bool Lander::isLanded() {
	return landed;
}

Point Lander::getPosition() {
	return pt;
}

int Lander::getFuel() {
	return fuel;
}

double Lander::getAngle()
{
	return angle.getRadians();
}

void Lander::land() {
	angle = 0;
	landed = true;
}
void Lander::crash() {
	dead = true;
}

void Lander::handleInput(const Interface* pUI) {
	if (pUI->isRight())
	{
		angle.setRadians(angle.getRadians() - 0.1);
		fuel -= 1;
	}
	if (pUI->isLeft())
	{
		angle.setRadians(angle.getRadians() + 0.1);
		fuel -= 1;
	}
	if (pUI->isDown()) {
		double _x, _y;
		std::tie(_x, _y) = pk.applyThrust(thrust, weight, v.getDx(), v.getDy(), angle.getRadians());
		v.setDx(_x);
		v.setDy(_y);
		fuel -= 10;
	}
}

void Lander::updatePosition() {
	v.setDy(pk.applyGravity(v.getDy(), (g / 30)));
	double _x, _y;
	tie(_x, _y) = pk.applyInertia(pt.getX(), pt.getY(), v.getDx(), v.getDy(), g);
	pt.setX(_x);
	pt.setY(_y);

}

double Lander::getSpeed()
{
	return v.getSpeed() * 3; // 3 times speed?;
}
