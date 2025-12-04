#include "pch.h"
#include "libCppUtils/Components/Logging/MetalMock/LoggerMock.h"
#include "libTradeTicksAnalyzer/Components/MessageWriters/TradeTicksAnalyzerMessageWriter.h"

TESTS(TradeTicksAnalyzerMessageWriterTests)
AFACT(Initialize_DoesSo)
// Actions
AFACT(WriteMessage_ReadingAndFindingPossibleBadTradeTicks_DoesSo)
EVIDENCE

TradeTicksAnalyzerMessageWriter _tradeTicksAnalyzerMessageWriter;
// Non-Owned Constant Components
unique_ptr<Utils::LoggerMock> _loggerMock;

STARTUP
{
   // Non-Owned Constant Components
   _tradeTicksAnalyzerMessageWriter._logger = (_loggerMock = make_unique<Utils::LoggerMock>()).get();
}

TEST(Initialize_DoesSo)
{
   const Utils::LoggerMock loggerMock;
   //
   _tradeTicksAnalyzerMessageWriter.Initialize(&loggerMock);
   //
   ARE_EQUAL(&loggerMock, _tradeTicksAnalyzerMessageWriter._logger);
}

// Actions

TEST(WriteMessage_ReadingAndFindingPossibleBadTradeTicks_DoesSo)
{
   _loggerMock->WriteProgramNameTimestampedThreadIdLineThenFlushMock.Expect();
   const size_t realTimeTextTradeTicksFilePathsSize = ZenUnit::Random<size_t>();
   const fs::path realTimeTextTradeTicksInputFolderPath = ZenUnit::Random<fs::path>();
   //
   _tradeTicksAnalyzerMessageWriter.WriteMessage_ReadingAndFindingPossibleBadTradeTicks(
      realTimeTextTradeTicksFilePathsSize, realTimeTextTradeTicksInputFolderPath);
   //
   const string expectedMessage = Utils::String::ConcatValues(
      "Reading and finding possible bad trade ticks in ", realTimeTextTradeTicksFilePathsSize, " RealTimeTradeTicks files in ",
      realTimeTextTradeTicksInputFolderPath.string());
   METALMOCK(_loggerMock->WriteProgramNameTimestampedThreadIdLineThenFlushMock.CalledOnceWith(expectedMessage));
}

RUN_TESTS(TradeTicksAnalyzerMessageWriterTests)
