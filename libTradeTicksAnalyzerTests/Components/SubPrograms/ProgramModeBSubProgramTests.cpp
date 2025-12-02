#include "pch.h"
#include "libTradeTicksAnalyzer/Components/SubPrograms/ProgramModeBSubProgram.h"

TESTS(ProgramModeBSubProgramTests)
AFACT(Run_Returns0)
EVIDENCE

ProgramModeBSubProgram _programModeBSubProgram;
// Base Constant Components
Time::ConsoleMock* p_consoleMock = nullptr;

STARTUP
{
   // Base Constant Components
   _programModeBSubProgram.p_console.reset(p_consoleMock = new Time::ConsoleMock);
}

TEST(Run_Returns0)
{
   const int exitCode = _programModeBSubProgram.Run();
   IS_ZERO(exitCode);
}

RUN_TESTS(ProgramModeBSubProgramTests)
