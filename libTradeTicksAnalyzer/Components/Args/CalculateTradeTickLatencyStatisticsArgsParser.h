#pragma once
#include "libDateTime/Components/Args/ArgsParserMixin.h"

class CalculateTradeTickLatencyStatisticsArgsParser : public Time::ArgsParserMixin
{
   friend class CalculateTradeTickLatencyStatisticsArgsParserTests;
public:
   CalculateTradeTickLatencyStatisticsArgsParser();
   virtual ~CalculateTradeTickLatencyStatisticsArgsParser() override;
   virtual TradeTicksAnalyzerArgs ParseDocoptArgs(const map<string, docopt::Value>& docoptArgs) const;
};
