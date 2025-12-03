#include "pch.h"
#include "libTradeTicksAnalyzer/Components/SubPrograms/CalculateTradeTickLatencyStatisticsSubProgram.h"

TESTS(CalculateTradeTickLatencyStatisticsSubProgramTests)
AFACT(Run_Returns0)
EVIDENCE

CalculateTradeTickLatencyStatisticsSubProgram _calculateTradeTickLatencyStatisticsSubProgram;
// Base Constant Components
Time::ConsoleMock* p_consoleMock = nullptr;

STARTUP
{
   // Base Constant Components
   _calculateTradeTickLatencyStatisticsSubProgram.p_console.reset(p_consoleMock = new Time::ConsoleMock);
}

TEST(Run_Returns0)
{
   const int exitCode = _calculateTradeTickLatencyStatisticsSubProgram.Run();
   IS_ZERO(exitCode);
}

RUN_TESTS(CalculateTradeTickLatencyStatisticsSubProgramTests)
