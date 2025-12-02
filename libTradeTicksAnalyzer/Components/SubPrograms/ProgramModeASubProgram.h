#pragma once
#include "libTradeTicksAnalyzer/Components/SubPrograms/SubProgram.h"

class ProgramModeASubProgram : public SubProgram
{
   friend class ProgramModeASubProgramTests;
public:
   ProgramModeASubProgram();
   virtual ~ProgramModeASubProgram() override;

   int Run() const override;
};
