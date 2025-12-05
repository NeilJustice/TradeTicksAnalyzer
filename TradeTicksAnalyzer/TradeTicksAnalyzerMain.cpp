#include "libCppUtils/Compiler/IfWindowsIgnoreTheseWarningsGlobally.h"
#include <memory>
#include <string>
#include <vector>
using namespace std;
#include "libTradeTicksAnalyzer/Components/TradeTicksAnalyzerProgram.h"

// Production Args
// ===============
// find-possible-bad-binary-trade-ticks --trading-logs-input-folder=X:\Trading\TradingProgram\PaperTradingLogs --date=2025-12-02T --bad-tick-change-percent-threshold=0.5 --trading-logs-output-folder=X:\Trading\TradingProgram\PaperTradingLogs
// find-possible-bad-binary-trade-ticks --trading-logs-input-folder=X:\Trading\TradingProgram\PaperTradingLogs --date=2025-12-02T --bad-tick-change-percent-threshold=0.5 --trading-logs-output-folder=X:\Trading\TradingProgram\PaperTradingLogs --parallel

// find-possible-bad-text-trade-ticks --trading-logs-input-folder=X:\Trading\TradingProgram\PaperTradingLogsReplay --date=2025-12-05F --run-number=3 --bad-tick-change-percent-threshold=0.5 --trading-logs-output-folder=X:\Trading\TradingProgram\PaperTradingLogsReplay
// find-possible-bad-text-trade-ticks --trading-logs-input-folder=X:\Trading\TradingProgram\PaperTradingLogsReplay --date=2025-12-05F --run-number=3 --bad-tick-change-percent-threshold=0.5 --trading-logs-output-folder=X:\Trading\TradingProgram\PaperTradingLogsReplay --parallel

// find-possible-bad-text-trade-ticks --trading-logs-input-folder=X:\Trading\TradingProgram\PaperTradingLogsReplay --date=2025-12-02T --run-number=12 --bad-tick-change-percent-threshold=0.5 --trading-logs-output-folder=X:\Trading\TradingProgram\PaperTradingLogsReplay
// find-possible-bad-text-trade-ticks --trading-logs-input-folder=X:\Trading\TradingProgram\PaperTradingLogsReplay --date=2025-12-02T --run-number=12 --bad-tick-change-percent-threshold=0.5 --trading-logs-output-folder=X:\Trading\TradingProgram\PaperTradingLogsReplay --parallel

// Acceptance Tests
// ================
// FindPossibleBadTextTradeTicks-Par
// find-possible-bad-text-trade-ticks --trading-logs-input-folder=InputFiles\TradingLogs --date=YYYY-MM-DDM --run-number=1 --bad-tick-change-percent-threshold=2.0 --trading-logs-output-folder=X:\AcceptanceTestResults\TradeTicksAnalyzer\FindPossibleBadTextTradeTicks-Par\TradingLogs --parallel
// C:\Code\TradeTicksAnalyzer\AcceptanceTests\FindPossibleBadTextTradeTicks-Par

// FindPossibleBadTextTradeTicks-ParEx
// find-possible-bad-text-trade-ticks --trading-logs-input-folder=InputFiles\TradingLogs --date=YYYY-MM-DDM --run-number=1 --bad-tick-change-percent-threshold=1.0 --trading-logs-output-folder=X:\AcceptanceTestResults\TradeTicksAnalyzer\FindPossibleBadTextTradeTicks-ParEx\TradingLogs --parallel
// C:\Code\TradeTicksAnalyzer\AcceptanceTests\FindPossibleBadTextTradeTicks-ParEx

// FindPossibleBadTextTradeTicks-Seq
// find-possible-bad-text-trade-ticks --trading-logs-input-folder=InputFiles\TradingLogs --date=YYYY-MM-DDM --run-number=1 --bad-tick-change-percent-threshold=1.0 --trading-logs-output-folder=X:\AcceptanceTestResults\TradeTicksAnalyzer\FindPossibleBadTextTradeTicks-Seq\TradingLogs
// C:\Code\TradeTicksAnalyzer\AcceptanceTests\FindPossibleBadTextTradeTicks-Seq

// InvalidCommandLineArguments
// invalid_program_mode
// C:\Code\TradeTicksAnalyzer\AcceptanceTests\InvalidCommandLineArguments

int main(int argc, char* argv[])
{
   TradeTicksAnalyzerProgram tradeTicksAnalyzerProgram;
   int exitCode = tradeTicksAnalyzerProgram.Main(argc, argv);
   return exitCode;
}
