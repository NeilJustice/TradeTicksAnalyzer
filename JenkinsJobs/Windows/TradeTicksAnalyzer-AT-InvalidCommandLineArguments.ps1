AcceptanceRunner.exe run-acceptance-test-with-one-possible-standard-output `
   --acceptance-test-folder="AcceptanceTests\InvalidCommandLineArguments" `
   --program="C:\bin\TradeTicksAnalyzerRelease.exe" `
   --program-args-file="ProgramArgs.txt" `
   --required-standard-output-file="RequiredStandardOutput.txt" `
   --required-text-file-writes-file="ZeroRequiredTextFileWrites.txt" `
   --test-runs=1 `
   --required-exit-code=1
