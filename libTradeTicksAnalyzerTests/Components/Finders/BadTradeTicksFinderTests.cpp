#include "pch.h"
#include "libCppUtils/Components/FileSystem/MetalMock/FileAndFolderPathsGetterMock.h"
#include "libCppUtils/Components/Logging/MetalMock/LoggerMock.h"
#include "libFunctional/Components/ForEachers/Member/MetalMock/OneArgMemberFunctionForEacherMock.h"
#include "libFunctional/Components/FunctionCallers/TryCatchCallers/MetalMock/VoidOneArgTryCatchCallerMock.h"
#include "libTickData/Components/Files/TextTradeTicks/MetalMock/TextTradeTicksFileReaderMock.h"
#include "libTradeTicksAnalyzer/Components/Finders/BadTradeTicksFinder.h"
#include "libTradeTicksAnalyzer/Components/MessageWriters/MetalMock/TradeTicksAnalyzerMessageWriterMock.h"

TESTS(BadTradeTicksFinderTests)
AFACT(Initialize_DoesSo)
// Actions
AFACT(FindAllPossibleBadTradeTicks_DoesSo)
// Private Functions
AFACT(TryCatchCall_FindPossibleBadTradeTicks_DoesSo)
AFACT(FindPossibleBadTradeTicks_DoesSo)
AFACT(ExceptionHandler_FindPossibleBadTradeTicks_DoesSo)
EVIDENCE

BadTradeTicksFinder _badTradeTicksFinder;
// Function Callers
using _forEacher_fsPathMockType = Functional::OneArgMemberFunctionForEacherMock<BadTradeTicksFinder, fs::path>;
_forEacher_fsPathMockType* _forEacher_fsPathMock = nullptr;

using _tryCatchCaller_fsPathMockType = Functional::VoidOneArgTryCatchCallerMock<BadTradeTicksFinder, const fs::path&>;
_tryCatchCaller_fsPathMockType* _tryCatchCaller_fsPathMock = nullptr;
// Constant Components
Utils::FileAndFolderPathsGetterMock* _fileAndFolderPathsGetterMock = nullptr;
TickData::TextTradeTicksFileReaderMock* _textTradeTicksFileReaderMock = nullptr;
// Mutable Components
TradeTicksAnalyzerMessageWriterMock* _tradeTicksAnalyzerMessageWriterMock = nullptr;
// Mutable Fields
TradeTicksAnalyzerArgs _args;

STARTUP
{
   // Function Callers
   _badTradeTicksFinder._forEacher_fsPath.reset(_forEacher_fsPathMock = new _forEacher_fsPathMockType);
   _badTradeTicksFinder._tryCatchCaller_fsPath.reset(_tryCatchCaller_fsPathMock = new _tryCatchCaller_fsPathMockType);
   // Owned Constant Components
   _badTradeTicksFinder._fileAndFolderPathsGetter.reset(_fileAndFolderPathsGetterMock = new Utils::FileAndFolderPathsGetterMock);
   _badTradeTicksFinder._textTradeTicksFileReader.reset(_textTradeTicksFileReaderMock = new TickData::TextTradeTicksFileReaderMock);
   // Mutable Components
   _badTradeTicksFinder._tradeTicksAnalyzerMessageWriter.reset(_tradeTicksAnalyzerMessageWriterMock = new TradeTicksAnalyzerMessageWriterMock);
   // Mutable Fields
   _badTradeTicksFinder._args = _args = ZenUnit::Random<TradeTicksAnalyzerArgs>();
}

TEST(Initialize_DoesSo)
{
   _tradeTicksAnalyzerMessageWriterMock->InitializeMock.Expect();
   const TradeTicksAnalyzerArgs args = ZenUnit::Random<TradeTicksAnalyzerArgs>();
   const Utils::LoggerMock loggerMock;
   //
   _badTradeTicksFinder.Initialize(args, &loggerMock);
   //
   METALMOCK(_tradeTicksAnalyzerMessageWriterMock->InitializeMock.CalledOnceWith(&loggerMock));
   ARE_EQUAL(args, _badTradeTicksFinder._args);
}

// Actions

TEST(FindAllPossibleBadTradeTicks_DoesSo)
{
   const vector<fs::path> realTimeTextTradeTicksInputFilePaths =
      _fileAndFolderPathsGetterMock->GetTopLevelFilePathsInFolderMock.ReturnRandom();

   _tradeTicksAnalyzerMessageWriterMock->WriteMessage_ReadingAndFindingPossibleBadTradeTicksMock.Expect();

   _forEacher_fsPathMock->CallConstMemberFunctionWithEachElementOptionallyInParallelMock.Expect();

   const fs::path realTimeTextTradeTicksInputFolderPath = ZenUnit::Random<fs::path>();
   const bool parallel = ZenUnit::Random<bool>();
   //
   _badTradeTicksFinder.FindAllPossibleBadTradeTicks(realTimeTextTradeTicksInputFolderPath, parallel);
   //
   METALMOCKTHEN(_fileAndFolderPathsGetterMock->GetTopLevelFilePathsInFolderMock.CalledOnceWith(
      realTimeTextTradeTicksInputFolderPath)).Then(

   METALMOCKTHEN(_tradeTicksAnalyzerMessageWriterMock->WriteMessage_ReadingAndFindingPossibleBadTradeTicksMock.CalledOnceWith(
      realTimeTextTradeTicksInputFilePaths.size(), realTimeTextTradeTicksInputFolderPath))).Then(

   METALMOCKTHEN(_forEacher_fsPathMock->CallConstMemberFunctionWithEachElementOptionallyInParallelMock.CalledOnceWith(
      realTimeTextTradeTicksInputFilePaths,
      &_badTradeTicksFinder, &BadTradeTicksFinder::TryCatchCall_FindPossibleBadTradeTicks,
      parallel)));
}

// Private Functions

TEST(TryCatchCall_FindPossibleBadTradeTicks_DoesSo)
{
   _tryCatchCaller_fsPathMock->TryCatchCallConstMemberFunctionMock.Expect();
   const fs::path realTimeTextTradeTicksInputFilePath = ZenUnit::Random<fs::path>();
   const size_t realTimeTextTradeTicksInputFilePathIndex = ZenUnit::Random<size_t>();
   //
   _badTradeTicksFinder.TryCatchCall_FindPossibleBadTradeTicks(
      realTimeTextTradeTicksInputFilePath,
      realTimeTextTradeTicksInputFilePathIndex);
   //
   METALMOCK(_tryCatchCaller_fsPathMock->TryCatchCallConstMemberFunctionMock.CalledOnceWith(
      &_badTradeTicksFinder, &BadTradeTicksFinder::FindPossibleBadTradeTicks,
      realTimeTextTradeTicksInputFilePath,
      &BadTradeTicksFinder::ExceptionHandler_FindPossibleBadTradeTicks));
}

TEST(FindPossibleBadTradeTicks_DoesSo)
{
   const TickData::TradeTicksFileContent tradeTicksFileContent =
      _textTradeTicksFileReaderMock->ReadRealTimeTextTradeTicksFileMock.ReturnRandom();


   const fs::path realTimeTextTradeTicksInputFilePath = ZenUnit::Random<fs::path>();
   //
   _badTradeTicksFinder.FindPossibleBadTradeTicks(realTimeTextTradeTicksInputFilePath);
   //
   METALMOCK(_textTradeTicksFileReaderMock->ReadRealTimeTextTradeTicksFileMock.CalledOnceWith(realTimeTextTradeTicksInputFilePath));

}

TEST(ExceptionHandler_FindPossibleBadTradeTicks_DoesSo)
{
   _tradeTicksAnalyzerMessageWriterMock->WriteExceptionMessage_FindPossibleBadTradeTicks_ThenExit1Mock.Expect();
   const string_view exceptionClassNameAndMessage = ZenUnit::Random<string_view>();
   const fs::path realTimeTextTradeTicksInputFilePath = ZenUnit::Random<fs::path>();
   //
   _badTradeTicksFinder.ExceptionHandler_FindPossibleBadTradeTicks(
      exceptionClassNameAndMessage,
      realTimeTextTradeTicksInputFilePath);
   //
   METALMOCK(_tradeTicksAnalyzerMessageWriterMock->WriteExceptionMessage_FindPossibleBadTradeTicks_ThenExit1Mock.CalledOnceWith(
      exceptionClassNameAndMessage, realTimeTextTradeTicksInputFilePath));
}

RUN_TESTS(BadTradeTicksFinderTests)
