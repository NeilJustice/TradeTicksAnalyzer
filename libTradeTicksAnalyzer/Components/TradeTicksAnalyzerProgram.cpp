#include "pch.h"
#include "libDateTime/Components/Time/Stopwatch.h"
#include "libFunctional/Components/FunctionCallers/TryCatchCallers/NonVoidOneArgTryCatchCaller.h"
#include "libTradeTicksAnalyzer/Components/Args/TradeTicksAnalyzerArgsParser.h"
#include "libTradeTicksAnalyzer/Components/TradeTicksAnalyzerProgram.h"
#include "libTradeTicksAnalyzer/Components/SubPrograms/SubProgram.h"
#include "libTradeTicksAnalyzer/Components/SubPrograms/SubProgramFactory.h"

TradeTicksAnalyzerProgram::TradeTicksAnalyzerProgram()
   // Function Callers
   : _nonVoidOneArgTryCatchCaller(make_unique<_nonVoidOneArgTryCatchCallerType>())
   // Constant Components
   , _console(make_unique<Time::Console>("TradeTicksAnalyzer"))
   , _tradeTicksAnalyzerArgsParser(make_unique<TradeTicksAnalyzerArgsParser>())
   , _subProgramFactory(make_unique<SubProgramFactory>())
   // Mutable Components
   , _stopwatch(make_unique<Time::Stopwatch>())
{
}

TradeTicksAnalyzerProgram::~TradeTicksAnalyzerProgram()
{
}

int TradeTicksAnalyzerProgram::Main(int argc, char* argv[])
{
   if (argc == 1)
   {
      _console->NakedWriteLine(TradeTicksAnalyzerArgs::CommandLineUsage);
      return 0;
   }
   _stopwatch->Start();
   const vector<string> stringArgs = _console->ArgcArgvToStringVector(argc, argv);
   int exitCode = _nonVoidOneArgTryCatchCaller->TryCatchCallNonConstMemberFunction(
      this, &TradeTicksAnalyzerProgram::Run, stringArgs,
      &TradeTicksAnalyzerProgram::ExceptionHandler_Run);
   const string elapsedSeconds = _stopwatch->StopAndGetElapsedSeconds();
   const string durationLine = Utils::String::ConcatValues("Duration: ", elapsedSeconds, " seconds");
   _console->WriteProgramNameTimestampedThreadIdLine(durationLine);
   const string exitCodeLine = Utils::String::ConcatValues("ExitCode: ", exitCode);
   _console->WriteProgramNameTimestampedThreadIdLine(exitCodeLine);
   return exitCode;
}

int TradeTicksAnalyzerProgram::Run(const vector<string>& stringArgs)
{
   const TradeTicksAnalyzerArgs args = _tradeTicksAnalyzerArgsParser->ParseStringArgs(stringArgs);
   const shared_ptr<SubProgram> subProgram = _subProgramFactory->NewSubProgram(args.programMode);
   subProgram->Initialize(args);
   subProgram->DerivedInitialize();
   int exitCode = subProgram->Run();
   return exitCode;
}

int TradeTicksAnalyzerProgram::ExceptionHandler_Run(
   string_view exceptionClassNameAndMessage, const vector<string>& /*stringArgs*/) const
{
   _console->WriteEnhancedExceptionInRedThenExit1AfterOptionalWaitForEnterKey(exceptionClassNameAndMessage, "", false);
   return 1;
}
