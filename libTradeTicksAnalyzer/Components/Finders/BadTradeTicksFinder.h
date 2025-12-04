#pragma once
namespace Utils
{
   class FileAndFolderPathsGetter;
}
class TradeTicksAnalyzerMessageWriter;

class BadTradeTicksFinder
{
   friend class BadTradeTicksFinderTests;
private:
   // Constant Components
   unique_ptr<const Utils::FileAndFolderPathsGetter> _fileAndFolderPathsGetter;
   // Mutable Components
   unique_ptr<TradeTicksAnalyzerMessageWriter> _tradeTicksAnalyzerMessageWriter;
public:
   BadTradeTicksFinder();
   virtual ~BadTradeTicksFinder();
   virtual void Initialize(const Utils::Logger* logger);
   // Actions
   virtual void FindAllPossibleBadTradeTicks(
      const fs::path& realTimeTextTradeTicksInputFolderPath,
      const fs::path& possibleBadTradeTicksOutputFolderPath,
      bool parallel) const;
};
