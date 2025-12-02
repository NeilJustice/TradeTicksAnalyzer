#pragma once
#include "libCppUtils/Compiler/IfWindowsIgnoreTheseWarningsGlobally.h"
#include <filesystem>
#include <mutex>
namespace fs = std::filesystem;
using namespace std;

// libCppUtils StaticUtilities
#include "libCppUtils/StaticUtilities/StringUtil.h"

// libDateTime Components
#include "libDateTime/Components/Args/DocoptParser.h"
#include "libDateTime/Components/Console/Console.h"

// libTradeTicksAnalyzer Enums
#include "libTradeTicksAnalyzer/Enums/ProgramMode.h"
// libTradeTicksAnalyzer ValueTypes
#include "libTradeTicksAnalyzer/ValueTypes/TradeTicksAnalyzerArgs.h"
#include "libTradeTicksAnalyzer/ValueTypes/TradeTicksAnalyzerArgMaps.h"
