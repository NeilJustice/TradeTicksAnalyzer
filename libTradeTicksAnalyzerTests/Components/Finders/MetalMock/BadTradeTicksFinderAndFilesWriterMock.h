#pragma once
#include "libTradeTicksAnalyzer/Components/Finders/BadTradeTicksFinderAndFilesWriter.h"

class BadTradeTicksFinderAndFilesWriterMock : public Metal::Mock<BadTradeTicksFinderAndFilesWriter>
{
public:
   METALMOCK_VOID2(Initialize, const TradeTicksAnalyzerArgs&, const Utils::Logger*)
   // Actions
   METALMOCK_VOID2_CONST(FindAllPossibleBadTradeTicksAndWriteResultsFiles,
      const fs::path&,
      bool)
};
