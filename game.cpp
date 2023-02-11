#pragma once
#include "game.h"
#include <iomanip>

using namespace std;

void Game::reset()
{
    timer = 50;
    playing = false;
    mL.reset();
    ground.reset();
}

void Game::input(const Interface* pUI) {
    // move the ship around
    if (timer == 0 && !(mL.isDead() || mL.isLanded()) && mL.getFuel() > 0) {
        mL.handleInput(pUI);
    }
    if (pUI->isSpace()) {
        reset();
    }
}

void Game::gamePlay() {
    if (timer > 0) {
        timer -= 1;
        return;
    }
    else playing = true;
    if (!(mL.isDead() || mL.isLanded())) {
        mL.updatePosition();
        if (ground.onPlatform(mL.getPosition(), 20) &&
            mL.getSpeed() < 4 &&
            (mL.getAngle() > 5.8 ||
                mL.getAngle() < 0.5)) {
            mL.land();
        }
        else if (ground.hitGround(mL.getPosition(), 20)) {
            mL.crash();
        }

    }
}

void Game::display(const Interface* pUI) {
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
    gout.setPosition(Point(30, 360));
    double speed = round(mL.getSpeed() * 100.0) / 100.0;
    gout << "Fuel:\t" << mL.getFuel() << " lbs \nAltitude:\t" << round(ground.getElevation(mL.getPosition())) << " meters\nSpeed:\t" << speed << " m/s";

    // draw an explosion if dea
    if (mL.isDead()) {
        gout.drawExplosion(mL.getPosition());
    }


    // draw end game message
    Point endGameMessages(200, 200);
    gout.setPosition(endGameMessages);
    if (mL.isLanded())
        gout << "Houston, We have Touchdown!\n";
    else if (mL.isDead()) {
        if (mL.getSpeed() > 4) {
            gout << "You came in too fast!";
            endGameMessages.addY(30);
            gout.setPosition(endGameMessages);
        }
        if (!(mL.getAngle() > 5.8 || mL.getAngle() < 0.5)) {
            gout << "Your angle is off-course!";
            endGameMessages.addY(30);
            gout.setPosition(endGameMessages);

        }
        if (!ground.onPlatform(mL.getPosition(), 20)) {
            gout << "You missed the platform!";
            endGameMessages.addY(30);
            gout.setPosition(endGameMessages);

        }
    }

    // display countdown timer
    if (!playing) {
        gout.setPosition(Point(200, 200));
        float displayTimer = timer / 10.0;
        gout << std::fixed << std::setprecision(1) << displayTimer;
    }
}