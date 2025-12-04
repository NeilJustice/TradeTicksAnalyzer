#include "pch.h"
#include "libTradeTicksAnalyzer/Components/Finders/BadTradeTicksFinder.h"
#include "libTradeTicksAnalyzer/Components/SubPrograms/FindPossibleBadTextTradeTicksSubProgram.h"

FindPossibleBadTextTradeTicksSubProgram::FindPossibleBadTextTradeTicksSubProgram()
   // Mutable Components
   : _badTradeTicksFinder(make_unique<BadTradeTicksFinder>())
{
}

FindPossibleBadTextTradeTicksSubProgram::~FindPossibleBadTextTradeTicksSubProgram()
{
}

void FindPossibleBadTextTradeTicksSubProgram::DerivedInitialize()
{
   _badTradeTicksFinder->Initialize(p_console.get());
}

// Actions

int FindPossibleBadTextTradeTicksSubProgram::Run() const
{
   //const vector<TickData::TradeTicksFileContent> allTradeTicksFileContents =
   //   _multipleTextTradeTicksFilesReader->ReadAllRealTimeTextTradeTicksFiles(
   //      p_args.tradingLogsInputFolderPath_dateDashRunNumber_Polygon_FilteredRealTimeTextTradeTicks, p_args.parallel);

   //_badTradeTicksFinder->FindAllPossibleBadTradeTicks(
   //   p_args.tradingLogsInputFolderPath_dateDashRunNumber_Polygon_FilteredRealTimeTextTradeTicks,
   //   p_args.tradingLogsOutputFolderPath_dateDashRunNumber_Polygon_FilteredRealTimeTextTradeTicksDashPossibleBadTradeTicks,
   //   p_args.parallel);
   return 0;
}
