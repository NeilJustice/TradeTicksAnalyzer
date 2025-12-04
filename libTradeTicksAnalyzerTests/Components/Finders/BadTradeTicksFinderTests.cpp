#include "pch.h"
#include "libCppUtils/Components/FileSystem/MetalMock/FileAndFolderPathsGetterMock.h"
#include "libCppUtils/Components/Logging/MetalMock/LoggerMock.h"
#include "libTradeTicksAnalyzer/Components/Finders/BadTradeTicksFinder.h"
#include "libTradeTicksAnalyzer/Components/MessageWriters/MetalMock/TradeTicksAnalyzerMessageWriterMock.h"

TESTS(BadTradeTicksFinderTests)
AFACT(Initialize_DoesSo)
// Actions
AFACT(FindAllPossibleBadTradeTicks_DoesSo)
EVIDENCE

BadTradeTicksFinder _badTradeTicksFinder;
// Owned Constant Components
Utils::FileAndFolderPathsGetterMock* _fileAndFolderPathsGetterMock = nullptr;
TradeTicksAnalyzerMessageWriterMock* _tradeTicksAnalyzerMessageWriterMock = nullptr;
// Non-Owned Constant Components
unique_ptr<Utils::LoggerMock> _loggerMock;

STARTUP
{
   // Owned Constant Components
   _badTradeTicksFinder._fileAndFolderPathsGetter.reset(_fileAndFolderPathsGetterMock = new Utils::FileAndFolderPathsGetterMock);
   _badTradeTicksFinder._tradeTicksAnalyzerMessageWriter.reset(_tradeTicksAnalyzerMessageWriterMock = new TradeTicksAnalyzerMessageWriterMock);
   // Non-Owned Constant Components
   _badTradeTicksFinder._logger = (_loggerMock = make_unique<Utils::LoggerMock>()).get();
}

TEST(Initialize_DoesSo)
{
   const Utils::LoggerMock loggerMock;
   //
   _badTradeTicksFinder.Initialize(&loggerMock);
   //
   ARE_EQUAL(&loggerMock, _badTradeTicksFinder._logger);
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

RUN_TESTS(BadTradeTicksFinderTests)
