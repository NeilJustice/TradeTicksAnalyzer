#include "pch.h"
#include "libCppUtils/StaticUtilities/Vector.h"
#include "libDateTime/Components/Args/MetalMock/PreamblePrinterMock.h"
#include "libTradeTicksAnalyzer/Components/Args/TradeTicksAnalyzerArgsParser.h"
#include "libTradeTicksAnalyzerTests/Components/Args/MetalMock/ProgramModeDeterminerMock.h"
#include "libTradeTicksAnalyzerTests/Components/Args/MetalMock/ProgramModeSpecificArgsParserDispatcherMock.h"

TESTS(ArgsParserTests)
AFACT(DefaultConstructor_SetsTradeTicksAnalyzer)
AFACT(ParseStringArgs_DoesSo)
EVIDENCE

TradeTicksAnalyzerArgsParser _tradeTicksAnalyzerArgsParser;
// Constant Components
Time::ConsoleMock* _consoleMock = nullptr;
Time::DocoptParserMock* _docoptParserMock = nullptr;
Time::PreamblePrinterMock* _preamblePrinterMock = nullptr;
ProgramModeDeterminerMock* _programModeDeterminerMock = nullptr;
ProgramModeSpecificArgsParserDispatcherMock* _programModeSpecificArgsParserDispatcherMock = nullptr;

STARTUP
{
   // Constant Components
   _tradeTicksAnalyzerArgsParser._console.reset(_consoleMock = new Time::ConsoleMock);
   _tradeTicksAnalyzerArgsParser._docoptParser.reset(_docoptParserMock = new Time::DocoptParserMock);
   _tradeTicksAnalyzerArgsParser._preamblePrinter.reset(_preamblePrinterMock = new Time::PreamblePrinterMock);
   _tradeTicksAnalyzerArgsParser._programModeDeterminer.reset(_programModeDeterminerMock = new ProgramModeDeterminerMock);
   _tradeTicksAnalyzerArgsParser._programModeSpecificArgsParserDispatcher.reset(_programModeSpecificArgsParserDispatcherMock = new ProgramModeSpecificArgsParserDispatcherMock);
}

TEST(DefaultConstructor_SetsTradeTicksAnalyzer)
{
   const TradeTicksAnalyzerArgsParser tradeTicksAnalyzerArgsParser;
   ARE_EQUAL("TradeTicksAnalyzer", tradeTicksAnalyzerArgsParser._console->ProgramName());
}

TEST(ParseStringArgs_DoesSo)
{
   _preamblePrinterMock->PrintPreambleMock.ReturnRandom();

   const map<string, docopt::Value> docoptArgs_program_mode_a = ZenUnit::RandomNonEmptyOrderedMap<string, docopt::Value>();
   const map<string, docopt::Value> docoptArgs_program_mode_b = ZenUnit::RandomNonEmptyOrderedMap<string, docopt::Value>();
   _docoptParserMock->ParseStringArgsMock.ReturnValues(
      docoptArgs_program_mode_a,
      docoptArgs_program_mode_b);

   const TradeTicksAnalyzerArgs args = _programModeSpecificArgsParserDispatcherMock->ParseDocoptArgsMock.ReturnRandom();

   const vector<string> stringArgs = ZenUnit::RandomVector<string>();
   //
   const TradeTicksAnalyzerArgs returnedArgs = _tradeTicksAnalyzerArgsParser.ParseStringArgs(stringArgs);
   //
   const TradeTicksAnalyzerArgMaps expectedTradeTicksAnalyzerArgMaps
   {
      docoptArgs_program_mode_a,
      docoptArgs_program_mode_b
   };
   METALMOCK(_docoptParserMock->ParseStringArgsMock.CalledNTimes(2));

   METALMOCKTHEN(_preamblePrinterMock->PrintPreambleMock.CalledOnceWith(
      stringArgs, _consoleMock)).Then(

   METALMOCKTHEN(_docoptParserMock->ParseStringArgsMock.CalledWith(
      TradeTicksAnalyzerArgs::CommandLineUsage_program_mode_a, stringArgs, false))).Then(

   METALMOCKTHEN(_docoptParserMock->ParseStringArgsMock.CalledWith(
      TradeTicksAnalyzerArgs::CommandLineUsage_program_mode_b, stringArgs, false))).Then(

   METALMOCKTHEN(_programModeSpecificArgsParserDispatcherMock->ParseDocoptArgsMock.CalledOnceWith(
      expectedTradeTicksAnalyzerArgMaps)));

   ARE_EQUAL(args, returnedArgs);
}

RUN_TESTS(ArgsParserTests)
