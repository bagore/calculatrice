#!/bin/bash

# Bash option to stop when an error occurs
set -e

# Bash option to print all executed commands
set -x


# Display PWD for debug purposes
pwd


# Build with analysis wrapping
build-wrapper-linux-x86-64 --out-dir bw-output make target tests


# Proceed analysis (option -X for debug)
sonar-scanner -X


# "default" return code if everything went well
exit 0
