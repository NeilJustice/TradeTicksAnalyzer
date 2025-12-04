AcceptanceRunner.exe run-acceptance-test-with-one-possible-standard-output `
   --acceptance-test-folder="AcceptanceTests\FindPossibleBadTextTradeTicks-Seq" `
   --program="C:\bin\TradeTicksAnalyzerRelease.exe" `
   --program-args-file="ProgramArgs.txt" `
   --required-standard-output-file="RequiredStandardOutput.txt" `
   --required-text-file-writes-file="RequiredTextFileWrites.txt" `
   --test-runs=2 `
   --required-exit-code=0 `
   --acceptance-test-results-folder-to-delete-first="X:\AcceptanceTestResults\TradeTicksAnalyzer\FindPossibleBadTextTradeTicks-Seq"
