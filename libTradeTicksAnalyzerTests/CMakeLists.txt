project(libTradeTicksAnalyzerTests)
include(${CMAKE_SOURCE_DIR}/CMakeMacros.cmake)

if(UNIX)
   find_package(TBB REQUIRED)
endif()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(
   ${CMAKE_SOURCE_DIR}
   ${libCppUtilsIncludeDirectory}
   ${libDateTimeIncludeDirectory}
   ${libFunctionalIncludeDirectory}
   ${ZenUnitAndMetalMockIncludeDirectory})

folder_source_group(Components)
folder_source_group_subfolder(Components Args)
folder_source_group_subsubfolder(Components Args MetalMock)
folder_source_group_subfolder(Components SubPrograms)
folder_source_group_subsubfolder(Components SubPrograms MetalMock)
folder_source_group_subfolder(Components Testing)
folder_source_group_subsubfolder(Components Testing MetalMock)
folder_source_group(Enums)
folder_source_group(ValueTypes)
folder_source_group_subfolder(ValueTypes ZenUnit)

file(GLOB_RECURSE Sources *.h *.cpp)
source_group("" FILES ${Sources})

add_executable(libTradeTicksAnalyzerTests ${Sources})
target_link_libraries(
   libTradeTicksAnalyzerTests
   libTradeTicksAnalyzer
   ${libCppUtilsLibPath}
   ${libDateTimeLibPath}
   ${libFunctionalLibPath})
if(UNIX)
   IfUNIXEnablePrecompiledHeaderAndPossiblyUnityBuildIfNotIncludeWhatYouUseMode(libTradeTicksAnalyzerTests 2)
   target_link_libraries(libTradeTicksAnalyzerTests TBB::tbb)
   set_property(TARGET libTradeTicksAnalyzerTests PROPERTY LINKER_TYPE LLD)
elseif(MSVC)
   IfMSVCSetOptimizationFlags()
   IfMSVCDisableDebugSymbolsIfJenkins()
   IfMSVCAddRunTestsPostBuildStep()
   IfMSVCEnablePrecompiledHeaderAndPossiblyUnityBuild(libTradeTicksAnalyzerTests 2)
endif()
