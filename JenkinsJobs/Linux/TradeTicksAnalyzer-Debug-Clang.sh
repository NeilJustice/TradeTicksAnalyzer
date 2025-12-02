#!/usr/bin/bash
set -eu

export CXX=clang++
LinuxCPlusPlusBuilder build-cpp-program \
   --solution-name=TradeTicksAnalyzer \
   --configuration=Debug \
   --cmake-definitions="-DFastLinuxDebugBuildMode=ON" \
   --install=false
