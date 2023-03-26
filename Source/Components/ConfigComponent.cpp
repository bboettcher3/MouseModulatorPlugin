/*
  ==============================================================================

    ConfigComponent.cpp
    Created: 16 Mar 2023 12:45:19pm
    Author:  brady

  ==============================================================================
*/

#include <JuceHeader.h>
#include "ConfigComponent.h"

//==============================================================================
ConfigComponent::ConfigComponent(): mSelectMouse("mouse"), mSelectTouch("touch"), mSelectPen("pen") { 
  addAndMakeVisible(mSelectMouse);
  addAndMakeVisible(mSelectTouch);
  addAndMakeVisible(mSelectPen);

  // Disable any input sources not connected
  for (juce::MouseInputSource src : juce::Desktop::getInstance().getMouseSources()) {
    DBG("type: " << (int)src.getType() << ", hover: " << (int)src.canHover() << ", pressure: " << (int)src.isPressureValid()
                 << ", orientation: " << (int)src.isOrientationValid() << ", rotation: " << (int)src.isRotationValid());
  }

}

ConfigComponent::~ConfigComponent() {}

void ConfigComponent::paint(juce::Graphics& g) {
  g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));  // clear the background
}

void ConfigComponent::resized() { 
  auto r = getLocalBounds();

  mSelectMouse.changeWidthToFitText(getHeight());
  mSelectTouch.changeWidthToFitText(getHeight());
  mSelectPen.changeWidthToFitText(getHeight());
  mSelectMouse.setBounds(r.removeFromLeft(mSelectMouse.getWidth()));
  mSelectTouch.setBounds(r.removeFromLeft(mSelectTouch.getWidth()));
  mSelectPen.setBounds(r.removeFromLeft(mSelectPen.getWidth()));
}
