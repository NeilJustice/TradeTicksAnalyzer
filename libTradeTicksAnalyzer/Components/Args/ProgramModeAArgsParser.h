#pragma once
#include "libDateTime/Components/Args/ArgsParserMixin.h"

class ProgramModeAArgsParser : public Time::ArgsParserMixin
{
   friend class ProgramModeAArgsParserTests;
public:
   ProgramModeAArgsParser();
   virtual ~ProgramModeAArgsParser() override;
   virtual TradeTicksAnalyzerArgs ParseDocoptArgs(const map<string, docopt::Value>& docoptArgs) const;
};
