#include "pch.h"
#include "libTradeTicksAnalyzerTests/ValueTypes/ZenUnit/TradeTicksAnalyzerArgsEqualizerAndRandom.h"

namespace ZenUnit
{
   void Equalizer<TradeTicksAnalyzerArgs>::AssertEqual(
      const TradeTicksAnalyzerArgs& expectedTradeTicksAnalyzerArgs, const TradeTicksAnalyzerArgs& actualTradeTicksAnalyzerArgs)
   {
      FIELDS_ARE_EQUAL(expectedTradeTicksAnalyzerArgs, actualTradeTicksAnalyzerArgs, programMode);
      FIELDS_ARE_EQUAL(expectedTradeTicksAnalyzerArgs, actualTradeTicksAnalyzerArgs, tradingLogsInputFolderPath);
      FIELDS_ARE_EQUAL(expectedTradeTicksAnalyzerArgs, actualTradeTicksAnalyzerArgs, date);
      FIELDS_ARE_EQUAL(expectedTradeTicksAnalyzerArgs, actualTradeTicksAnalyzerArgs, runNumber);
      FIELDS_ARE_EQUAL(expectedTradeTicksAnalyzerArgs, actualTradeTicksAnalyzerArgs, outputFolderPath);
      FIELDS_ARE_EQUAL(expectedTradeTicksAnalyzerArgs, actualTradeTicksAnalyzerArgs, parallel);
   }

   TradeTicksAnalyzerArgs TestableRandomTradeTicksAnalyzerArgs(
      const RandomGenerator* randomGenerator,
      const Time::TimeRandomGenerator* timeRandomGenerator,
      const TradeTicksAnalyzerRandomGenerator* tradeTicksAnalyzerRandomGenerator)
   {
      TradeTicksAnalyzerArgs randomArgs;
      randomArgs.programMode = tradeTicksAnalyzerRandomGenerator->RandomProgramMode();
      randomArgs.tradingLogsInputFolderPath = randomGenerator->FilesystemPath();
      randomArgs.date = timeRandomGenerator->RandomDate();
      randomArgs.runNumber = randomGenerator->Unsigned();
      randomArgs.parallel = randomGenerator->Bool();
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
