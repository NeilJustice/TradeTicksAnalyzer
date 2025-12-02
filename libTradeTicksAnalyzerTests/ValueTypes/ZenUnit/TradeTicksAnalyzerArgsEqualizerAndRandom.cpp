#include "pch.h"
#include "libTradeTicksAnalyzerTests/ValueTypes/ZenUnit/TradeTicksAnalyzerArgsEqualizerAndRandom.h"

namespace ZenUnit
{
   void Equalizer<TradeTicksAnalyzerArgs>::AssertEqual(
      const TradeTicksAnalyzerArgs& expectedTradeTicksAnalyzerArgs, const TradeTicksAnalyzerArgs& actualTradeTicksAnalyzerArgs)
   {
      FIELDS_ARE_EQUAL(expectedTradeTicksAnalyzerArgs, actualTradeTicksAnalyzerArgs, programMode);
      FIELDS_ARE_EQUAL(expectedTradeTicksAnalyzerArgs, actualTradeTicksAnalyzerArgs, requiredString);
      FIELDS_ARE_EQUAL(expectedTradeTicksAnalyzerArgs, actualTradeTicksAnalyzerArgs, parallel);
   }

   TradeTicksAnalyzerArgs TestableRandomTradeTicksAnalyzerArgs(
      const RandomGenerator* randomGenerator, const TradeTicksAnalyzerRandomGenerator* tradeTicksAnalyzerRandomGenerator)
   {
      TradeTicksAnalyzerArgs randomArgs;
      randomArgs.programMode = tradeTicksAnalyzerRandomGenerator->RandomProgramMode();
      randomArgs.requiredString = randomGenerator->String();
      randomArgs.parallel = randomGenerator->Bool();
      return randomArgs;
   }

   template<>
   TradeTicksAnalyzerArgs Random()
   {
      return TestableRandomTradeTicksAnalyzerArgs(RandomGenerator::Instance(), TradeTicksAnalyzerRandomGenerator::Instance());
   }
}
