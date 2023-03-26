/*
  ==============================================================================

    MouseSignals.h
    Created: 25 Mar 2023 12:11:35pm
    Author:  brady

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class MouseSignals {
 public:
  MouseSignals();
  ~MouseSignals() {}

  class Signal {
   public:
    Signal(juce::String name, int midiCC);
    ~Signal();

    juce::String name;
    int midiCC;
    bool sendMidi = false;
    bool sendOsc = false;
    bool sendMapper = false;
  };

  void updatePosition(float x, float y);
  void updatePressure(float pressure);

 private:
  // Position-based signals
  juce::Point<float> mPos;         // Position on the screen
  float mMoveAngle;                // Movement angle in radians
  float mSpeedX, mSpeedY, mSpeed;  // Speed in each direction and total
  float mPressure;                 // Pen pressure
  // Misc. signals
  // clicks, scrolls, etc.
};