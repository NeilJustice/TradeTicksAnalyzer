WindowsCPlusPlusBuilder.exe build-cpp-program `
   --solution-name=TradeTicksAnalyzer `
   --configuration=RelWithDebInfo `
   --install=false
if ($LastExitCode -ne 0) { exit $LastExitCode }
Write-Host

.\"MarketDataGeneratorScripts\GenerateMarketDataForSequentialProfiling.ps1" "VTuneHotspots"
if ($LastExitCode -ne 0) { exit $LastExitCode }
Write-Host

AcceliTune.exe collect-hotspots `
   --app-working-dir="TradeTicksAnalyzer\RelWithDebInfo" `
   --program=TradeTicksAnalyzer.exe `
   --args="" `
   --results-folder="D:\PerformanceProfilingResults\VTune\TradeTicksAnalyzer_Hotspots" `
   --overwrite-results-folder
