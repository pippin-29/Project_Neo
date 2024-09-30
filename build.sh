#!/bin/bash
#
# File: /media/daniel/Stuff/Linux_Stuff/Project_Neo/build.sh
# Header Created: Tue Oct 01 2024
# Author: Daniel Haddington at <haddingtondaniel5@gmail.com>
# Copyright (c) 2024 Daniel Haddington
#

# Exit script on any error
set -e

# Install necessary packages
echo "Installing necessary packages..."
sudo apt install -y build-essential git libasound2-dev libx11-dev libxrandr-dev libxi-dev \
    libgl1-mesa-dev libglu1-mesa-dev libxcursor-dev libxinerama-dev libwayland-dev libxkbcommon-dev

# Clone Raylib repository if it doesn't already exist
if [ ! -d "raylib" ]; then
    echo "Cloning Raylib..."
    git clone --depth 1 https://github.com/raysan5/raylib.git raylib
else
    echo "Raylib directory already exists, skipping clone."
fi

# Build Raylib
echo "Building Raylib..."
cd raylib/src/
make PLATFORM=PLATFORM_DESKTOP  # To make the static version.
sudo make install
cd ../../

# Build your project (replace 'neo' with your project's actual target name)
echo "Building Project Neo..."
make neo

# Run your project
echo "Running Project Neo..."
./neo
