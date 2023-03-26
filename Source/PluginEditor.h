/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Components/MouseVisualsComponent.h"
#include "Components/ConfigComponent.h"
#include "MouseSignals.h"

//==============================================================================
/**
 */
class MouseModulatorPluginAudioProcessorEditor : public juce::AudioProcessorEditor, juce::MouseListener, juce::KeyListener {
 public:
  MouseModulatorPluginAudioProcessorEditor(MouseModulatorPluginAudioProcessor&);
  ~MouseModulatorPluginAudioProcessorEditor() override;

  //==============================================================================
  void paint(juce::Graphics&) override;
  void resized() override;

  void mouseMove(const juce::MouseEvent& e) override;
  void mouseDrag(const juce::MouseEvent& e) override;
  void mouseUp(const juce::MouseEvent& e) override;
  void mouseExit(const juce::MouseEvent& e) override;

  bool keyPressed(const juce::KeyPress& key, juce::Component* originatingComponent) override;

 private:
  // Components
  ConfigComponent mConfig;
  MouseVisualsComponent mMouseVisuals;

  // Bookkeeping
  juce::MouseInputSource* mMouse = nullptr;
  MouseSignals mMouseSigs;

  // This reference is provided as a quick way for your editor to
  // access the processor object that created it.
  MouseModulatorPluginAudioProcessor& audioProcessor;

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MouseModulatorPluginAudioProcessorEditor)
};
