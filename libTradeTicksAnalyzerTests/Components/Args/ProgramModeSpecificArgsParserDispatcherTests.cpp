#include "pch.h"
#include "libTradeTicksAnalyzer/Components/Args/ProgramModeSpecificArgsParserDispatcher.h"
#include "libTradeTicksAnalyzerTests/Components/Args/MetalMock/FindPossibleBadTradeTicksArgsParserMock.h"
#include "libTradeTicksAnalyzerTests/Components/Args/MetalMock/ProgramModeBArgsParserMock.h"
#include "libTradeTicksAnalyzerTests/Components/Args/MetalMock/ProgramModeDeterminerMock.h"

TESTS(ProgramModeSpecificArgsParserDispatcherTests)
AFACT(ParseDocoptArgs_FindPossibleBadTradeTicks_DoesSo)
AFACT(ParseDocoptArgs_ProgramModeB_DoesSo)
AFACT(ParseDocoptArgs_InvalidProgramMode_ThrowsInvalidArgument)
EVIDENCE

ProgramModeSpecificArgsParserDispatcher _programModeSpecificArgsParserDispatcher;
// Constant Components
FindPossibleBadTradeTicksArgsParserMock* _findPossibleBadTradeTicksArgsParserMock = nullptr;
ProgramModeBArgsParserMock* _programModeBArgsParserMock = nullptr;
ProgramModeDeterminerMock* _programModeDeterminerMock = nullptr;

STARTUP
{
   // Constant Components
   _programModeSpecificArgsParserDispatcher._findPossibleBadTradeTicksArgsParser.reset(_findPossibleBadTradeTicksArgsParserMock = new FindPossibleBadTradeTicksArgsParserMock);
   _programModeSpecificArgsParserDispatcher._programModeBArgsParser.reset(_programModeBArgsParserMock = new ProgramModeBArgsParserMock);
   _programModeSpecificArgsParserDispatcher._programModeDeterminer.reset(_programModeDeterminerMock = new ProgramModeDeterminerMock);
}

TEST(ParseDocoptArgs_FindPossibleBadTradeTicks_DoesSo)
{
   _programModeDeterminerMock->DetermineProgramModeMock.Return(ProgramMode::FindPossibleBadTradeTicks);
   const TradeTicksAnalyzerArgs args = _findPossibleBadTradeTicksArgsParserMock->ParseDocoptArgsMock.ReturnRandom();
   const TradeTicksAnalyzerArgMaps tradeTicksAnalyzerArgMaps = ZenUnit::Random<TradeTicksAnalyzerArgMaps>();
   //
   const TradeTicksAnalyzerArgs returnedArgs = _programModeSpecificArgsParserDispatcher.ParseDocoptArgs(tradeTicksAnalyzerArgMaps);
   //
   METALMOCKTHEN(_programModeDeterminerMock->DetermineProgramModeMock.CalledOnceWith(tradeTicksAnalyzerArgMaps)).Then(
   METALMOCKTHEN(_findPossibleBadTradeTicksArgsParserMock->ParseDocoptArgsMock.CalledOnceWith(tradeTicksAnalyzerArgMaps.docoptArgs_calculate_trade_tick_latency_statistics)));
   ARE_EQUAL(args, returnedArgs);
}

TEST(ParseDocoptArgs_ProgramModeB_DoesSo)
{
   _programModeDeterminerMock->DetermineProgramModeMock.Return(ProgramMode::ProgramModeB);
   const TradeTicksAnalyzerArgs args = _programModeBArgsParserMock->ParseDocoptArgsMock.ReturnRandom();
   const TradeTicksAnalyzerArgMaps tradeTicksAnalyzerArgMaps = ZenUnit::Random<TradeTicksAnalyzerArgMaps>();
   //
   const TradeTicksAnalyzerArgs returnedArgs = _programModeSpecificArgsParserDispatcher.ParseDocoptArgs(tradeTicksAnalyzerArgMaps);
   //
   METALMOCKTHEN(_programModeDeterminerMock->DetermineProgramModeMock.CalledOnceWith(tradeTicksAnalyzerArgMaps)).Then(
   METALMOCKTHEN(_programModeBArgsParserMock->ParseDocoptArgsMock.CalledOnceWith(tradeTicksAnalyzerArgMaps.docoptArgs_find_possible_bad_trade_ticks)));
   ARE_EQUAL(args, returnedArgs);
}

TEST(ParseDocoptArgs_InvalidProgramMode_ThrowsInvalidArgument)
{
   _programModeDeterminerMock->DetermineProgramModeMock.Return(ProgramMode::Invalid);
   const TradeTicksAnalyzerArgMaps tradeTicksAnalyzerArgMaps = ZenUnit::Random<TradeTicksAnalyzerArgMaps>();
   //
   const string expectedExceptionMessage = Utils::String::ConcatStrings(
      "Invalid command line usage.\n\n", TradeTicksAnalyzerArgs::CommandLineUsage);
   THROWS_EXCEPTION(_programModeSpecificArgsParserDispatcher.ParseDocoptArgs(tradeTicksAnalyzerArgMaps),
      invalid_argument, expectedExceptionMessage);
   //
   METALMOCK(_programModeDeterminerMock->DetermineProgramModeMock.CalledOnceWith(tradeTicksAnalyzerArgMaps));
}

RUN_TESTS(ProgramModeSpecificArgsParserDispatcherTests)
