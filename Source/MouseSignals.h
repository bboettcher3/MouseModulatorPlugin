/*
  ==============================================================================

    MouseSignals.h
    Created: 25 Mar 2023 12:11:35pm
    Author:  brady

  ==============================================================================
*/

#pragma once

class MouseSignals {
 public:
  MouseSignals();
  ~MouseSignals() {}

  typedef struct Point {
    Point() : x(0), y(0) {}
    Point(float x, float y) : x(x), y(y) {}
    float x;
    float y;
  } Point;

  void updatePosition(float x, float y);
  void updatePressure(float pressure);

 private:
  // Position-based signals
  Point mPos;                      // Position on the screen
  float mMoveAngle;                // Movement angle in radians
  float mSpeedX, mSpeedY, mSpeed;  // Speed in each direction and total
  float mPressure;                 // Pen pressure
  // Misc. signals
  // clicks, scrolls, etc.
};