#!/bin/bash

Release() {
  echo "Release Build"
  cmake -DCMAKE_BUILD_TYPE=Debug $1
  make
  cpack -G DEB
  cpack -G TGZ
}

Debug() {
  echo "Debug Build"
  cmake -DCMAKE_BUILD_TYPE=Debug $1
  make
  make coverage
}

Both() {
  mkdir Release
  cd Release
  Release "../.."

  cd ".." || exit
  echo

  mkdir Debug
  cd Debug
  Debug "../.."
}

# Make a build directory, if one does not already exist
install -d build
cd build

# Clear build directory of any build artifacts
rm -rf ./*

# Build k-means-cpp
if [ "$1" == "Release" ]; then
  Release ..
elif [ "$1" == "Debug" ]; then
  Debug ..
else
  Both
fi