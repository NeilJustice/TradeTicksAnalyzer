#pragma once

class BadTradeTicksFinder
{
   friend class BadTradeTicksFinderTests;
private:
   // Non-Owned Constant Components
   const Utils::Logger* _logger;
public:
   BadTradeTicksFinder();
   virtual ~BadTradeTicksFinder();
   virtual void Initialize(const Utils::Logger* logger);
   // Actions
   virtual void FindAllPossibleBadTradeTicks(
      const vector<TickData::TradeTicksFileContent>& allTradeTicksFileContents,
      const fs::path& tradingLogsOutputFolderPath_dateDashRunNumber_Polygon_FilteredRealTimeTextTradeTicksDashPossibleBadTradeTicks,
      bool parallel) const;
};
