#include "pch.h"
#include "libTradeTicksAnalyzer/Components/Args/ProgramModeSpecificArgsParserDispatcher.h"
#include "libTradeTicksAnalyzerTests/Components/Args/MetalMock/CalculateTradeTickLatencyStatisticsArgsParserMock.h"
#include "libTradeTicksAnalyzerTests/Components/Args/MetalMock/FindPossibleBadTextTradeTicksArgsParserMock.h"
#include "libTradeTicksAnalyzerTests/Components/Args/MetalMock/ProgramModeDeterminerMock.h"

TESTS(ProgramModeSpecificArgsParserDispatcherTests)
AFACT(ParseDocoptArgs_CalculateTradeTickLatencyStatistics_DoesSo)
AFACT(ParseDocoptArgs_FindPossibleBadTextTradeTicks_DoesSo)
AFACT(ParseDocoptArgs_InvalidProgramMode_ThrowsInvalidArgument)
EVIDENCE

ProgramModeSpecificArgsParserDispatcher _programModeSpecificArgsParserDispatcher;
// Constant Components
FindPossibleBadTextTradeTicksArgsParserMock* _findPossibleBadTextTradeTicksArgsParserMock = nullptr;
CalculateTradeTickLatencyStatisticsArgsParserMock* _calculateTradeTickLatencyStatisticsArgsParserMock = nullptr;
ProgramModeDeterminerMock* _programModeDeterminerMock = nullptr;

STARTUP
{
   // Constant Components
   _programModeSpecificArgsParserDispatcher._findPossibleBadTextTradeTicksArgsParser.reset(_findPossibleBadTextTradeTicksArgsParserMock = new FindPossibleBadTextTradeTicksArgsParserMock);
   _programModeSpecificArgsParserDispatcher._calculateTradeTickLatencyStatisticsArgsParser.reset(_calculateTradeTickLatencyStatisticsArgsParserMock = new CalculateTradeTickLatencyStatisticsArgsParserMock);
   _programModeSpecificArgsParserDispatcher._programModeDeterminer.reset(_programModeDeterminerMock = new ProgramModeDeterminerMock);
}

TEST(ParseDocoptArgs_CalculateTradeTickLatencyStatistics_DoesSo)
{
   _programModeDeterminerMock->DetermineProgramModeMock.Return(ProgramMode::CalculateTradeTickLatencyStatistics);
   const TradeTicksAnalyzerArgs args = _calculateTradeTickLatencyStatisticsArgsParserMock->ParseDocoptArgsMock.ReturnRandom();
   const TradeTicksAnalyzerArgMaps tradeTicksAnalyzerArgMaps = ZenUnit::Random<TradeTicksAnalyzerArgMaps>();
   //
   const TradeTicksAnalyzerArgs returnedArgs = _programModeSpecificArgsParserDispatcher.ParseDocoptArgs(tradeTicksAnalyzerArgMaps);
   //
   METALMOCKTHEN(_programModeDeterminerMock->DetermineProgramModeMock.CalledOnceWith(tradeTicksAnalyzerArgMaps)).Then(
   METALMOCKTHEN(_calculateTradeTickLatencyStatisticsArgsParserMock->ParseDocoptArgsMock.CalledOnceWith(
      tradeTicksAnalyzerArgMaps.docoptArgs_calculate_trade_tick_latency_statistics)));
   ARE_EQUAL(args, returnedArgs);
}

TEST(ParseDocoptArgs_FindPossibleBadTextTradeTicks_DoesSo)
{
   _programModeDeterminerMock->DetermineProgramModeMock.Return(ProgramMode::FindPossibleBadTextTradeTicks);
   const TradeTicksAnalyzerArgs args = _findPossibleBadTextTradeTicksArgsParserMock->ParseDocoptArgsMock.ReturnRandom();
   const TradeTicksAnalyzerArgMaps tradeTicksAnalyzerArgMaps = ZenUnit::Random<TradeTicksAnalyzerArgMaps>();
   //
   const TradeTicksAnalyzerArgs returnedArgs = _programModeSpecificArgsParserDispatcher.ParseDocoptArgs(tradeTicksAnalyzerArgMaps);
   //
   METALMOCKTHEN(_programModeDeterminerMock->DetermineProgramModeMock.CalledOnceWith(tradeTicksAnalyzerArgMaps)).Then(
   METALMOCKTHEN(_findPossibleBadTextTradeTicksArgsParserMock->ParseDocoptArgsMock.CalledOnceWith(
      tradeTicksAnalyzerArgMaps.docoptArgs_find_possible_bad_trade_ticks)));
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
