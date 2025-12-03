#pragma once
class FindPossibleBadTradeTicksArgsParser;
class ProgramModeBArgsParser;
class ProgramModeDeterminer;

class ProgramModeSpecificArgsParserDispatcher
{
   friend class ProgramModeSpecificArgsParserDispatcherTests;
private:
   // Constant Components
   unique_ptr<const FindPossibleBadTradeTicksArgsParser> _findPossibleBadTradeTicksArgsParser;
   unique_ptr<const ProgramModeBArgsParser> _programModeBArgsParser;
   unique_ptr<const ProgramModeDeterminer> _programModeDeterminer;
public:
   ProgramModeSpecificArgsParserDispatcher();
   virtual ~ProgramModeSpecificArgsParserDispatcher();
   virtual TradeTicksAnalyzerArgs ParseDocoptArgs(const TradeTicksAnalyzerArgMaps& tradeTicksAnalyzerArgMaps) const;
};
