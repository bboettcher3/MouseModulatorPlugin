/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MouseModulatorPluginAudioProcessorEditor::MouseModulatorPluginAudioProcessorEditor(MouseModulatorPluginAudioProcessor& p)
    : AudioProcessorEditor(&p), audioProcessor(p) {
  addAndMakeVisible(mConfig);
  addAndMakeVisible(mMouseVisuals);

  const juce::Displays::Display* screen = juce::Desktop::getInstance().getDisplays().getPrimaryDisplay();
  if (screen != nullptr) {
    setSize(screen->userArea.getWidth(), screen->userArea.getHeight());
  } else {
    setSize(300, 400);
  }
  
}

MouseModulatorPluginAudioProcessorEditor::~MouseModulatorPluginAudioProcessorEditor() {}

//==============================================================================
void MouseModulatorPluginAudioProcessorEditor::paint(juce::Graphics& g) {
  // (Our component is opaque, so we must completely fill the background with a solid colour)
  g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));

}

void MouseModulatorPluginAudioProcessorEditor::resized() {
  auto r = getLocalBounds();
  mConfig.setBounds(r.removeFromTop(50));
  mMouseVisuals.setBounds(r);
}

void MouseModulatorPluginAudioProcessorEditor::mouseMove(const juce::MouseEvent& e) {
  if (mMouse != nullptr) {
    mMouseSigs.updatePosition(e.getScreenPosition().x, e.getScreenPosition().y);
    mMouseVisuals.updateMousePosition(e.getScreenPosition().toFloat());
    juce::Desktop::setMousePosition(getScreenBounds().getCentre());
    // mMouse->setScreenPosition(getScreenBounds().getCentre().toFloat());
    DBG("type: " << (int)e.source.getType() << ", hover: " << (int)e.source.canHover()
                 << ", pressure: " << (int)e.source.isPressureValid() << ", orientation: " << (int)e.source.isOrientationValid()
                 << ", rotation: " << (int)e.source.isRotationValid());
  }
}

void MouseModulatorPluginAudioProcessorEditor::mouseDrag(const juce::MouseEvent& e) {
  if (mMouse != nullptr) {
    mMouseSigs.updatePosition(e.getScreenPosition().x, e.getScreenPosition().y);
    if (e.source.isPressureValid()) mMouseSigs.updatePressure(e.pressure);
    //mMouseVisuals.
    mMouse->setScreenPosition(getScreenBounds().getCentre().toFloat());
  }
}

void MouseModulatorPluginAudioProcessorEditor::mouseUp(const juce::MouseEvent& e) {
  // Save the mouse source that triggered this event
  mMouse = juce::Desktop::getInstance().getMouseSource(e.source.getIndex());
  mMouse->showMouseCursor(juce::MouseCursor::NoCursor);
  mMouseVisuals.setIsActive(true);
}

void MouseModulatorPluginAudioProcessorEditor::mouseExit(const juce::MouseEvent& e) {
  if (mMouse != nullptr) {
    mMouse->setScreenPosition(getScreenBounds().getCentre().toFloat());
  }
}

bool MouseModulatorPluginAudioProcessorEditor::keyPressed(const juce::KeyPress& key, juce::Component* originatingComponent) {
  if (key.isKeyCode(juce::KeyPress::escapeKey) && mMouse != nullptr) {
    mMouse->showMouseCursor(juce::MouseCursor::NormalCursor);
    mMouse = nullptr;
    mMouseVisuals.setIsActive(false);
    return true;
  }

  return false;
}