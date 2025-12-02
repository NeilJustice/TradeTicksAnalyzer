#include "pch.h"
#include "libTradeTicksAnalyzer/Components/Args/ProgramModeAArgsParser.h"

ProgramModeAArgsParser::ProgramModeAArgsParser()
{
}

ProgramModeAArgsParser::~ProgramModeAArgsParser()
{
}

TradeTicksAnalyzerArgs ProgramModeAArgsParser::ParseDocoptArgs(const map<string, docopt::Value>& docoptArgs) const
{
   TradeTicksAnalyzerArgs args;
   args.programMode = ProgramMode::ProgramModeA;
   args.requiredString = p_docoptParser->GetRequiredString(docoptArgs, "--required-string");
   args.parallel = p_docoptParser->GetOptionalBool(docoptArgs, "--parallel");
   return args;
}
