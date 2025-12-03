#include "pch.h"
#include "libTradeTicksAnalyzer/Components/SubPrograms/FindPossibleBadTradeTicksSubProgram.h"

TESTS(FindPossibleBadTradeTicksSubProgramTests)
AFACT(Run_Returns0)
EVIDENCE

FindPossibleBadTradeTicksSubProgram _findPossibleBadTradeTicksSubProgram;
// Base Constant Components
Time::ConsoleMock* p_consoleMock = nullptr;

STARTUP
{
   // Base Constant Components
   _findPossibleBadTradeTicksSubProgram.p_console.reset(p_consoleMock = new Time::ConsoleMock);
}

TEST(Run_Returns0)
{
   const int exitCode = _findPossibleBadTradeTicksSubProgram.Run();
   IS_ZERO(exitCode);
}

RUN_TESTS(FindPossibleBadTradeTicksSubProgramTests)
