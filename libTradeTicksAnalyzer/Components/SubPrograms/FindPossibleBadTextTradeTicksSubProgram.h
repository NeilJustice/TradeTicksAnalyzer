#pragma once
#include "libTradeTicksAnalyzer/Components/SubPrograms/SubProgram.h"
namespace TickData
{
   class TextTradeTicksFileReader;
}

class FindPossibleBadTextTradeTicksSubProgram : public SubProgram
{
   friend class FindPossibleBadTextTradeTicksSubProgramTests;
private:
   // Constant Components
   unique_ptr<const TickData::TextTradeTicksFileReader> _textTradeTicksFileReader;
public:
   FindPossibleBadTextTradeTicksSubProgram();
   virtual ~FindPossibleBadTextTradeTicksSubProgram() override;

   int Run() const override;
};
