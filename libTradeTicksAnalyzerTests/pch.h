#pragma once
#include "libCppUtils/Compiler/IfWindowsIgnoreTheseWarningsGlobally.h"
#include <filesystem>
namespace fs = std::filesystem;
using namespace std;

#include "ZenUnitAndMetalMock/MetalMock.h"

// libCppUtils StaticUtilities
#include "libCppUtils/StaticUtilities/StringUtil.h"

// libDateTime Components
#include "libDateTime/Components/Args/MetalMock/DocoptParserMock.h"
#include "libDateTime/Components/Console/MetalMock/ConsoleMock.h"
#include "libDateTime/Components/Random/MetalMock/TimeRandomGeneratorMock.h"

// libTradeTicksAnalyzer Enums
#include "libTradeTicksAnalyzer/Enums/ProgramMode.h"
// libTradeTicksAnalyzer ValueTypes
#include "libTradeTicksAnalyzerTests/ValueTypes/ZenUnit/TradeTicksAnalyzerArgsEqualizerAndRandom.h"
#include "libTradeTicksAnalyzerTests/ValueTypes/ZenUnit/TradeTicksAnalyzerArgMapsEqualizerAndRandom.h"
// libTradeTicksAnalyzer Components
#include "libTradeTicksAnalyzerTests/Components/Testing/MetalMock/TradeTicksAnalyzerRandomGeneratorMock.h"

// libTickData ValueTypes
#include "libTickData/ValueTypes/ZenUnit/TradeTicksFileContentEqualizerAndRandom.h"
#include "libTickData/ValueTypes/ZenUnit/TradeTickEqualizerAndRandom.h"
