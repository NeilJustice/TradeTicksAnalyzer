#pragma once
namespace Utils
{
   class DocoptParser;
}

class ProgramModeDeterminer
{
   friend class ProgramModeDeterminerTests;
private:
   // Constant Components
   unique_ptr<const Time::DocoptParser> _docoptParser;
public:
   ProgramModeDeterminer();
   virtual ~ProgramModeDeterminer();
   virtual ProgramMode DetermineProgramMode(const TradeTicksAnalyzerArgMaps& tradeTicksAnalyzerArgMaps) const;
};
