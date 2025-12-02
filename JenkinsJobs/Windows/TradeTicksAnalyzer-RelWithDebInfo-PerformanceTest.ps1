WindowsCPlusPlusBuilder.exe build-cpp-program `
   --solution-name=TradeTicksAnalyzer `
   --configuration=RelWithDebInfo `
   --install=false
if ($LastExitCode -ne 0) { exit $LastExitCode }
Write-Host

.\"MarketDataGeneratorScripts\GenerateMarketDataForPerformanceTest.ps1"
if ($LastExitCode -ne 0) { exit $LastExitCode }
Write-Host

AcceliTune.exe measure-program-run-time `
   --app-working-dir="TradeTicksAnalyzer\RelWithDebInfo" `
   --program=TradeTicksAnalyzer.exe `
   --args="" `
   --results-file="C:\Code\PerformanceTestResults\TradeTicksAnalyzerPerformance.txt"
