#pragma once
#include "libTradeTicksAnalyzer/Components/Args/ProgramModeSpecificArgsParserDispatcher.h"

class ProgramModeSpecificArgsParserDispatcherMock : public Metal::Mock<ProgramModeSpecificArgsParserDispatcher>
{
public:
   METALMOCK_NONVOID1_CONST(TradeTicksAnalyzerArgs, ParseDocoptArgs, const TradeTicksAnalyzerArgMaps&)
};
