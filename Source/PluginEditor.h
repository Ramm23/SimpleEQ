//
// Created by romel on 06/06/2025.
//

#pragma once

#include <juce_gui_extra/juce_gui_extra.h>
#include "PluginProcessor.h"

class MyAudioPluginAudioProcessorEditor : public juce::AudioProcessorEditor
{
public:
    MyAudioPluginAudioProcessorEditor(SimpleEQAudioProcessor&);
    ~MyAudioPluginAudioProcessorEditor() override;

    void paint(juce::Graphics&) override;
    void resized() override;

private:
    SimpleEQAudioProcessor& audioProcessor;
};
