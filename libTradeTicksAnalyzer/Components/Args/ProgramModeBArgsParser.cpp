#include "pch.h"
#include "libTradeTicksAnalyzer/Components/Args/ProgramModeBArgsParser.h"

ProgramModeBArgsParser::ProgramModeBArgsParser()
{
}

ProgramModeBArgsParser::~ProgramModeBArgsParser()
{
}

TradeTicksAnalyzerArgs ProgramModeBArgsParser::ParseDocoptArgs(const map<string, docopt::Value>& docoptArgs) const
{
   TradeTicksAnalyzerArgs args;
   args.programMode = ProgramMode::ProgramModeB;
   args.requiredString = p_docoptParser->GetRequiredString(docoptArgs, "--required-string");
   args.parallel = p_docoptParser->GetOptionalBool(docoptArgs, "--parallel");
   return args;
}
