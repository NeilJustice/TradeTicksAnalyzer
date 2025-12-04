#include "libTickData/Components/MessageWriters/LibTickDataMessageWriter.h"

namespace TickData
{
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
}
