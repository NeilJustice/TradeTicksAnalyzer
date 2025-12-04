#include "pch.h"
#include "libCppUtils/Components/FileSystem/FileAndFolderPathsGetter.h"
#include "libTradeTicksAnalyzer/Components/Finders/BadTradeTicksFinder.h"

BadTradeTicksFinder::BadTradeTicksFinder()
   // Owned Constant Components
   : _fileAndFolderPathsGetter(make_unique<Utils::FileAndFolderPathsGetter>())
   // Non-Owned Constant Components
   , _logger(nullptr)
{
}

BadTradeTicksFinder::~BadTradeTicksFinder()
{
}

void BadTradeTicksFinder::Initialize(const Utils::Logger* logger)
{
   _logger = logger;
}

// Actions

void BadTradeTicksFinder::FindAllPossibleBadTradeTicks(
   const fs::path& realTimeTextTradeTicksInputFolderPath,
   const fs::path& /*possibleBadTradeTicksOutputFolderPath*/,
   bool /*parallel*/) const
{
   const vector<fs::path> realTimeTextTradeTicksFilePaths =
      _fileAndFolderPathsGetter->GetTopLevelFilePathsInFolder(realTimeTextTradeTicksInputFolderPath);

   //_tradeTicksAnalyzerMessageWriter->WriteMessage_ReadingAndProcessing(
   //   realTimeTextTradeTicksFilePaths.size(), realTimeTextTradeTicksFolderPaths);

   // _forEacher_fsPath->CallConstMemberFunctionOnEachElementOptionallyInParallel(
   //    realTimeTextTradeTicksFilePaths,
   //    this, &MultipleTextTradeTicksFilesReader::TryCatchCall_ReadTradeTicksFile,
   //    parallel);

   //_tradeTicksAnalyzerMessageWriter->WriteMessage_ReadAndProcessing(
   //   realTimeTextTradeTicksFilePaths.size(), realTimeTextTradeTicksFolderPath);
}

// Private Functions

// void BadTradeTicksFinder::ReadAndFindPossibleBadTradeTicks() const
// {
      //const TickData::TradeTicksFileContent tradeTicksFileContent =
      //   _textTradeTicksFileReader->ReadRealTimeTextTradeTicksFile(realTimeTextTradeTicksFilePath);
// }

