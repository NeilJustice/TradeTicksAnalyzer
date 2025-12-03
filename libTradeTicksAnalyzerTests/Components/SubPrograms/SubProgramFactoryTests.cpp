#include "pch.h"
#include "libTradeTicksAnalyzer/Components/SubPrograms/FindPossibleBadTradeTicksSubProgram.h"
#include "libTradeTicksAnalyzer/Components/SubPrograms/ProgramModeBSubProgram.h"
#include "libTradeTicksAnalyzer/Components/SubPrograms/SubProgram.h"
#include "libTradeTicksAnalyzer/Components/SubPrograms/SubProgramFactory.h"

TESTS(SubProgramFactoryTests)
AFACT(NewSubProgram_FindPossibleBadTradeTicks_ReturnsFindPossibleBadTradeTicksSubProgram)
AFACT(NewSubProgram_ProgramModeB_ReturnsProgramModeBSubProgram)
FACTS(NewSubProgram_InvalidProgramMode_ThrowsInvalidArgument)
EVIDENCE

SubProgramFactory _subProgramFactory;

TEST(NewSubProgram_FindPossibleBadTradeTicks_ReturnsFindPossibleBadTradeTicksSubProgram)
{
   const shared_ptr<SubProgram> subProgram = _subProgramFactory.NewSubProgram(ProgramMode::FindPossibleBadTradeTicks);
   POINTEE_IS_EXACT_TYPE(FindPossibleBadTradeTicksSubProgram, subProgram);
}

TEST(NewSubProgram_ProgramModeB_ReturnsProgramModeBSubProgram)
{
   const shared_ptr<SubProgram> subProgram = _subProgramFactory.NewSubProgram(ProgramMode::ProgramModeB);
   POINTEE_IS_EXACT_TYPE(ProgramModeBSubProgram, subProgram);
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
