cmake_minimum_required(VERSION 3.15)

project(MyAudioPlugin VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)

# Add JUCE
set(JUCE_DIR "${CMAKE_SOURCE_DIR}/JUCE")
add_subdirectory(${JUCE_DIR} JUCE)

juce_add_plugin(MyAudioPlugin
        COMPANY_NAME "MyCompany"
        IS_SYNTH FALSE
        NEEDS_MIDI_INPUT FALSE
        NEEDS_MIDI_OUTPUT FALSE
        IS_MIDI_EFFECT FALSE
        EDITOR_WANTS_KEYBOARD_FOCUS FALSE
        COPY_PLUGIN_AFTER_BUILD TRUE
        PLUGIN_MANUFACTURER_CODE Juce
        PLUGIN_CODE Plg1
        FORMATS VST3
        PRODUCT_NAME "My Audio Plugin"
        # Optional: enable standalone version
        # STANDALONE_PLUGIN TRUE
)

target_sources(MyAudioPlugin
        PRIVATE
        Source/PluginProcessor.cpp
        Source/PluginProcessor.h
        Source/PluginEditor.cpp
        Source/PluginEditor.h)

target_compile_definitions(MyAudioPlugin
        PRIVATE
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
)

target_link_libraries(MyAudioPlugin
        PRIVATE
        juce::juce_audio_utils
)
