#include "pch.h"
#include "libCppUtils/Components/FileSystem/MetalMock/FileAndFolderPathsGetterMock.h"
#include "libCppUtils/Components/Logging/MetalMock/LoggerMock.h"
#include "libTradeTicksAnalyzer/Components/Finders/BadTradeTicksFinder.h"

TESTS(BadTradeTicksFinderTests)
AFACT(Initialize_DoesSo)
// Actions
AFACT(FindAllPossibleBadTradeTicks_DoesSo)
EVIDENCE

BadTradeTicksFinder _badTradeTicksFinder;
// Owned Constant Components
Utils::FileAndFolderPathsGetterMock* _fileAndFolderPathsGetterMock = nullptr;
// Non-Owned Constant Components
unique_ptr<Utils::LoggerMock> _loggerMock;

STARTUP
{
   // Owned Constant Components
   _badTradeTicksFinder._fileAndFolderPathsGetter.reset(_fileAndFolderPathsGetterMock = new Utils::FileAndFolderPathsGetterMock);
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
   const vector<fs::path> realTimeTextTradeTicksFilePaths =
      _fileAndFolderPathsGetterMock->GetTopLevelFilePathsInFolderMock.ReturnRandom();

   const fs::path tradingLogsInputFolderPath_dateDashRunNumber_Polygon_FilteredRealTimeTextTradeTicks = ZenUnit::Random<fs::path>();
   const fs::path tradingLogsOutputFolderPath_dateDashRunNumber_Polygon_FilteredRealTimeTextTradeTicksDashPossibleBadTradeTicks = ZenUnit::Random<fs::path>();
   const bool parallel = ZenUnit::Random<bool>();
   //
   _badTradeTicksFinder.FindAllPossibleBadTradeTicks(
      tradingLogsInputFolderPath_dateDashRunNumber_Polygon_FilteredRealTimeTextTradeTicks,
      tradingLogsOutputFolderPath_dateDashRunNumber_Polygon_FilteredRealTimeTextTradeTicksDashPossibleBadTradeTicks,
      parallel);
   //
   METALMOCK(_fileAndFolderPathsGetterMock->GetTopLevelFilePathsInFolderMock.CalledOnceWith(
      tradingLogsInputFolderPath_dateDashRunNumber_Polygon_FilteredRealTimeTextTradeTicks));
}

RUN_TESTS(BadTradeTicksFinderTests)
