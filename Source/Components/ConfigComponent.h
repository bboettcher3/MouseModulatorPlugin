/*
  ==============================================================================

    ConfigComponent.h
    Created: 16 Mar 2023 12:45:19pm
    Author:  brady

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
 */
class ConfigComponent : public juce::Component {
 public:
  ConfigComponent();
  ~ConfigComponent() override;

  void paint(juce::Graphics&) override;
  void resized() override;

 private:
  juce::TextButton mSelectMouse;
  juce::TextButton mSelectTouch;
  juce::TextButton mSelectPen;

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ConfigComponent)
};
