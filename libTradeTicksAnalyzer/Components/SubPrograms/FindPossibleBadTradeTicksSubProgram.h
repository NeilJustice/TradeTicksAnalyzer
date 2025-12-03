#pragma once
#include "libTradeTicksAnalyzer/Components/SubPrograms/SubProgram.h"

class FindPossibleBadTradeTicksSubProgram : public SubProgram
{
   friend class FindPossibleBadTradeTicksSubProgramTests;
public:
   FindPossibleBadTradeTicksSubProgram();
   virtual ~FindPossibleBadTradeTicksSubProgram() override;

   int Run() const override;
};
