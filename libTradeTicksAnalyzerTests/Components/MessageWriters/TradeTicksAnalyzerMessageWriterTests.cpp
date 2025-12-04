#include "pch.h"
#include "libCppUtils/Components/Logging/MetalMock/LoggerMock.h"
#include "libTradeTicksAnalyzer/Components/MessageWriters/TradeTicksAnalyzerMessageWriter.h"

TESTS(TradeTicksAnalyzerMessageWriterTests)
AFACT(Initialize_DoesSo)
// Actions
AFACT(WriteMessage_Reading_DoesSo)
AFACT(WriteMessage_Read_DoesSo)
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

TEST(WriteMessage_Reading_DoesSo)
{
   _loggerMock->WriteProgramNameTimestampedThreadIdLineThenFlushMock.Expect();
   const size_t realTimeTextTradeTicksFilePathsSize = ZenUnit::Random<size_t>();
   const fs::path realTimeTextTradeTicksFolderPath = ZenUnit::Random<fs::path>();
   //
   _tradeTicksAnalyzerMessageWriter.WriteMessage_Reading(
      realTimeTextTradeTicksFilePathsSize, realTimeTextTradeTicksFolderPath);
   //
   const string expectedMessage = Utils::String::ConcatValues(
      "Reading and finding possible bad trade ticks in ", realTimeTextTradeTicksFilePathsSize, " RealTimeTradeTicks files in ",
      realTimeTextTradeTicksFolderPath.string());
   METALMOCK(_loggerMock->WriteProgramNameTimestampedThreadIdLineThenFlushMock.CalledOnceWith(expectedMessage));
}

TEST(WriteMessage_Read_DoesSo)
{
   _loggerMock->WriteProgramNameTimestampedThreadIdLineThenFlushMock.Expect();
   const size_t realTimeTextTradeTicksFilePathsSize = ZenUnit::Random<size_t>();
   const fs::path realTimeTextTradeTicksFolderPath = ZenUnit::Random<fs::path>();
   //
   _tradeTicksAnalyzerMessageWriter.WriteMessage_Read(
      realTimeTextTradeTicksFilePathsSize, realTimeTextTradeTicksFolderPath);
   //
   const string expectedMessage = Utils::String::ConcatValues(
      "   Read ", realTimeTextTradeTicksFilePathsSize, " RealTimeTradeTicks files in ", realTimeTextTradeTicksFolderPath.string());
   METALMOCK(_loggerMock->WriteProgramNameTimestampedThreadIdLineThenFlushMock.CalledOnceWith(expectedMessage));
}

RUN_TESTS(TradeTicksAnalyzerMessageWriterTests)
