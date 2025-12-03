#pragma once
class FindPossibleBadTextTradeTicksArgsParser;
class CalculateTradeTickLatencyStatisticsArgsParser;
class ProgramModeDeterminer;

class ProgramModeSpecificArgsParserDispatcher
{
   friend class ProgramModeSpecificArgsParserDispatcherTests;
private:
   // Constant Components
   unique_ptr<const FindPossibleBadTextTradeTicksArgsParser> _findPossibleBadTextTradeTicksArgsParser;
   unique_ptr<const CalculateTradeTickLatencyStatisticsArgsParser> _calculateTradeTickLatencyStatisticsArgsParser;
   unique_ptr<const ProgramModeDeterminer> _programModeDeterminer;
public:
   ProgramModeSpecificArgsParserDispatcher();
   virtual ~ProgramModeSpecificArgsParserDispatcher();

   virtual TradeTicksAnalyzerArgs ParseDocoptArgs(const TradeTicksAnalyzerArgMaps& tradeTicksAnalyzerArgMaps) const;
};
