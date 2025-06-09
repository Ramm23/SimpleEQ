//
// Created by romel on 06/06/2025.
//
#pragma once

#include <juce_audio_processors/juce_audio_processors.h>

class SimpleEQAudioProcessor : public juce::AudioProcessor
{
public:
    SimpleEQAudioProcessor();
    ~SimpleEQAudioProcessor() override;


    void prepareToPlay(double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

    bool isBusesLayoutSupported(const BusesLayout& layouts) const override;
    void processBlock(juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram(int index) override;
    const juce::String getProgramName(int index) override;
    void changeProgramName(int index, const juce::String& newName) override;

    void getStateInformation(juce::MemoryBlock& destData) override;
    void setStateInformation(const void* data, int sizeInBytes) override;

    static juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout()
    {
       juce::AudioProcessorValueTreeState::ParameterLayout layout;

        layout.add(std::make_unique<juce::AudioParameterFloat>("LowCut Freq",
                                                            "LowCut Freq",
                                                            juce::NormalisableRange<float>(20.0f, 20000.0f, 1.f, 1.f  ),
                                                            20.f));

        layout.add(std::make_unique<juce::AudioParameterFloat>("HighCut Freq",
                                                            "HighCut Freq",
                                                            juce::NormalisableRange<float>(20.0f, 20000.0f, 1.f, 1.f  ),
                                                    20000.f));
        layout.add(std::make_unique<juce::AudioParameterFloat>("Peak Freq",
                                                            "Peak Freq",
                                                            juce::NormalisableRange<float>(20.0f, 20000.0f, 1.f, 1.f  ),
                                                            750.f));

        layout.add(std::make_unique<juce::AudioParameterFloat>("Peak Gain",
                                                            "Peak Gain",
                                                            juce::NormalisableRange<float>(-24.0f, 24.0f, 0.5f, 1.f  ),
                                                            0.0f));

        layout.add(std::make_unique<juce::AudioParameterFloat>("Peak Quality",
                                                            "Peak Quality",
                                                            juce::NormalisableRange<float>(0.1f, 10.f, 0.05f, 1.f  ),
                                                            1.f));

        juce::StringArray stringArray;
        for (int i = 0; i < 4; i++) {
            juce::String string;
            string << (12 + i*12);
            string << "db/Oct";
            stringArray.add(string);
        }
        layout.add(std::make_unique<juce::AudioParameterChoice>("LowCut Slope", "LowCut Slope", stringArray, 0));
        layout.add(std::make_unique<juce::AudioParameterChoice>("HighCut Slope", "HighCut Slope", stringArray, 0));

        return layout;
    };

    //This creates new instances of the plugin
    AudioProcessor* JUCE_CALLTYPE createPluginfilter() {
        return new SimpleEQAudioProcessor();
    }


};
