#include "pch.h"
#include "libCppUtils/Components/Logging/MetalMock/LoggerMock.h"
#include "libTradeTicksAnalyzer/Components/MessageWriters/TradeTicksAnalyzerMessageWriter.h"

TESTS(TradeTicksAnalyzerMessageWriterTests)
AFACT(Initialize_DoesSo)
// Actions
AFACT(WriteMessage_ReadingAndFindingPossibleBadTradeTicks_DoesSo)
AFACT(WriteFatalExceptionMessage_FindPossibleBadTradeTicks_DoesSo)
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

TEST(WriteFatalExceptionMessage_FindPossibleBadTradeTicks_DoesSo)
{
   _loggerMock->WriteProgramNameTimestampedThreadIdLineInRedThenExitWithCode1IfConsoleMock.Expect();
   const string_view exceptionClassNameAndMessage = ZenUnit::Random<string_view>();
   const fs::path realTimeTextTradeTicksInputFilePath = ZenUnit::Random<fs::path>();
   //
   _tradeTicksAnalyzerMessageWriter.WriteFatalExceptionMessage_FindPossibleBadTradeTicks(
      exceptionClassNameAndMessage, realTimeTextTradeTicksInputFilePath);
   //
   const string expectedEnhancedExceptionMessage = Utils::String::ConcatStrings(
      "Exception thrown while calling BadTradeTicksFinder::FindPossibleBadTradeTicks:\n",
      exceptionClassNameAndMessage, "\n",
      "realTimeTextTradeTicksInputFilePath=", realTimeTextTradeTicksInputFilePath.string());
   METALMOCK(_loggerMock->WriteProgramNameTimestampedThreadIdLineInRedThenExitWithCode1IfConsoleMock.CalledOnceWith(
      expectedEnhancedExceptionMessage));
}

RUN_TESTS(TradeTicksAnalyzerMessageWriterTests)
