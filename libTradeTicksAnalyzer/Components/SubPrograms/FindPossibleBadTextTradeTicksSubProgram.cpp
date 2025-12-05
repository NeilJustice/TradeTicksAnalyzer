#include "pch.h"
#include "libTradeTicksAnalyzer/Components/Finders/BadTradeTicksFinderAndFilesWriter.h"
#include "libTradeTicksAnalyzer/Components/SubPrograms/FindPossibleBadTextTradeTicksSubProgram.h"

FindPossibleBadTextTradeTicksSubProgram::FindPossibleBadTextTradeTicksSubProgram()
   // Mutable Components
   : _badTradeTicksFinderAndFilesWriter(make_unique<BadTradeTicksFinderAndFilesWriter>())
{
}

FindPossibleBadTextTradeTicksSubProgram::~FindPossibleBadTextTradeTicksSubProgram()
{
}

void FindPossibleBadTextTradeTicksSubProgram::DerivedInitialize()
{
   _badTradeTicksFinderAndFilesWriter->Initialize(p_args, p_console.get());
}

// Actions

int FindPossibleBadTextTradeTicksSubProgram::Run() const
{
   _badTradeTicksFinderAndFilesWriter->FindAllPossibleBadTradeTicks(
      p_args.tradingLogsInputFolderPath_dateDashRunNumber_Polygon_FilteredRealTimeTextTradeTicks,
      p_args.parallel);
   return 0;
}
