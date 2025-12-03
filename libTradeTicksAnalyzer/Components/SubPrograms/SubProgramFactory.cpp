#include "pch.h"
#include "libTradeTicksAnalyzer/Components/SubPrograms/FindPossibleBadTradeTicksSubProgram.h"
#include "libTradeTicksAnalyzer/Components/SubPrograms/CalculateTradeTickLatencyStatisticsSubProgram.h"
#include "libTradeTicksAnalyzer/Components/SubPrograms/SubProgramFactory.h"

shared_ptr<SubProgram> SubProgramFactory::NewSubProgram(ProgramMode programMode) const
{
   switch (programMode)
   {
   case ProgramMode::CalculateTradeTickLatencyStatistics: return make_shared<CalculateTradeTickLatencyStatisticsSubProgram>();
   case ProgramMode::FindPossibleBadTradeTicks: return make_shared<FindPossibleBadTradeTicksSubProgram>();
   default:
   {
      const string exceptionMessage = Utils::String::ConcatValues("Invalid ProgramMode: ", programMode);
      throw invalid_argument(exceptionMessage);
   }
   }
}
