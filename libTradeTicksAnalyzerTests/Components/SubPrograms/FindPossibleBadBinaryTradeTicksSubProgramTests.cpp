#include "pch.h"
#include "libTradeTicksAnalyzer/Components/SubPrograms/FindPossibleBadBinaryTradeTicksSubProgram.h"

TESTS(FindPossibleBadBinaryTradeTicksSubProgramTests)
AFACT(Run_Returns0)
EVIDENCE

FindPossibleBadBinaryTradeTicksSubProgram _findPossibleBadBinaryTradeTicksSubProgram;
// Base Constant Components
Time::ConsoleMock* p_consoleMock = nullptr;

STARTUP
{
   // Base Constant Components
   _findPossibleBadBinaryTradeTicksSubProgram.p_console.reset(p_consoleMock = new Time::ConsoleMock);
}

TEST(Run_Returns0)
{
   const int exitCode = _findPossibleBadBinaryTradeTicksSubProgram.Run();
   IS_ZERO(exitCode);
}

RUN_TESTS(FindPossibleBadBinaryTradeTicksSubProgramTests)
