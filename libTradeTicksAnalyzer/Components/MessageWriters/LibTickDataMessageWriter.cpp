#include "pch.h"
#include "libTradeTicksAnalyzer/Components/MessageWriters/LibTickDataMessageWriter.h"

LibTickDataMessageWriter::LibTickDataMessageWriter()
   // Non-Owned Constant Components
   : _logger(nullptr)
{
}

LibTickDataMessageWriter::~LibTickDataMessageWriter()
{
}

void LibTickDataMessageWriter::Initialize(const Utils::Logger* logger)
{
   _logger = logger;
}

// Actions

void LibTickDataMessageWriter::WriteMessage_Reading(
   size_t realTimeTextTradeTicksFilePathsSize, const fs::path& realTimeTextTradeTicksFolderPath) const
{
   const string message = Utils::String::ConcatValues(
      "Reading ", realTimeTextTradeTicksFilePathsSize, " RealTimeTradeTicks files in ", realTimeTextTradeTicksFolderPath.string());
   _logger->WriteProgramNameTimestampedThreadIdLineThenFlush(message);
}

void LibTickDataMessageWriter::WriteMessage_Read(
   size_t realTimeTextTradeTicksFilePathsSize, const fs::path& realTimeTextTradeTicksFolderPath) const
{
   const string message = Utils::String::ConcatValues(
      "   Read ", realTimeTextTradeTicksFilePathsSize, " RealTimeTradeTicks files in ", realTimeTextTradeTicksFolderPath.string());
   _logger->WriteProgramNameTimestampedThreadIdLineThenFlush(message);
}
