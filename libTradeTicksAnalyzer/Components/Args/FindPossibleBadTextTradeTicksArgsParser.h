#pragma once
#include "libDateTime/Components/Args/ArgsParserMixin.h"

class FindPossibleBadTextTradeTicksArgsParser : public Time::ArgsParserMixin
{
   friend class FindPossibleBadTextTradeTicksArgsParserTests;
public:
   FindPossibleBadTextTradeTicksArgsParser();
   virtual ~FindPossibleBadTextTradeTicksArgsParser() override;
   virtual TradeTicksAnalyzerArgs ParseDocoptArgs(const map<string, docopt::Value>& docoptArgs) const;
};
