#include "pch.h"
#include "libTradeTicksAnalyzer/Components/Finders/BadTradeTicksFinder.h"

BadTradeTicksFinder::BadTradeTicksFinder()
   // Non-Owned Constant Components
   : _logger(nullptr)
{
}

BadTradeTicksFinder::~BadTradeTicksFinder()
{
}

// Actions

void BadTradeTicksFinder::Initialize(const Utils::Logger* logger)
{
   _logger = logger;
}

void BadTradeTicksFinder::FindAllPossibleBadTradeTicks(
   const fs::path& /*tradingLogsInputFolderPath_dateDashRunNumber_Polygon_FilteredRealTimeTextTradeTicks*/,
   const fs::path& /*tradingLogsOutputFolderPath_dateDashRunNumber_Polygon_FilteredRealTimeTextTradeTicksDashPossibleBadTradeTicks*/,
   bool /*parallel*/) const
{
   //const vector<fs::path> realTimeTextTradeTicksFilePaths =
   //   _fileAndFolderPathsGetter->GetTopLevelFilePathsInFolder(tradingLogsInputFolderPath_dateDashRunNumber_Polygon_FilteredRealTimeTextTradeTicks);
   //_libTickDataMessageWriter->WriteMessage_ReadingAndProcessing(realTimeTextTradeTicksFilePaths.size(), realTimeTextTradeTicksFolderPath);

   // _forEacher_fsPath->CallConstMemberFunctionOnEachElementOptionallyInParallel(
   //    realTimeTextTradeTicksFilePaths,
   //    this, &MultipleTextTradeTicksFilesReader::TryCatchCall_ReadTradeTicksFile,
   //    parallel);

   //_libTickDataMessageWriter->WriteMessage_ReadAndProcessing(realTimeTextTradeTicksFilePaths.size(), realTimeTextTradeTicksFolderPath);
}

// Private Functions

// void BadTradeTicksFinder::ReadAndFindPossibleBadTradeTicks() const
// {
      //const TickData::TradeTicksFileContent tradeTicksFileContent =
      //   _textTradeTicksFileReader->ReadRealTimeTextTradeTicksFile(realTimeTextTradeTicksFilePath);
// }

