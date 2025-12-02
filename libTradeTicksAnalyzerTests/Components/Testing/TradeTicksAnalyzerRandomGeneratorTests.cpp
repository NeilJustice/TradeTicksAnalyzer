#include "pch.h"
#include "libTradeTicksAnalyzerTests/Components/Testing/TradeTicksAnalyzerRandomGenerator.h"

TESTS(TradeTicksAnalyzerRandomGeneratorTests)
AFACT(RandomProgramMode_CodeCoverage)
EVIDENCE

TradeTicksAnalyzerRandomGenerator _tradeTicksAnalyzerRandomGenerator;

TEST(RandomProgramMode_CodeCoverage)
{
   _tradeTicksAnalyzerRandomGenerator.RandomProgramMode();
}

RUN_TESTS(TradeTicksAnalyzerRandomGeneratorTests)
