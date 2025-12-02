#!/bin/bash
set -eu

export CXX=clang++
LinuxCPlusPlusBuilder build-cpp-program \
   --solution-name=TradeTicksAnalyzer \
   --configuration=RelWithDebInfo \
   --cmake-definitions="-DClangUndefinedBehaviorSanitizerMode=ON" \
   --install=false
