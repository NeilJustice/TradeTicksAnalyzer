#pragma once
#include "libDateTime/Components/Args/ArgsParserMixin.h"

class FindPossibleBadBinaryTradeTicksArgsParser : public Time::ArgsParserMixin
{
   friend class FindPossibleBadBinaryTradeTicksArgsParserTests;
public:
   FindPossibleBadBinaryTradeTicksArgsParser();
   virtual ~FindPossibleBadBinaryTradeTicksArgsParser() override;
   virtual TradeTicksAnalyzerArgs ParseDocoptArgs(const map<string, docopt::Value>& docoptArgs) const;
};
