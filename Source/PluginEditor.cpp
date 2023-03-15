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
  addAndMakeVisible(mMouseCapture);

  setSize(400, 500);
}

MouseModulatorPluginAudioProcessorEditor::~MouseModulatorPluginAudioProcessorEditor() {}

//==============================================================================
void MouseModulatorPluginAudioProcessorEditor::paint(juce::Graphics& g) {
  // (Our component is opaque, so we must completely fill the background with a solid colour)
  g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));

  g.setColour(juce::Colours::white);
  g.setFont(15.0f);
  g.drawFittedText("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void MouseModulatorPluginAudioProcessorEditor::resized() {
  auto r = getLocalBounds();
  auto config = r.removeFromTop(100);
  mMouseCapture.setBounds(r);
}
