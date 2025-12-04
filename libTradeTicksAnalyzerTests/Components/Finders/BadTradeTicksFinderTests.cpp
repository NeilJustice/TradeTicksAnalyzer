#include "pch.h"
#include "libCppUtils/Components/Logging/MetalMock/LoggerMock.h"
#include "libTradeTicksAnalyzer/Components/Finders/BadTradeTicksFinder.h"

TESTS(BadTradeTicksFinderTests)
AFACT(DefaultConstructor_SetsFieldsToDefaultValues)
EVIDENCE

BadTradeTicksFinder _badTradeTicksFinder;
// Non-Owned Constant Components
unique_ptr<Utils::LoggerMock> _loggerMock;

STARTUP
{
   // Non-Owned Constant Components
   _badTradeTicksFinder._logger = (_loggerMock = make_unique<Utils::LoggerMock>()).get();
}

TEST(DefaultConstructor_SetsFieldsToDefaultValues)
{

}

RUN_TESTS(BadTradeTicksFinderTests)
