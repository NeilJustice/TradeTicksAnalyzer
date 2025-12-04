#include "pch.h"
#include "libTickData/Components/Files/TextTradeTicks/MultipleTextTradeTicksFilesReader.h"
#include "libTradeTicksAnalyzer/Components/SubPrograms/FindPossibleBadTextTradeTicksSubProgram.h"

FindPossibleBadTextTradeTicksSubProgram::FindPossibleBadTextTradeTicksSubProgram()
   // Constant Components
   : _multipleTextTradeTicksFilesReader(make_unique<TickData::MultipleTextTradeTicksFilesReader>())
{
}

FindPossibleBadTextTradeTicksSubProgram::~FindPossibleBadTextTradeTicksSubProgram()
{
}

int FindPossibleBadTextTradeTicksSubProgram::Run() const
{
   const vector<TickData::TradeTicksFileContent> allTradeTicksFileContents =
      _multipleTextTradeTicksFilesReader->ReadAllRealTimeTextTradeTicksFiles(
         p_args.tradingLogsOutputFolderPath_dateDashRunNumber_Polygon_FilteredRealTimeTextTradeTicks, p_args.parallel);
   return 0;
}
