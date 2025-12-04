#include "pch.h"
#include "libCppUtils/Components/FileSystem/FileAndFolderPathsGetter.h"
#include "libTradeTicksAnalyzer/Components/Finders/BadTradeTicksFinder.h"
#include "libTradeTicksAnalyzer/Components/MessageWriters/TradeTicksAnalyzerMessageWriter.h"

BadTradeTicksFinder::BadTradeTicksFinder()
   // Owned Constant Components
   : _fileAndFolderPathsGetter(make_unique<Utils::FileAndFolderPathsGetter>())
   , _tradeTicksAnalyzerMessageWriter(make_unique<TradeTicksAnalyzerMessageWriter>())
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
   const vector<fs::path> realTimeTextTradeTicksInputFilePaths =
      _fileAndFolderPathsGetter->GetTopLevelFilePathsInFolder(realTimeTextTradeTicksInputFolderPath);

   _tradeTicksAnalyzerMessageWriter->WriteMessage_ReadingAndFindingPossibleBadTradeTicks(
      realTimeTextTradeTicksInputFilePaths.size(), realTimeTextTradeTicksInputFolderPath);

   // _forEacher_fsPath->CallConstMemberFunctionOnEachElementOptionallyInParallel(
   //    realTimeTextTradeTicksInputFilePaths,
   //    this, &MultipleTextTradeTicksFilesReader::TryCatchCall_ReadTradeTicksFile,
   //    parallel);
}

// Private Functions

// void BadTradeTicksFinder::ReadAndFindPossibleBadTradeTicks() const
// {
      //const TickData::TradeTicksFileContent tradeTicksFileContent =
      //   _textTradeTicksFileReader->ReadRealTimeTextTradeTicksFile(realTimeTextTradeTicksFilePath);
// }

