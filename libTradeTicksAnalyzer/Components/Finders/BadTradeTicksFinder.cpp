#include "pch.h"
#include "libFunctional/Components/FunctionCallers/TryCatchCallers/VoidOneArgTryCatchCaller.h"
#include "libCppUtils/Components/FileSystem/FileAndFolderPathsGetter.h"
#include "libFunctional/Components/ForEachers/Member/OneArgMemberFunctionForEacher.h"
#include "libTradeTicksAnalyzer/Components/Finders/BadTradeTicksFinder.h"
#include "libTradeTicksAnalyzer/Components/MessageWriters/TradeTicksAnalyzerMessageWriter.h"

BadTradeTicksFinder::BadTradeTicksFinder()
   // Function Callers
   : _forEacher_fsPath(make_unique<_forEacher_fsPathType>())
   , _tryCatchCaller_fsPath(make_unique<_tryCatchCaller_fsPathType>())
   // Constant Components
   , _fileAndFolderPathsGetter(make_unique<Utils::FileAndFolderPathsGetter>())
   // Mutable Components
   , _tradeTicksAnalyzerMessageWriter(make_unique<TradeTicksAnalyzerMessageWriter>())
{
}

BadTradeTicksFinder::~BadTradeTicksFinder()
{
}

void BadTradeTicksFinder::Initialize(const Utils::Logger* logger)
{
   _tradeTicksAnalyzerMessageWriter->Initialize(logger);
}

// Actions

void BadTradeTicksFinder::FindAllPossibleBadTradeTicks(
   const fs::path& realTimeTextTradeTicksInputFolderPath,
   const fs::path& /*possibleBadTradeTicksOutputFolderPath*/,
   bool parallel) const
{
   const vector<fs::path> realTimeTextTradeTicksInputFilePaths =
      _fileAndFolderPathsGetter->GetTopLevelFilePathsInFolder(realTimeTextTradeTicksInputFolderPath);

   _tradeTicksAnalyzerMessageWriter->WriteMessage_ReadingAndFindingPossibleBadTradeTicks(
      realTimeTextTradeTicksInputFilePaths.size(), realTimeTextTradeTicksInputFolderPath);

   _forEacher_fsPath->CallConstMemberFunctionWithEachElementOptionallyInParallel(
      realTimeTextTradeTicksInputFilePaths,
      this, &BadTradeTicksFinder::TryCatchCall_FindPossibleBadTradeTicks,
      parallel);
}

// Private Functions

void BadTradeTicksFinder::TryCatchCall_FindPossibleBadTradeTicks(
   const fs::path& realTimeTextTradeTicksInputFilePath,
   size_t /*realTimeTextTradeTicksInputFilePathIndex*/) const
{
   _tryCatchCaller_fsPath->TryCatchCallConstMemberFunction(
      this, &BadTradeTicksFinder::FindPossibleBadTradeTicks,
      realTimeTextTradeTicksInputFilePath,
      &BadTradeTicksFinder::ExceptionHandler_FindPossibleBadTradeTicks);
}

void BadTradeTicksFinder::FindPossibleBadTradeTicks(
   const fs::path& /*realTimeTextTradeTicksInputFilePath*/) const
{
   //const TickData::TradeTicksFileContent tradeTicksFileContent =
   //   _textTradeTicksFileReader->ReadRealTimeTextTradeTicksFile(realTimeTextTradeTicksFilePath);
}

void BadTradeTicksFinder::ExceptionHandler_FindPossibleBadTradeTicks(
   string_view /*exceptionClassNameAndMessage*/,
   const fs::path& /*realTimeTextTradeTicksInputFilePath*/) const
{

}
