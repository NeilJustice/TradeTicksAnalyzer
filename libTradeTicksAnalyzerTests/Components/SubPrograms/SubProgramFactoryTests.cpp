#include "pch.h"
#include "libTradeTicksAnalyzer/Components/SubPrograms/FindPossibleBadTextTradeTicksSubProgram.h"
#include "libTradeTicksAnalyzer/Components/SubPrograms/FindPossibleBadBinaryTradeTicksSubProgram.h"
#include "libTradeTicksAnalyzer/Components/SubPrograms/SubProgram.h"
#include "libTradeTicksAnalyzer/Components/SubPrograms/SubProgramFactory.h"

TESTS(SubProgramFactoryTests)
AFACT(NewSubProgram_ValidProgramMode_DoesSo)
FACTS(NewSubProgram_InvalidProgramMode_ThrowsInvalidArgument)
EVIDENCE

SubProgramFactory _subProgramFactory;

TEST(NewSubProgram_ValidProgramMode_DoesSo)
{
   POINTEE_IS_EXACT_TYPE(FindPossibleBadBinaryTradeTicksSubProgram, _subProgramFactory.NewSubProgram(ProgramMode::FindPossibleBadBinaryTradeTicks));
   POINTEE_IS_EXACT_TYPE(FindPossibleBadTextTradeTicksSubProgram, _subProgramFactory.NewSubProgram(ProgramMode::FindPossibleBadTextTradeTicks));
}

TEST1X1(NewSubProgram_InvalidProgramMode_ThrowsInvalidArgument,
   ProgramMode invalidTradeTicksAnalyzerMode,
   ProgramMode::Unset,
   ProgramMode::MaxValue)
{
   const string expectedExceptionMessage = Utils::String::ConcatValues("Invalid ProgramMode: ", invalidTradeTicksAnalyzerMode);
   THROWS_EXCEPTION(_subProgramFactory.NewSubProgram(invalidTradeTicksAnalyzerMode),
      invalid_argument, expectedExceptionMessage);
}

RUN_TESTS(SubProgramFactoryTests)
