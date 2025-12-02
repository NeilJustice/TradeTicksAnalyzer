#include "pch.h"
#include "libDateTime/Components/Time/MetalMock/StopwatchMock.h"
#include "libFunctional/Components/FunctionCallers/TryCatchCallers/MetalMock/NonVoidOneArgTryCatchCallerMock.h"
#include "libTradeTicksAnalyzer/Components/TradeTicksAnalyzerProgram.h"
#include "libTradeTicksAnalyzerTests/Components/Args/MetalMock/TradeTicksAnalyzerArgsParserMock.h"
#include "libTradeTicksAnalyzerTests/Components/SubPrograms/MetalMock/SubProgramFactoryMock.h"
#include "libTradeTicksAnalyzerTests/Components/SubPrograms/MetalMock/SubProgramMock.h"

TESTS(TradeTicksAnalyzerProgramTests)
AFACT(DefaultConstructor_SetsTradeTicksAnalyzer)
AFACT(Main_ArgcIs1_WritesCommandLineUsage_Returns0)
AFACT(Main_RunsSubProgram_ReturnsSubProgramExitCode)
AFACT(Run_RunsSubProgram_ReturnsSubProgramExitCode)
AFACT(ExceptionHandler_Run_WritesExceptionClassNameAndMessageInRed_ExitsWithCode1_Returns1)
EVIDENCE

TradeTicksAnalyzerProgram _tradeTicksAnalyzerProgram;
// Function Callers
using _nonVoidOneArgTryCatchCallerMockType = Functional::NonVoidOneArgTryCatchCallerMock<int, TradeTicksAnalyzerProgram, const vector<string>&>;
_nonVoidOneArgTryCatchCallerMockType* _nonVoidOneArgTryCatchCallerMock = nullptr;
// Constant Components
Time::ConsoleMock* _consoleMock = nullptr;
SubProgramFactoryMock* _subProgramFactoryMock = nullptr;
TradeTicksAnalyzerArgsParserMock* _tradeTicksAnalyzerArgsParserMock = nullptr;
// Mutable Components
Time::StopwatchMock* _stopwatchMock = nullptr;

STARTUP
{
   // Function Callers
   _tradeTicksAnalyzerProgram._nonVoidOneArgTryCatchCaller.reset(_nonVoidOneArgTryCatchCallerMock = new _nonVoidOneArgTryCatchCallerMockType);
   // Constant Components
   _tradeTicksAnalyzerProgram._console.reset(_consoleMock = new Time::ConsoleMock);
   _tradeTicksAnalyzerProgram._tradeTicksAnalyzerArgsParser.reset(_tradeTicksAnalyzerArgsParserMock = new TradeTicksAnalyzerArgsParserMock);
   _tradeTicksAnalyzerProgram._subProgramFactory.reset(_subProgramFactoryMock = new SubProgramFactoryMock);
   // Mutable Components
   _tradeTicksAnalyzerProgram._stopwatch.reset(_stopwatchMock = new Time::StopwatchMock);
}

TEST(DefaultConstructor_SetsTradeTicksAnalyzer)
{
   const TradeTicksAnalyzerProgram tradeTicksAnalyzerProgram;
   ARE_EQUAL("TradeTicksAnalyzer", tradeTicksAnalyzerProgram._console->ProgramName());
}

TEST(Main_ArgcIs1_WritesCommandLineUsage_Returns0)
{
   _consoleMock->NakedWriteLineMock.Expect();
   //
   const int exitCode = _tradeTicksAnalyzerProgram.Main(1, nullptr);
   //
   METALMOCK(_consoleMock->NakedWriteLineMock.CalledOnceWith(TradeTicksAnalyzerArgs::CommandLineUsage));
   IS_ZERO(exitCode);
}

TEST(Main_RunsSubProgram_ReturnsSubProgramExitCode)
{
   _stopwatchMock->StartMock.Expect();

   const vector<string> stringArgs = _consoleMock->ArgcArgvToStringVectorMock.ReturnRandom();

   int tryCatchCallReturnValue = ZenUnit::Random<int>();
   _nonVoidOneArgTryCatchCallerMock->TryCatchCallNonConstMemberFunctionMock.Return(tryCatchCallReturnValue);

   const string elapsedSeconds = _stopwatchMock->StopAndGetElapsedSecondsMock.ReturnRandom();

   _consoleMock->WriteProgramNameTimestampedThreadIdLineMock.Expect();

   const int argc = ZenUnit::RandomNotEqualTo<int>(1);
   const string exePath = ZenUnit::Random<string>();
   const string commandLineArgument = ZenUnit::Random<string>();
   const char* argv[] = { exePath.c_str(), commandLineArgument.c_str() };
   //
   const int exitCode = _tradeTicksAnalyzerProgram.Main(argc, const_cast<char**>(argv));
   //
   const string expectedDurationLine = Utils::String::ConcatValues("Duration: ", elapsedSeconds, " seconds");
   const string expectedExitCodeLine = Utils::String::ConcatValues("ExitCode: ", exitCode);
   METALMOCK(_consoleMock->WriteProgramNameTimestampedThreadIdLineMock.CalledNTimes(2));
   METALMOCKTHEN(_stopwatchMock->StartMock.CalledOnce()).Then(
   METALMOCKTHEN(_consoleMock->ArgcArgvToStringVectorMock.CalledOnceWith(argc, const_cast<char**>(argv)))).Then(
   METALMOCKTHEN(_nonVoidOneArgTryCatchCallerMock->TryCatchCallNonConstMemberFunctionMock.CalledOnceWith(
      &_tradeTicksAnalyzerProgram, &TradeTicksAnalyzerProgram::Run, stringArgs,
      &TradeTicksAnalyzerProgram::ExceptionHandler_Run))).Then(
   METALMOCKTHEN(_stopwatchMock->StopAndGetElapsedSecondsMock.CalledOnce())).Then(
   METALMOCKTHEN(_consoleMock->WriteProgramNameTimestampedThreadIdLineMock.CalledWith(expectedDurationLine))).Then(
   METALMOCKTHEN(_consoleMock->WriteProgramNameTimestampedThreadIdLineMock.CalledWith(expectedExitCodeLine)));
   ARE_EQUAL(tryCatchCallReturnValue, exitCode);
}

TEST(Run_RunsSubProgram_ReturnsSubProgramExitCode)
{
   const TradeTicksAnalyzerArgs args = _tradeTicksAnalyzerArgsParserMock->ParseStringArgsMock.ReturnRandom();

   shared_ptr<SubProgramMock> subProgramMock = make_shared<SubProgramMock>();
   subProgramMock->InitializeMock.Expect();
   subProgramMock->DerivedInitializeMock.Expect();
   const int runReturnValue = subProgramMock->RunMock.ReturnRandom();
   _subProgramFactoryMock->NewSubProgramMock.Return(subProgramMock);

   const vector<string> stringArgs = ZenUnit::RandomVector<string>();
   //
   const int exitCode = _tradeTicksAnalyzerProgram.Run(stringArgs);
   //
   METALMOCKTHEN(_tradeTicksAnalyzerArgsParserMock->ParseStringArgsMock.CalledOnceWith(stringArgs)).Then(
   METALMOCKTHEN(_subProgramFactoryMock->NewSubProgramMock.CalledOnceWith(args.programMode))).Then(
   METALMOCKTHEN(subProgramMock->InitializeMock.CalledOnceWith(args))).Then(
   METALMOCKTHEN(subProgramMock->DerivedInitializeMock.CalledOnce())).Then(
   METALMOCKTHEN(subProgramMock->RunMock.CalledOnce()));
   ARE_EQUAL(runReturnValue, exitCode);
}

TEST(ExceptionHandler_Run_WritesExceptionClassNameAndMessageInRed_ExitsWithCode1_Returns1)
{
   _consoleMock->WriteEnhancedExceptionInRedThenExit1AfterOptionalWaitForEnterKeyMock.Expect();
   const string exceptionClassNameAndMessage = ZenUnit::Random<string>();
   const vector<string> stringArgs = ZenUnit::RandomVector<string>();
   //
   const int exitCode = _tradeTicksAnalyzerProgram.ExceptionHandler_Run(exceptionClassNameAndMessage, stringArgs);
   //
   METALMOCK(_consoleMock->WriteEnhancedExceptionInRedThenExit1AfterOptionalWaitForEnterKeyMock.CalledOnceWith(
      exceptionClassNameAndMessage, "", false));
   ARE_EQUAL(1, exitCode);
}

RUN_TESTS(TradeTicksAnalyzerProgramTests)
