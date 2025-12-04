project(libTradeTicksAnalyzer)
include(${CMAKE_SOURCE_DIR}/CMakeMacros.cmake)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(
   ${CMAKE_SOURCE_DIR}
   ${libCppUtilsIncludeDirectory}
   ${libDateTimeIncludeDirectory}
   ${libFunctionalIncludeDirectory}
   ${libSymbologyIncludeDirectory}
   ${libTickDataIncludeDirectory}
   ${ZenUnitAndMetalMockIncludeDirectory})

folder_source_group(Components)
folder_source_group_subfolder(Components Args)
folder_source_group_subfolder(Components Finders)
folder_source_group_subfolder(Components MessageWriters)
folder_source_group_subfolder(Components SubPrograms)
folder_source_group(Enums)
folder_source_group(ValueTypes)

file(GLOB_RECURSE Sources *.h *.cpp *.ui)
source_group("" FILES ${Sources})

add_library(libTradeTicksAnalyzer ${Sources})
if(UNIX)
   IfMSVCEnablePrecompiledHeaderAndPossiblyUnityBuild(libTradeTicksAnalyzer 2)
elseif(MSVC)
   IfMSVCSetOptimizationFlags()
   IfMSVCDisableDebugSymbolsIfJenkins()
   IfUNIXEnablePrecompiledHeaderAndPossiblyUnityBuildIfNotIncludeWhatYouUseMode(libTradeTicksAnalyzer 2)
endif()
