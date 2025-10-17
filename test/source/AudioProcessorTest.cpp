#include <gtest/gtest.h>
#include <PluginName/PluginProcessor.h>

namespace audio_plugin_test {
    TEST(PluginName, Foo) {
        // Tester. om der kan instantieres en AudioProcessor
        // fra AudioPlugin projektet.
        AudioPluginAudioProcessor processor{};
        ASSERT_FALSE(true);
    }
}