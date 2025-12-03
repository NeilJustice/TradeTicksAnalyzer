#include "libCppUtils/Compiler/IfWindowsIgnoreTheseWarningsGlobally.h"
#include <memory>
#include <string>
#include <vector>
using namespace std;
#include "libTradeTicksAnalyzer/Components/TradeTicksAnalyzerProgram.h"

// Production Args
// ===============
// calculate-trade-tick-latency-statistics --trading-logs-folder=X:\Trading\TradingProgram\PaperTradingLogs --date=2025-12-02T
// calculate-trade-tick-latency-statistics --trading-logs-folder=X:\Trading\TradingProgram\PaperTradingLogs --date=2025-12-02T --parallel

// find-possible-bad-trade-ticks --trading-logs-folder=X:\Trading\TradingProgram\PaperTradingLogs --date=2025-12-02T --run-number=12 --output-folder=X:\Trading\TradingProgram\PaperTradingLogs
// find-possible-bad-trade-ticks --trading-logs-folder=X:\Trading\TradingProgram\PaperTradingLogs --date=2025-12-02T --run-number=12 --output-folder=X:\Trading\TradingProgram\PaperTradingLogs --parallel

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
