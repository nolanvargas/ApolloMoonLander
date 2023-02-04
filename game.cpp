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
#include <iomanip>
#include <iostream>

using namespace std;

void Game::reset()
{
    timer = 100;
    playing = false;
}

void Game::input(const Interface* pUI) {
    // move the ship around
    if (timer == 0 && mL.status == 0) {
        if (pUI->isRight())
            mL.input(1);
        if (pUI->isLeft())
            mL.input(2);
        if (pUI->isUp())
            mL.input(3);
        if (pUI->isDown())
            mL.input(4);
    }
}

void Game::gamePlay(Thrust thrust) {
    if (timer > 0) {
        timer -= 1;
        return;
    }
    else playing = true;

    if (mL.status == 0) {
        mL.updatePosition();
        if (ground.onPlatform(mL.getPosition(), 10) && 
            mL.getSpeed() < 4 && 
            mL.getAngle() > -45 && 
            mL.getAngle() < 45 ) {
            mL.land();
        }else if (ground.hitGround(mL.getPosition(), 10)) {
            mL.crash();
        }
        
    }
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
    gout.setPosition(Point(30, 960));
    double speed = round(mL.getSpeed() * 100.0) / 100.0;
    gout << "Fuel:\t" << mL.getFuel() << "\nAltitude:\t" << mL.getPosition().getY() << "\nSpeed:\t" << speed << "m/s";

    // display countdown timer
    if (!playing) {
        gout.setPosition(Point(500, 700));
        float displayTimer = timer / 10.0;
        gout << std::fixed << std::setprecision(1) << displayTimer;
    }
    if (mL.status == 1) {
        gout.drawExplosion(mL.getPosition());
    }


    // draw end game message
    gout.setPosition(Point(400, 700));
    if (mL.isLanded())
        gout << "Houston, We have Touchdown.\n";
    else if (mL.status == 1)
        gout << "Houston, We Have a Problem!\n";
}