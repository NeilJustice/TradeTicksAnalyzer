#pragma once
#include "libTradeTicksAnalyzer/Components/MessageWriters/TradeTicksAnalyzerMessageWriter.h"

class TradeTicksAnalyzerMessageWriterMock : public Metal::Mock<TradeTicksAnalyzerMessageWriter>
{
public:
   METALMOCK_VOID1(Initialize, const Utils::Logger*)
   // Actions
   METALMOCK_VOID2_CONST(WriteMessage_ReadingAndFindingPossibleBadTradeTicks,
      size_t, const fs::path&)

   METALMOCK_VOID2_CONST(WriteFatalExceptionMessage_FindPossibleBadTradeTicks,
      string_view, const fs::path&)
};
