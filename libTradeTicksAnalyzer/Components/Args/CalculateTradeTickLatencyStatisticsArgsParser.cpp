#include "pch.h"
#include "libTradeTicksAnalyzer/Components/Args/CalculateTradeTickLatencyStatisticsArgsParser.h"

CalculateTradeTickLatencyStatisticsArgsParser::CalculateTradeTickLatencyStatisticsArgsParser()
{
}

CalculateTradeTickLatencyStatisticsArgsParser::~CalculateTradeTickLatencyStatisticsArgsParser()
{
}

TradeTicksAnalyzerArgs CalculateTradeTickLatencyStatisticsArgsParser::ParseDocoptArgs(const map<string, docopt::Value>& /*docoptArgs*/) const
{
   TradeTicksAnalyzerArgs args;
   args.programMode = ProgramMode::CalculateTradeTickLatencyStatistics;
   return args;
}
