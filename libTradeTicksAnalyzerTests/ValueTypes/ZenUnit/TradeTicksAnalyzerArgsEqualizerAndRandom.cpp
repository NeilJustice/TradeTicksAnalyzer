#include "pch.h"
#include "libTradeTicksAnalyzerTests/ValueTypes/ZenUnit/TradeTicksAnalyzerArgsEqualizerAndRandom.h"

namespace ZenUnit
{
   void Equalizer<TradeTicksAnalyzerArgs>::AssertEqual(
      const TradeTicksAnalyzerArgs& expectedTradeTicksAnalyzerArgs, const TradeTicksAnalyzerArgs& actualTradeTicksAnalyzerArgs)
   {
      FIELDS_ARE_EQUAL(expectedTradeTicksAnalyzerArgs, actualTradeTicksAnalyzerArgs, programMode);
      FIELDS_ARE_EQUAL(expectedTradeTicksAnalyzerArgs, actualTradeTicksAnalyzerArgs, tradingLogsInputFolderPath);
      FIELDS_ARE_EQUAL(expectedTradeTicksAnalyzerArgs, actualTradeTicksAnalyzerArgs, dateWithDayOfWeek);
      FIELDS_ARE_EQUAL(expectedTradeTicksAnalyzerArgs, actualTradeTicksAnalyzerArgs, runNumber);
      FIELDS_ARE_EQUAL(expectedTradeTicksAnalyzerArgs, actualTradeTicksAnalyzerArgs, badTickChangePercentThreshold);
      FIELDS_ARE_EQUAL(expectedTradeTicksAnalyzerArgs, actualTradeTicksAnalyzerArgs, tradingLogsOutputFolderPath);
      FIELDS_ARE_EQUAL(expectedTradeTicksAnalyzerArgs, actualTradeTicksAnalyzerArgs, parallel);
      // Calculated Fields
      FIELDS_ARE_EQUAL(expectedTradeTicksAnalyzerArgs, actualTradeTicksAnalyzerArgs, tradingLogsInputFolderPath_dateDashRunNumber_Polygon_FilteredRealTimeTextTradeTicks);
      FIELDS_ARE_EQUAL(expectedTradeTicksAnalyzerArgs, actualTradeTicksAnalyzerArgs, tradingLogsOutputFolderPath_dateDashRunNumber_Polygon_FilteredRealTimeTextTradeTicksDashPossibleBad);
   }

   TradeTicksAnalyzerArgs TestableRandomTradeTicksAnalyzerArgs(
      const RandomGenerator* randomGenerator,
      const Time::TimeRandomGenerator* timeRandomGenerator,
      const TradeTicksAnalyzerRandomGenerator* tradeTicksAnalyzerRandomGenerator)
   {
      TradeTicksAnalyzerArgs randomArgs;
      randomArgs.programMode = tradeTicksAnalyzerRandomGenerator->RandomProgramMode();
      randomArgs.tradingLogsInputFolderPath = randomGenerator->FilesystemPath();
      randomArgs.dateWithDayOfWeek = timeRandomGenerator->RandomDateWithDayOfWeek();
      randomArgs.runNumber = randomGenerator->Unsigned();
      randomArgs.badTickChangePercentThreshold = randomGenerator->Float();
      randomArgs.tradingLogsOutputFolderPath = randomGenerator->FilesystemPath();
      randomArgs.parallel = randomGenerator->Bool();
      // Calculated Fields
      randomArgs.tradingLogsInputFolderPath_dateDashRunNumber_Polygon_FilteredRealTimeTextTradeTicks = randomGenerator->FilesystemPath();
      randomArgs.tradingLogsOutputFolderPath_dateDashRunNumber_Polygon_FilteredRealTimeTextTradeTicksDashPossibleBad = randomGenerator->FilesystemPath();
      return randomArgs;
   }

   template<>
   TradeTicksAnalyzerArgs Random()
   {
      return TestableRandomTradeTicksAnalyzerArgs(
         RandomGenerator::Instance(),
         Time::TimeRandomGenerator::Instance(),
         TradeTicksAnalyzerRandomGenerator::Instance());
   }
}
