#include "pch.h"
#include "libCppUtils/Components/Logging/MetalMock/LoggerMock.h"
#include "libTradeTicksAnalyzer/Components/MessageWriters/LibTickDataMessageWriter.h"

TESTS(LibTickDataMessageWriterTests)
AFACT(Initialize_DoesSo)
// Actions
AFACT(WriteMessage_Reading_DoesSo)
AFACT(WriteMessage_Read_DoesSo)
EVIDENCE

LibTickDataMessageWriter _libTickDataMessageWriter;
// Non-Owned Constant Components
unique_ptr<Utils::LoggerMock> _loggerMock;

STARTUP
{
   // Non-Owned Constant Components
   _libTickDataMessageWriter._logger = (_loggerMock = make_unique<Utils::LoggerMock>()).get();
}

TEST(Initialize_DoesSo)
{
   const Utils::LoggerMock loggerMock;
   //
   _libTickDataMessageWriter.Initialize(&loggerMock);
   //
   ARE_EQUAL(&loggerMock, _libTickDataMessageWriter._logger);
}

// Actions

TEST(WriteMessage_Reading_DoesSo)
{
   _loggerMock->WriteProgramNameTimestampedThreadIdLineThenFlushMock.Expect();
   const size_t realTimeTextTradeTicksFilePathsSize = ZenUnit::Random<size_t>();
   const fs::path realTimeTextTradeTicksFolderPath = ZenUnit::Random<fs::path>();
   //
   _libTickDataMessageWriter.WriteMessage_Reading(
      realTimeTextTradeTicksFilePathsSize, realTimeTextTradeTicksFolderPath);
   //
   const string expectedMessage = Utils::String::ConcatValues(
      "Reading ", realTimeTextTradeTicksFilePathsSize, " RealTimeTradeTicks files in ", realTimeTextTradeTicksFolderPath.string());
   METALMOCK(_loggerMock->WriteProgramNameTimestampedThreadIdLineThenFlushMock.CalledOnceWith(expectedMessage));
}

TEST(WriteMessage_Read_DoesSo)
{
   _loggerMock->WriteProgramNameTimestampedThreadIdLineThenFlushMock.Expect();
   const size_t realTimeTextTradeTicksFilePathsSize = ZenUnit::Random<size_t>();
   const fs::path realTimeTextTradeTicksFolderPath = ZenUnit::Random<fs::path>();
   //
   _libTickDataMessageWriter.WriteMessage_Read(
      realTimeTextTradeTicksFilePathsSize, realTimeTextTradeTicksFolderPath);
   //
   const string expectedMessage = Utils::String::ConcatValues(
      "   Read ", realTimeTextTradeTicksFilePathsSize, " RealTimeTradeTicks files in ", realTimeTextTradeTicksFolderPath.string());
   METALMOCK(_loggerMock->WriteProgramNameTimestampedThreadIdLineThenFlushMock.CalledOnceWith(expectedMessage));
}

RUN_TESTS(LibTickDataMessageWriterTests)
