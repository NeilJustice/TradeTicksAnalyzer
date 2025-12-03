#include "pch.h"
#include "libTradeTicksAnalyzer/Components/Args/FindPossibleBadBinaryTradeTicksArgsParser.h"

FindPossibleBadBinaryTradeTicksArgsParser::FindPossibleBadBinaryTradeTicksArgsParser()
{
}

FindPossibleBadBinaryTradeTicksArgsParser::~FindPossibleBadBinaryTradeTicksArgsParser()
{
}

TradeTicksAnalyzerArgs FindPossibleBadBinaryTradeTicksArgsParser::ParseDocoptArgs(const map<string, docopt::Value>& /*docoptArgs*/) const
{
   TradeTicksAnalyzerArgs args;
   args.programMode = ProgramMode::FindPossibleBadBinaryTradeTicks;
   return args;
}
