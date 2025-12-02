#pragma once
#include "libTradeTicksAnalyzer/Components/SubPrograms/SubProgramFactory.h"

class SubProgramFactoryMock : public Metal::Mock<SubProgramFactory>
{
public:
   METALMOCK_NONVOID1_CONST(shared_ptr<SubProgram>, NewSubProgram, ProgramMode)
};
