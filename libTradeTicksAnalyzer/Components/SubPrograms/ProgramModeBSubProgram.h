#pragma once
#include "libTradeTicksAnalyzer/Components/SubPrograms/SubProgram.h"

class ProgramModeBSubProgram : public SubProgram
{
   friend class ProgramModeBSubProgramTests;
public:
   ProgramModeBSubProgram();
   virtual ~ProgramModeBSubProgram() override;

   int Run() const override;
};
