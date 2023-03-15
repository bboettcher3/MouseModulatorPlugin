/*
  ==============================================================================

    MouseCaptureComponent.h
    Created: 18 Jul 2022 9:09:31pm
    Author:  brady

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
 */
class MouseCaptureComponent : public juce::AnimatedAppComponent, juce::MouseListener, juce::KeyListener {
 public:
  MouseCaptureComponent();
  ~MouseCaptureComponent() override;

  void paint(juce::Graphics&) override;
  void resized() override;

  void update() override;

  void mouseMove(const juce::MouseEvent& e) override;
  void mouseUp(const juce::MouseEvent& e) override;
  void mouseExit(const juce::MouseEvent& e) override;

  bool keyPressed(const juce::KeyPress& key, juce::Component* originatingComponent) override;

 private:
  juce::MouseInputSource* mMouse = nullptr;
  float mMouseAngle;
  float mMouseSpeed;

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MouseCaptureComponent)
};
