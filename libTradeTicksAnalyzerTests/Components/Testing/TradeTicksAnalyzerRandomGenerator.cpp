#include "pch.h"
#include "libTradeTicksAnalyzerTests/Components/Testing/TradeTicksAnalyzerRandomGenerator.h"

const TradeTicksAnalyzerRandomGenerator* TradeTicksAnalyzerRandomGenerator::Instance()
{
   static const TradeTicksAnalyzerRandomGenerator tradeTicksAnalyzerRandomGenerator;
   return &tradeTicksAnalyzerRandomGenerator;
}

ProgramMode TradeTicksAnalyzerRandomGenerator::RandomProgramMode() const
{
   ProgramMode randomProgramMode = ZenUnit::RandomEnum<ProgramMode>();
   return randomProgramMode;
}
