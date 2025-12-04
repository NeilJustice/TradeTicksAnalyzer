#include "pch.h"
#include "libTickData/Components/Files/TextTradeTicks/MultipleTextTradeTicksFilesReader.h"
#include "libTradeTicksAnalyzer/Components/SubPrograms/FindPossibleBadTextTradeTicksSubProgram.h"

FindPossibleBadTextTradeTicksSubProgram::FindPossibleBadTextTradeTicksSubProgram()
   // Mutable Components
   : _multipleTextTradeTicksFilesReader(make_unique<TickData::MultipleTextTradeTicksFilesReader>())
{
}

FindPossibleBadTextTradeTicksSubProgram::~FindPossibleBadTextTradeTicksSubProgram()
{
}

void FindPossibleBadTextTradeTicksSubProgram::DerivedInitialize()
{
   _multipleTextTradeTicksFilesReader->Initialize(p_console.get());
}

// Actions

int FindPossibleBadTextTradeTicksSubProgram::Run() const
{
   const vector<TickData::TradeTicksFileContent> allTradeTicksFileContents =
      _multipleTextTradeTicksFilesReader->ReadAllRealTimeTextTradeTicksFiles(
         p_args.tradingLogsOutputFolderPath_dateDashRunNumber_Polygon_FilteredRealTimeTextTradeTicks, p_args.parallel);
   return 0;
}
