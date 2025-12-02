#!/bin/bash
set -eu

export CXX=clang++
LinuxCPlusPlusBuilder build-cpp-program \
   --solution-name=TradeTicksAnalyzer \
   --configuration=RelWithDebInfo \
   --cmake-definitions="-DFastLinuxReleaseBuildMode=ON" \
   --install=true
