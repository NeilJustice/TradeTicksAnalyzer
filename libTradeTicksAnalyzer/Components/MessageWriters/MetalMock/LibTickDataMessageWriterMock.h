#pragma once
#include "libTradeTicksAnalyzer/Components/MessageWriters/LibTickDataMessageWriter.h"

class LibTickDataMessageWriterMock : public Metal::Mock<LibTickDataMessageWriter>
{
public:
   METALMOCK_VOID1(Initialize, const Utils::Logger*)
   // Actions
   METALMOCK_VOID2_CONST(WriteMessage_Reading,
      size_t, const fs::path&)

   METALMOCK_VOID2_CONST(WriteMessage_Read,
      size_t, const fs::path&)
};
