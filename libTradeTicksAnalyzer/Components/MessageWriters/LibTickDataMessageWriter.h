#pragma once
namespace Utils
{
   class Logger;
}
class LibTickDataMessageWriterTests;

namespace TickData
{
   class LibTickDataMessageWriter
   {
      friend class ::LibTickDataMessageWriterTests;
   private:
      // Non-Owned Constant Components
      const Utils::Logger* _logger;
   public:
      LibTickDataMessageWriter();
      virtual ~LibTickDataMessageWriter();
      virtual void Initialize(const Utils::Logger* logger);
      // Actions
      virtual void WriteMessage_Reading(
         size_t realTimeTextTradeTicksFilePathsSize, const fs::path& realTimeTextTradeTicksFolderPath) const;

      virtual void WriteMessage_Read(
         size_t realTimeTextTradeTicksFilePathsSize, const fs::path& realTimeTextTradeTicksFolderPath) const;
   };
}
