#pragma once
#include "libTradeTicksAnalyzer/Components/SubPrograms/SubProgram.h"

class FindPossibleBadTextTradeTicksSubProgram : public SubProgram
{
   friend class FindPossibleBadTextTradeTicksSubProgramTests;
public:
   FindPossibleBadTextTradeTicksSubProgram();
   virtual ~FindPossibleBadTextTradeTicksSubProgram() override;

   int Run() const override;
};
