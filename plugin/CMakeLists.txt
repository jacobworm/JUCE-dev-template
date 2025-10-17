cmake_minimum_required(VERSION 4.0)

project (${PLUGIN_NAME} VERSION 0.1.0)

juce_add_plugin(${PLUGIN_NAME}
    COMPANY_NAME "Umbrae"
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT FALSE
    NEEDS_MIDI_OUTPUT FALSE
    PLUGIN_MANUFACTURER_CODE Umbrae
    PLUGIN_CODE Dem0
    FORMATS VST3 AU AAX Standalone
    PRODUCT_NAME "${PLUGIN_NAME}"
    )

# Add source files to the plugin target
target_sources(${PROJECT_NAME}
    PRIVATE
        source/PluginName/PluginProcessor.cpp
        source/PluginName/PluginEditor.cpp
        include/PluginName/PluginProcessor.h
        include/PluginName/PluginEditor.h
)

# Set include directories
target_include_directories(${PROJECT_NAME}
    PRIVATE
        include
)

    target_link_libraries(${PROJECT_NAME}
        PRIVATE
            juce::juce_audio_utils
            juce::juce_audio_devices
        PUBLIC
            juce::juce_recommended_config_flags
            juce::juce_recommended_lto_flags
            juce::juce_recommended_warning_flags
            )

    target_compile_definitions(${PROJECT_NAME}
        PRIVATE
            JUCE_PLUGINNAME_VERSION_MAJOR=0
            JUCE_PLUGINNAME_VERSION_MINOR=1
            JUCE_PLUGINNAME_VERSION_PATCH=0
            JUCE_VST3_CAN_REPLACE_VST2=0
            JUCE_USE_CURL=0
            JUCE_WEB_BROWSER=0
    )

    if (MSVC)
        target_compile_options(${PROJECT_NAME} 
        PRIVATE 
        _SILENCE_CXX23_ALIGNED_STORAGE_DEPRECATION_WARNING
        )
    endif()