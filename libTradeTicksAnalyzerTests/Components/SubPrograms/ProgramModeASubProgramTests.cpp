#include "pch.h"
#include "libTradeTicksAnalyzer/Components/SubPrograms/ProgramModeASubProgram.h"

TESTS(ProgramModeASubProgramTests)
AFACT(Run_Returns0)
EVIDENCE

ProgramModeASubProgram _programModeASubProgram;
// Base Constant Components
Time::ConsoleMock* p_consoleMock = nullptr;

STARTUP
{
   // Base Constant Components
   _programModeASubProgram.p_console.reset(p_consoleMock = new Time::ConsoleMock);
}

TEST(Run_Returns0)
{
   const int exitCode = _programModeASubProgram.Run();
   IS_ZERO(exitCode);
}

RUN_TESTS(ProgramModeASubProgramTests)
