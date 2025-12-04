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
   // Non-Owned Constant Components
   _badTradeTicksFinder._logger = (_loggerMock = make_unique<Utils::LoggerMock>()).get();
}

TEST(Initialize_DoesSo)
{

}

// Actions

TEST(FindAllPossibleBadTradeTicks_DoesSo)
{

}

RUN_TESTS(BadTradeTicksFinderTests)
