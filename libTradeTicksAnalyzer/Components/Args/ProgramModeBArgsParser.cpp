#include "pch.h"
#include "libTradeTicksAnalyzer/Components/Args/ProgramModeBArgsParser.h"

ProgramModeBArgsParser::ProgramModeBArgsParser()
{
}

ProgramModeBArgsParser::~ProgramModeBArgsParser()
{
}

TradeTicksAnalyzerArgs ProgramModeBArgsParser::ParseDocoptArgs(const map<string, docopt::Value>& /*docoptArgs*/) const
{
   TradeTicksAnalyzerArgs args;
   args.programMode = ProgramMode::ProgramModeB;
   return args;
}
