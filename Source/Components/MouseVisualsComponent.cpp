/*
  ==============================================================================

    MouseVisualsComponent.cpp
    Created: 18 Jul 2022 9:09:31pm
    Author:  brady

  ==============================================================================
*/

#include <JuceHeader.h>
#include "MouseVisualsComponent.h"

//==============================================================================
MouseVisualsComponent::MouseVisualsComponent() {
  juce::Desktop::getInstance().addGlobalMouseListener(this);
  setWantsKeyboardFocus(true);
  setFramesPerSecond(30);
}

MouseVisualsComponent::~MouseVisualsComponent() {}

void MouseVisualsComponent::paint(juce::Graphics& g) {
  g.fillAll(juce::Colours::black);
  //g.setColour(mMouse != nullptr ? juce::Colours::lawngreen : juce::Colours::red);
  //juce::Point<float> vector = getLocalBounds().getCentre().getPointOnCircumference(mMouseSpeed, mMouseAngle);
  //g.drawLine(getLocalBounds().getCentreX(), getLocalBounds().getCentreY(), vector.x, vector.y, 2);
  g.drawRect(getLocalBounds(), 2);  // draw an outline around the component
}

void MouseVisualsComponent::resized() {}

void MouseVisualsComponent::update() {

}

void MouseVisualsComponent::updateMousePosition(juce::Point<float> position) {

}