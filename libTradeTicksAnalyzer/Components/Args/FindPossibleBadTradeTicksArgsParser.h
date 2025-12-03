#pragma once
#include "libDateTime/Components/Args/ArgsParserMixin.h"

class FindPossibleBadTradeTicksArgsParser : public Time::ArgsParserMixin
{
   friend class FindPossibleBadTradeTicksArgsParserTests;
public:
   FindPossibleBadTradeTicksArgsParser();
   virtual ~FindPossibleBadTradeTicksArgsParser() override;
   virtual TradeTicksAnalyzerArgs ParseDocoptArgs(const map<string, docopt::Value>& docoptArgs) const;
};
