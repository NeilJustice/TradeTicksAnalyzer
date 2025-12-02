#pragma once
#include "libDateTime/Components/Args/ArgsParserMixin.h"

class ProgramModeBArgsParser : public Time::ArgsParserMixin
{
   friend class ProgramModeBArgsParserTests;
public:
   ProgramModeBArgsParser();
   virtual ~ProgramModeBArgsParser() override;
   virtual TradeTicksAnalyzerArgs ParseDocoptArgs(const map<string, docopt::Value>& docoptArgs) const;
};
