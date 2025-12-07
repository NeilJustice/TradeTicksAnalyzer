TradeTicksGenerator.exe create-real-time-text-trade-ticks-file `
   --scenario=TradeTicksAnalyzerTesting_AllGood `
   --symbol-number=1 `
   --output-folder="InputFiles\TradingLogs\YYYY-MM-DDM-1\Polygon\FilteredRealTimeTextTradeTicks"
if ($LastExitCode -ne 0) { exit $LastExitCode }
Write-Host

TradeTicksGenerator.exe create-real-time-text-trade-ticks-file `
   --scenario=TradeTicksAnalyzerTesting_SomeBad `
   --symbol-number=2 `
   --output-folder="InputFiles\TradingLogs\YYYY-MM-DDM-1\Polygon\FilteredRealTimeTextTradeTicks"
