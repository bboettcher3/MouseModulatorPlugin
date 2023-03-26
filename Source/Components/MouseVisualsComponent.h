/*
  ==============================================================================

    MouseCaptureComponent.h
    Created: 18 Jul 2022 9:09:31pm
    Author:  brady

  ==============================================================================
*/

#pragma once

#include <juce_gui_basics/juce_gui_basics.h>
#include <juce_gui_extra/juce_gui_extra.h>

//==============================================================================
/*
 */
class MouseVisualsComponent : public juce::AnimatedAppComponent {
 public:
  MouseVisualsComponent();
  ~MouseVisualsComponent() override;

  void paint(juce::Graphics&) override;
  void resized() override;

  void setIsActive(bool active) { mIsActive = active; }
  void updateMousePosition(juce::Point<float> position);

  void update() override;

 private:
  bool mIsActive = false;
  juce::Point<float> mMousePosition;

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MouseVisualsComponent)
};
