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
      FIELDS_ARE_EQUAL(expectedTradeTicksAnalyzerArgs, actualTradeTicksAnalyzerArgs, tradingLogsOutputFolderPath);
      FIELDS_ARE_EQUAL(expectedTradeTicksAnalyzerArgs, actualTradeTicksAnalyzerArgs, parallel);
      // Calculated Fields
      FIELDS_ARE_EQUAL(expectedTradeTicksAnalyzerArgs, actualTradeTicksAnalyzerArgs, tradingLogsOutputFolderPath_dateDashRunNumber_Polygon_FilteredRealTimeTextTradeTicks);
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
      randomArgs.parallel = randomGenerator->Bool();
      // Calculated Fields
      randomArgs.tradingLogsOutputFolderPath_dateDashRunNumber_Polygon_FilteredRealTimeTextTradeTicks = randomGenerator->FilesystemPath();
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
