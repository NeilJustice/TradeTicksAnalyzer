#include "pch.h"
#include "libCppUtils/Components/FileSystem/FileAndFolderPathsGetter.h"
#include "libFunctional/Components/ForEachers/Member/OneArgMemberFunctionForEacher.h"
#include "libFunctional/Components/FunctionCallers/TryCatchCallers/VoidOneArgTryCatchCaller.h"
#include "libTickData/Components/Files/TextTradeTicks/TextTradeTicksFileReader.h"
#include "libTickData/Components/Files/TextTradeTicks/TextTradeTicksFileWriter.h"
#include "libTradeTicksAnalyzer/Components/Determiners/BadTradeTicksDeterminer.h"
#include "libTradeTicksAnalyzer/Components/Finders/BadTradeTicksFinderAndFilesWriter.h"
#include "libTradeTicksAnalyzer/Components/MessageWriters/TradeTicksAnalyzerMessageWriter.h"

BadTradeTicksFinderAndFilesWriter::BadTradeTicksFinderAndFilesWriter()
   // Function Callers
   : _forEacher_fsPath(make_unique<_forEacher_fsPathType>())
   , _tryCatchCaller_fsPath(make_unique<_tryCatchCaller_fsPathType>())
   // Constant Components
   , _badTradeTicksDeterminer(make_unique<BadTradeTicksDeterminer>())
   , _fileAndFolderPathsGetter(make_unique<Utils::FileAndFolderPathsGetter>())
   , _textTradeTicksFileReader(make_unique<TickData::TextTradeTicksFileReader>())
   // Mutable Components
   , _textTradeTicksFileWriter(make_unique<TickData::TextTradeTicksFileWriter>())
   , _tradeTicksAnalyzerMessageWriter(make_unique<TradeTicksAnalyzerMessageWriter>())
{
}

BadTradeTicksFinderAndFilesWriter::~BadTradeTicksFinderAndFilesWriter()
{
}

void BadTradeTicksFinderAndFilesWriter::Initialize(const TradeTicksAnalyzerArgs& args, const Utils::Logger* logger)
{
   _textTradeTicksFileWriter->SetProgramName("TradeTicksAnalyzer");
   _tradeTicksAnalyzerMessageWriter->Initialize(logger);
   _args = args;
}

// Actions

void BadTradeTicksFinderAndFilesWriter::FindAllPossibleBadTradeTicksAndWriteResultsFiles(
   const fs::path& realTimeTextTradeTicksInputFolderPath, bool parallel) const
{
   const vector<fs::path> realTimeTextTradeTicksInputFilePaths =
      _fileAndFolderPathsGetter->GetTopLevelFilePathsInFolder(realTimeTextTradeTicksInputFolderPath);

   _tradeTicksAnalyzerMessageWriter->WriteMessage_ReadingAndFindingPossibleBadTradeTicks(
      realTimeTextTradeTicksInputFilePaths.size(), realTimeTextTradeTicksInputFolderPath);

   _forEacher_fsPath->CallConstMemberFunctionWithEachElementOptionallyInParallel(
      realTimeTextTradeTicksInputFilePaths,
      this, &BadTradeTicksFinderAndFilesWriter::TryCatchCall_FindPossibleBadTradeTicksAndWriteResultsFile,
      parallel);
}

// Private Functions

void BadTradeTicksFinderAndFilesWriter::TryCatchCall_FindPossibleBadTradeTicksAndWriteResultsFile(
   const fs::path& realTimeTextTradeTicksInputFilePath, size_t /*realTimeTextTradeTicksInputFilePathIndex*/) const
{
   _tryCatchCaller_fsPath->TryCatchCallConstMemberFunction(
      this, &BadTradeTicksFinderAndFilesWriter::FindPossibleBadTradeTicksAndWriteResultsFile,
      realTimeTextTradeTicksInputFilePath,
      &BadTradeTicksFinderAndFilesWriter::ExceptionHandler_FindPossibleBadTradeTicksAndWriteResultsFile);
}

void BadTradeTicksFinderAndFilesWriter::FindPossibleBadTradeTicksAndWriteResultsFile(
   const fs::path& realTimeTextTradeTicksInputFilePath) const
{
   const TickData::TradeTicksFileContent tradeTicksFileContent =
      _textTradeTicksFileReader->ReadRealTimeTextTradeTicksFile(realTimeTextTradeTicksInputFilePath);

   const vector<TickData::TradeTick> possibleBadTradeTicks = _badTradeTicksDeterminer->FindPossibleBadTradeTicks(
      tradeTicksFileContent.tradeTicks, _args.badTickChangePercentThreshold);

   _textTradeTicksFileWriter->CreatePossibleBadTradeTicksFile(
      tradeTicksFileContent.symbol,
      possibleBadTradeTicks,
      _args.tradingLogsOutputFolderPath_dateDashRunNumber_Polygon_FilteredRealTimeTextTradeTicksDashPossibleBad);
}

void BadTradeTicksFinderAndFilesWriter::ExceptionHandler_FindPossibleBadTradeTicksAndWriteResultsFile(
   string_view exceptionClassNameAndMessage, const fs::path& realTimeTextTradeTicksInputFilePath) const
{
   _tradeTicksAnalyzerMessageWriter->WriteExceptionMessage_FindPossibleBadTradeTicks_ThenExit1(
      exceptionClassNameAndMessage, realTimeTextTradeTicksInputFilePath);
}
