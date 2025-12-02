cmake_minimum_required(VERSION 3.18)
project(TradeTicksAnalyzer)
include(${CMAKE_SOURCE_DIR}/CMakeMacros.cmake)

SetLinuxOrWindowsCompilerFlags()

add_subdirectory(TradeTicksAnalyzer)
add_subdirectory(libTradeTicksAnalyzer)
add_subdirectory(libTradeTicksAnalyzerTests)
