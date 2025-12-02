#pragma once
namespace Time
{
   class PreamblePrinter;
}
class ProgramModeDeterminer;
class ProgramModeSpecificArgsParserDispatcher;

class TradeTicksAnalyzerArgsParser
{
   friend class ArgsParserTests;
private:
   // Constant Components
   unique_ptr<const Time::Console> _console;
   unique_ptr<const Time::DocoptParser> _docoptParser;
   unique_ptr<const Time::PreamblePrinter> _preamblePrinter;
   unique_ptr<const ProgramModeDeterminer> _programModeDeterminer;
   unique_ptr<const ProgramModeSpecificArgsParserDispatcher> _programModeSpecificArgsParserDispatcher;
public:
   TradeTicksAnalyzerArgsParser();
   virtual ~TradeTicksAnalyzerArgsParser();
   virtual TradeTicksAnalyzerArgs ParseStringArgs(const vector<string>& stringArgs) const;
};
