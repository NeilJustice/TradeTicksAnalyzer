#pragma once
namespace Functional
{
   template<typename ReturnType, typename ClassType, typename Arg1Type>
   class NonVoidOneArgTryCatchCaller;
}
namespace Time
{
   class Console;
   class Stopwatch;
}
class TradeTicksAnalyzerArgsParser;
class SubProgramFactory;

class TradeTicksAnalyzerProgram
{
   friend class TradeTicksAnalyzerProgramTests;
private:
   // Function Callers
   using _nonVoidOneArgTryCatchCallerType = Functional::NonVoidOneArgTryCatchCaller<int, TradeTicksAnalyzerProgram, const vector<string>&>;
   unique_ptr<const _nonVoidOneArgTryCatchCallerType> _nonVoidOneArgTryCatchCaller;
   // Constant Components
   unique_ptr<const Time::Console> _console;
   unique_ptr<const TradeTicksAnalyzerArgsParser> _tradeTicksAnalyzerArgsParser;
   unique_ptr<const SubProgramFactory> _subProgramFactory;
   // Mutable Components
   unique_ptr<Time::Stopwatch> _stopwatch;
public:
   TradeTicksAnalyzerProgram();
   virtual ~TradeTicksAnalyzerProgram();
   int Main(int argc, char* argv[]);
private:
   int Run(const vector<string>& stringArgs);
   int ExceptionHandler_Run(
      string_view exceptionClassNameAndMessage, const vector<string>& stringArgs) const;
};
