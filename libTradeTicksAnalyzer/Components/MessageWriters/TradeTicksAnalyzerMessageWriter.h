#pragma once
namespace Utils
{
   class Logger;
}
class TradeTicksAnalyzerMessageWriterTests;

class TradeTicksAnalyzerMessageWriter
{
   friend class ::TradeTicksAnalyzerMessageWriterTests;
private:
   // Non-Owned Constant Components
   const Utils::Logger* _logger;
public:
   TradeTicksAnalyzerMessageWriter();
   virtual ~TradeTicksAnalyzerMessageWriter();
   virtual void Initialize(const Utils::Logger* logger);
   // Actions
   virtual void WriteMessage_Reading(
      size_t realTimeTextTradeTicksFilePathsSize, const fs::path& realTimeTextTradeTicksFolderPath) const;

   virtual void WriteMessage_Read(
      size_t realTimeTextTradeTicksFilePathsSize, const fs::path& realTimeTextTradeTicksFolderPath) const;
};
