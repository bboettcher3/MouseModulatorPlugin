/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Components/MouseCaptureComponent.h"

//==============================================================================
/**
*/
class MouseModulatorPluginAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    MouseModulatorPluginAudioProcessorEditor (MouseModulatorPluginAudioProcessor&);
    ~MouseModulatorPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    MouseCaptureComponent mMouseCapture;

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    MouseModulatorPluginAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MouseModulatorPluginAudioProcessorEditor)
};
