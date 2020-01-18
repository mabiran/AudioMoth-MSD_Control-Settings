#!/bin/bash
BUILD_FOLDER="build"
RELEASE_FOLDER="release"

rm -rf "$BUILD_FOLDER"
mkdir "$BUILD_FOLDER"
cd "$BUILD_FOLDER"
cmake -DCMAKE_BUILD_TYPE=Release ..
make
cd ..
mkdir -p "$RELEASE_FOLDER"
cp "$BUILD_FOLDER"/AudioMoth-Project.bin "$RELEASE_FOLDER"
rm -rf "$BUILD_FOLDER"
