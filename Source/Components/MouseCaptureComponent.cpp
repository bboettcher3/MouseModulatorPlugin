/*
  ==============================================================================

    MouseCaptureComponent.cpp
    Created: 18 Jul 2022 9:09:31pm
    Author:  brady

  ==============================================================================
*/

#include <JuceHeader.h>
#include "MouseCaptureComponent.h"

//==============================================================================
MouseCaptureComponent::MouseCaptureComponent() {
  addMouseListener(this, false);
  addKeyListener(this);
  setWantsKeyboardFocus(true);
  setFramesPerSecond(30);
}

MouseCaptureComponent::~MouseCaptureComponent() {}

void MouseCaptureComponent::paint(juce::Graphics& g) {
  g.fillAll(juce::Colours::black);
  g.setColour(mMouse != nullptr ? juce::Colours::lawngreen : juce::Colours::red);
  juce::Point<float> vector = getLocalBounds().getCentre().getPointOnCircumference(mMouseSpeed, mMouseAngle);
  g.drawLine(getLocalBounds().getCentreX(), getLocalBounds().getCentreY(), vector.x, vector.y, 2);
  g.drawRect(getLocalBounds(), 2);  // draw an outline around the component
}

void MouseCaptureComponent::resized() {}

void MouseCaptureComponent::update() {

}

void MouseCaptureComponent::mouseMove(const juce::MouseEvent& e) {
  if (mMouse != nullptr) {
    mMouseAngle = getScreenBounds().getCentre().getAngleToPoint(e.getScreenPosition());
    mMouseSpeed = getScreenBounds().getCentre().getDistanceFrom(e.getScreenPosition());
    mMouse->setScreenPosition(getScreenBounds().getCentre().toFloat());
  }
  //e.source.enableUnboundedMouseMovement(mIsActive);
  //DBG((int)e.source.canDoUnboundedMovement());

}

void MouseCaptureComponent::mouseUp(const juce::MouseEvent& e) { 
  // Save the mouse source that triggered this event
  mMouse = juce::Desktop::getInstance().getMouseSource(e.source.getIndex());
  DBG((int)mMouse->hasMouseCursor());
  mMouse->showMouseCursor(juce::MouseCursor::NoCursor);
  
}

void MouseCaptureComponent::mouseExit(const juce::MouseEvent& e) {
  if (mMouse != nullptr) {
    mMouse->setScreenPosition(getScreenBounds().getCentre().toFloat());
  }
}

bool MouseCaptureComponent::keyPressed(const juce::KeyPress& key, juce::Component* originatingComponent) {
  if (key.isKeyCode(juce::KeyPress::escapeKey) && mMouse != nullptr) {
    mMouse->showMouseCursor(juce::MouseCursor::NormalCursor);
    mMouse = nullptr;
    mMouseAngle = 0;
    mMouseSpeed = 0;
    return true;
  }

  return false;
}