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
   virtual void WriteMessage_ReadingAndFindingPossibleBadTradeTicks(
      size_t realTimeTextTradeTicksFilePathsSize, const fs::path& realTimeTextTradeTicksFolderPath) const;

   virtual void WriteFatalExceptionMessage_FindPossibleBadTradeTicks(
      string_view exceptionClassNameAndMessage, const fs::path& realTimeTextTradeTicksInputFilePath) const;
};
