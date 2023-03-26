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
class MouseVisualsComponent : public juce::AnimatedAppComponent {
 public:
  MouseVisualsComponent();
  ~MouseVisualsComponent() override;

  void paint(juce::Graphics&) override;
  void resized() override;

  void updateMousePosition(juce::Point<float> position);

  void update() override;

 private:
  juce::Point<float> mMousePosition;

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MouseVisualsComponent)
};
