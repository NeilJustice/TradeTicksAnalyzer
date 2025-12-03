#include "pch.h"
#include "libTradeTicksAnalyzer/Components/SubPrograms/FindPossibleBadTradeTicksSubProgram.h"
#include "libTradeTicksAnalyzer/Components/SubPrograms/ProgramModeBSubProgram.h"
#include "libTradeTicksAnalyzer/Components/SubPrograms/SubProgramFactory.h"

shared_ptr<SubProgram> SubProgramFactory::NewSubProgram(ProgramMode programMode) const
{
   switch (programMode)
   {
   case ProgramMode::FindPossibleBadTradeTicks:
   {
      return make_shared<FindPossibleBadTradeTicksSubProgram>();
   }
   case ProgramMode::ProgramModeB:
   {
      return make_shared<ProgramModeBSubProgram>();
   }
   default:
   {
      const string exceptionMessage = Utils::String::ConcatValues("Invalid ProgramMode: ", programMode);
      throw invalid_argument(exceptionMessage);
   }
   }
}
