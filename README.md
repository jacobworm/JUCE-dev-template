# Basic setup for beginning a JUCE audio plugin.

Based on WolfSound tutorial: https://www.youtube.com/watch?v=Uq7Hwt18s3s
Be sure to update PLUGIN_NAME and COMPANY_NAME in CMakeLists.txt

# Setup:

## Run the CMakeLists.txt:

To import packages, create the build-system and install packages run the CMakeLists.txt. This will also run the included script:

cmake -S . -B build

-S specifys Source directory ( . gives current directory)
-B specifys build directory.

This command will not make a build but will set the system up.

## Make a build:
by running the command:
cmake - -build build

Builds the project in the build folder by means of the build-files that were created by running “cmake -S . -B build”.
