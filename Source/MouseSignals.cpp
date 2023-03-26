/*
  ==============================================================================

    MouseSignals.cpp
    Created: 25 Mar 2023 12:11:35pm
    Author:  brady

  ==============================================================================
*/

#include "MouseSignals.h"
#include <cmath>

MouseSignals::MouseSignals(): mPos(0, 0) { }

void MouseSignals::updatePosition(float x, float y) {
  // Update movement angle
  mMoveAngle = std::atan2f(x - mPos.x, mPos.y - y);

  // Update speed
  mSpeed = std::sqrtf(std::powf(mPos.x + x, 2) + std::powf(mPos.y + y, 2));
  
  // Finally update the position
  mPos.x = x;
  mPos.y = y;
}

void MouseSignals::updatePressure(float pressure) { mPressure = pressure; }