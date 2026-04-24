#!/bin/bash
set -e

echo "== Configuring =="
cmake -B build_linux -DCMAKE_BUILD_TYPE=Release

echo "== Building =="
cmake --build build_linux

echo "== Packaging =="
cd build_linux
zip -r ../sdl3-demo-linux.zip sdl3-demo resources/
cd ..

echo ""
echo "Build complete. Release zip: sdl3-demo-linux.zip"
