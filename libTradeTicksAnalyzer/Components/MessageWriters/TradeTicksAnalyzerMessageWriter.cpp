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

void TradeTicksAnalyzerMessageWriter::WriteMessage_ReadingAndFinding(
   size_t realTimeTextTradeTicksFilePathsSize, const fs::path& realTimeTextTradeTicksFolderPath) const
{
   const string message = Utils::String::ConcatValues(
      "Reading and finding possible bad trade ticks in ", realTimeTextTradeTicksFilePathsSize, " RealTimeTradeTicks files in ",
      realTimeTextTradeTicksFolderPath.string());
   _logger->WriteProgramNameTimestampedThreadIdLineThenFlush(message);
}
