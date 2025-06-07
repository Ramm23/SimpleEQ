//
// Created by romel on 06/06/2025.
//
#include "PluginEditor.h"

MyAudioPluginAudioProcessorEditor::MyAudioPluginAudioProcessorEditor(MyAudioPluginAudioProcessor& p)
    : AudioProcessorEditor(&p), audioProcessor(p)
{
    setSize(400, 300);
}

MyAudioPluginAudioProcessorEditor::~MyAudioPluginAudioProcessorEditor() {}

void MyAudioPluginAudioProcessorEditor::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colours::black);
    g.setColour(juce::Colours::white);
    g.setFont(15.0f);
    g.drawFittedText("MyAudioPlugin", getLocalBounds(), juce::Justification::centred, 1);
}

void MyAudioPluginAudioProcessorEditor::resized()
{
    // Layout components here
}
