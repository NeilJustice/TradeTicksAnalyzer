project(TradeTicksAnalyzer)
include(${CMAKE_SOURCE_DIR}/CMakeMacros.cmake)

if(UNIX)
   find_package(TBB REQUIRED)
endif()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(
   ${CMAKE_SOURCE_DIR}
   ${libCppUtilsIncludeDirectory})

file(GLOB_RECURSE Sources *.h *.cpp)
source_group("" FILES ${Sources})

add_executable(TradeTicksAnalyzer ${Sources})
target_link_libraries(
   TradeTicksAnalyzer
   libTradeTicksAnalyzer
   ${libCppUtilsLibPath}
   ${libDateTimeLibPath}
   ${libFunctionalLibPath})
if(UNIX)
   target_link_libraries(TradeTicksAnalyzer TBB::tbb)
   set_property(TARGET TradeTicksAnalyzer PROPERTY LINKER_TYPE LLD)
elseif(MSVC)
   IfMSVCSetOptimizationFlags()
   IfMSVCDisableDebugSymbolsIfJenkins()
endif()

SetBinaryOutputNames(TradeTicksAnalyzer programname)
