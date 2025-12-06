#include "pch.h"
#include "libTradeTicksAnalyzer/Components/MessageWriters/TradeTicksAnalyzerMessageWriter.h"

TradeTicksAnalyzerMessageWriter::TradeTicksAnalyzerMessageWriter()
   // Non-Owned Constant Components
   : _logger(nullptr)
{
}

TradeTicksAnalyzerMessageWriter::~TradeTicksAnalyzerMessageWriter()
{
}

void TradeTicksAnalyzerMessageWriter::Initialize(const Utils::Logger* logger)
{
   _logger = logger;
}

// Actions

void TradeTicksAnalyzerMessageWriter::WriteMessage_ReadingAndFindingPossibleBadTradeTicks(
   size_t realTimeTextTradeTicksFilePathsSize, const fs::path& realTimeTextTradeTicksInputFolderPath) const
{
   const string message = Utils::String::ConcatValues(
      "Finding possible bad trade ticks in ", realTimeTextTradeTicksFilePathsSize, " RealTimeTradeTicks files in ",
      realTimeTextTradeTicksInputFolderPath.string());
   _logger->WriteProgramNameTimestampedThreadIdLineThenFlush(message);
}

void TradeTicksAnalyzerMessageWriter::WriteExceptionMessage_FindPossibleBadTradeTicks_ThenExit1(
   string_view exceptionClassNameAndMessage, const fs::path& realTimeTextTradeTicksInputFilePath) const
{
   const string enhancedExceptionMessage = Utils::String::ConcatStrings(
      "Exception thrown while calling BadTradeTicksFinderAndFilesWriter::FindPossibleBadTradeTicks:\n",
      exceptionClassNameAndMessage, "\n",
      "realTimeTextTradeTicksInputFilePath=", realTimeTextTradeTicksInputFilePath.string());
   _logger->WriteProgramNameTimestampedThreadIdLineInRedThenExitWithCode1IfConsole(enhancedExceptionMessage);
}
