#pragma once
#include "libTradeTicksAnalyzer/Components/SubPrograms/SubProgram.h"

class FindPossibleBadBinaryTradeTicksSubProgram : public SubProgram
{
   friend class FindPossibleBadBinaryTradeTicksSubProgramTests;
public:
   FindPossibleBadBinaryTradeTicksSubProgram();
   virtual ~FindPossibleBadBinaryTradeTicksSubProgram() override;

   int Run() const override;
};
