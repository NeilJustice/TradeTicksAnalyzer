AcceptanceRunner.exe run-acceptance-test-with-multiple-possible-standard-outputs `
   --acceptance-test-folder="AcceptanceTests\FindPossibleBadTextTradeTicks-ParEx" `
   --program="C:\bin\TradeTicksAnalyzerRelease.exe" `
   --program-args-file="ProgramArgs.txt" `
   --required-standard-output-possibilities-file="RequiredStandardOutputPossibilities.txt" `
   --required-text-file-writes-possibilities-folder="ZeroRequiredTextFileWrites" `
   --test-runs=2 `
   --required-exit-code=1 `
   --acceptance-test-results-folder-to-delete-first="X:\AcceptanceTestResults\TradeTicksAnalyzer\FindPossibleBadTextTradeTicks-ParEx"
