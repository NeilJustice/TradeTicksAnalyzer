#include "libCppUtils/Compiler/IfWindowsIgnoreTheseWarningsGlobally.h"
#include <memory>
#include <string>
#include <vector>
using namespace std;
#include "libTradeTicksAnalyzer/Components/TradeTicksAnalyzerProgram.h"

// Production Args
// ===============
// find-possible-bad-binary-trade-ticks --trading-logs-input-folder=X:\Trading\TradingProgram\PaperTradingLogs --date=2025-12-02T --trading-logs-output-folder=X:\Trading\TradingProgram\PaperTradingLogs
// find-possible-bad-binary-trade-ticks --trading-logs-input-folder=X:\Trading\TradingProgram\PaperTradingLogs --date=2025-12-02T --trading-logs-output-folder=X:\Trading\TradingProgram\PaperTradingLogs --parallel

// find-possible-bad-text-trade-ticks --trading-logs-input-folder=X:\Trading\TradingProgram\PaperTradingLogsReplay --date=2025-12-02T --run-number=12 --trading-logs-output-folder=X:\Trading\TradingProgram\PaperTradingLogsReplay
// find-possible-bad-text-trade-ticks --trading-logs-input-folder=X:\Trading\TradingProgram\PaperTradingLogsReplay --date=2025-12-02T --run-number=12 --trading-logs-output-folder=X:\Trading\TradingProgram\PaperTradingLogsReplay --parallel

// Acceptance Tests
// ================
// InvalidCommandLineArguments
// invalid_program_mode
// C:\Code\TradeTicksAnalyzer\AcceptanceTests\InvalidCommandLineArguments

int main(int argc, char* argv[])
{
   TradeTicksAnalyzerProgram tradeTicksAnalyzerProgram;
   int exitCode = tradeTicksAnalyzerProgram.Main(argc, argv);
   return exitCode;
}
