#include "libCppUtils/Compiler/IfWindowsIgnoreTheseWarningsGlobally.h"
#include <memory>
#include <string>
#include <vector>
using namespace std;
#include "libTradeTicksAnalyzer/Components/TradeTicksAnalyzerProgram.h"

// calculate-trade-tick-latencies --required-string=String --parallel

// find-possible-bad-trade-ticks --required-string=String --parallel

// Acceptance Tests
// ================
// TradeTicksAnalyzer-AT-InvalidCommandLineArguments
// invalid_program_mode
// C:\Code\TradeTicksAnalyzer\AcceptanceTests\InvalidCommandLineArguments

int main(int argc, char* argv[])
{
   TradeTicksAnalyzerProgram tradeTicksAnalyzerProgram;
   int exitCode = tradeTicksAnalyzerProgram.Main(argc, argv);
   return exitCode;
}
