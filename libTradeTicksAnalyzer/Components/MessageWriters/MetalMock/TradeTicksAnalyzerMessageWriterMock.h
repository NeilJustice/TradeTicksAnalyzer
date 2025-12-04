#pragma once
#include "libTradeTicksAnalyzer/Components/MessageWriters/TradeTicksAnalyzerMessageWriter.h"

class TradeTicksAnalyzerMessageWriterMock : public Metal::Mock<TradeTicksAnalyzerMessageWriter>
{
public:
   METALMOCK_VOID1(Initialize, const Utils::Logger*)
   // Actions
   METALMOCK_VOID2_CONST(WriteMessage_Reading,
      size_t, const fs::path&)
};
