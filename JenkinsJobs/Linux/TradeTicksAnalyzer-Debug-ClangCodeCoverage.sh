#!/usr/bin/bash
set -eu

export CXX=clang++
LinuxCPlusPlusBuilder build-cpp-program \
   --solution-name=TradeTicksAnalyzer \
   --configuration=Debug \
   --cmake-definitions="-DClangCodeCoverageMode=ON" \
   --install=false

LinuxCodeCoverageRunner measure-cplusplus-code-coverage --solution=TradeTicksAnalyzer --tests-project=libTradeTicksAnalyzerTests
