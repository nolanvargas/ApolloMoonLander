#pragma once
#include "uiInteract.h"
#include "uiDraw.h"
#include "point.h"
#include "ground.h"
#include "lander.h"
#include "star.h"
#include "thrust.h"
#include <vector> // This may need to be changed
#include <cmath>
#include "game.h"

using namespace std;

void Game::input(const Interface* pUI) {
    // move the ship around
    if (pUI->isRight())
        mL.input(1);
    if (pUI->isLeft())
        mL.input(2);
    if (pUI->isUp())
        mL.input(3);
    if (pUI->isDown())
        mL.input(4);
}

void Game::gamePlay(Thrust thrust) {
    mL.updatePosition();
}

void Game::display(Thrust thrust, const Interface* pUI) {
    ogstream gout;

    for (auto& star : stars) {
        star.draw(gout);
    }

    // We were passing the object and that uses the object copy constructor. INstead we are passing by reference

    ground.draw(gout);

    // draw the lander and its flames
    gout.drawLander(mL.getPosition() /*position*/, mL.getAngle() /*angle*/);
    gout.drawLanderFlames(mL.getPosition(), mL.getAngle(), /*angle*/
        pUI->isDown(), pUI->isLeft(), pUI->isRight());

    // draw the lander stats
    cout << ptUpperRight.getY();
    gout.setPosition(Point(30, 360));
    double speed = round(mL.getSpeed() * 100.0) / 100.0;
    gout << "Fuel:\t" << mL.getFuel() << "\nAltitude:\t" << mL.getPosition().getY() << "\nSpeed:\t" << speed << "m/s";
}