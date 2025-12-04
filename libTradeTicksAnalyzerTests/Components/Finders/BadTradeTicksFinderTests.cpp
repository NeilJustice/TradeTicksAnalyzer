#include "pch.h"
#include "libCppUtils/Components/FileSystem/MetalMock/FileAndFolderPathsGetterMock.h"
#include "libCppUtils/Components/Logging/MetalMock/LoggerMock.h"
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
// Constant Components
Utils::FileAndFolderPathsGetterMock* _fileAndFolderPathsGetterMock = nullptr;
// Mutable Components
TradeTicksAnalyzerMessageWriterMock* _tradeTicksAnalyzerMessageWriterMock = nullptr;

STARTUP
{
   // Owned Constant Components
   _badTradeTicksFinder._fileAndFolderPathsGetter.reset(_fileAndFolderPathsGetterMock = new Utils::FileAndFolderPathsGetterMock);
   // Mutable Components
   _badTradeTicksFinder._tradeTicksAnalyzerMessageWriter.reset(_tradeTicksAnalyzerMessageWriterMock = new TradeTicksAnalyzerMessageWriterMock);
}

TEST(Initialize_DoesSo)
{
   _tradeTicksAnalyzerMessageWriterMock->InitializeMock.Expect();
   const Utils::LoggerMock loggerMock;
   //
   _badTradeTicksFinder.Initialize(&loggerMock);
   //
   METALMOCK(_tradeTicksAnalyzerMessageWriterMock->InitializeMock.CalledOnceWith(&loggerMock));
}

// Actions

TEST(FindAllPossibleBadTradeTicks_DoesSo)
{
   const vector<fs::path> realTimeTextTradeTicksInputFilePaths =
      _fileAndFolderPathsGetterMock->GetTopLevelFilePathsInFolderMock.ReturnRandom();

   _tradeTicksAnalyzerMessageWriterMock->WriteMessage_ReadingAndFindingPossibleBadTradeTicksMock.Expect();



   const fs::path realTimeTextTradeTicksInputFolderPath = ZenUnit::Random<fs::path>();
   const fs::path possibleBadTradeTicksOutputFolderPath = ZenUnit::Random<fs::path>();
   const bool parallel = ZenUnit::Random<bool>();
   //
   _badTradeTicksFinder.FindAllPossibleBadTradeTicks(
      realTimeTextTradeTicksInputFolderPath,
      possibleBadTradeTicksOutputFolderPath,
      parallel);
   //
   METALMOCKTHEN(_fileAndFolderPathsGetterMock->GetTopLevelFilePathsInFolderMock.CalledOnceWith(
      realTimeTextTradeTicksInputFolderPath)).Then(

   METALMOCKTHEN(_tradeTicksAnalyzerMessageWriterMock->WriteMessage_ReadingAndFindingPossibleBadTradeTicksMock.CalledOnceWith(
      realTimeTextTradeTicksInputFilePaths.size(), realTimeTextTradeTicksInputFolderPath)));


}

// Private Functions

TEST(TryCatchCall_FindPossibleBadTradeTicks_DoesSo)
{

   const fs::path realTimeTextTradeTicksInputFilePath = ZenUnit::Random<fs::path>();
   const size_t realTimeTextTradeTicksInputFilePathIndex = ZenUnit::Random<size_t>();
   //
   _badTradeTicksFinder.TryCatchCall_FindPossibleBadTradeTicks(
      realTimeTextTradeTicksInputFilePath,
      realTimeTextTradeTicksInputFilePathIndex);
   //

}

TEST(FindPossibleBadTradeTicks_DoesSo)
{

   const fs::path realTimeTextTradeTicksInputFilePath = ZenUnit::Random<fs::path>();
   //
   _badTradeTicksFinder.FindPossibleBadTradeTicks(realTimeTextTradeTicksInputFilePath);
   //

}

TEST(ExceptionHandler_FindPossibleBadTradeTicks_DoesSo)
{

   const string_view exceptionClassNameAndMessage = ZenUnit::Random<string_view>();
   const fs::path realTimeTextTradeTicksInputFilePath = ZenUnit::Random<fs::path>();
   //
   _badTradeTicksFinder.ExceptionHandler_FindPossibleBadTradeTicks(
      exceptionClassNameAndMessage,
      realTimeTextTradeTicksInputFilePath);
   //

}

RUN_TESTS(BadTradeTicksFinderTests)
