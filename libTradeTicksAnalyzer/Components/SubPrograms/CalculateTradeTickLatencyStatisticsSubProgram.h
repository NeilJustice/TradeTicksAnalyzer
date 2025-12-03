#pragma once
#include "libTradeTicksAnalyzer/Components/SubPrograms/SubProgram.h"

class CalculateTradeTickLatencyStatisticsSubProgram : public SubProgram
{
   friend class CalculateTradeTickLatencyStatisticsSubProgramTests;
public:
   CalculateTradeTickLatencyStatisticsSubProgram();
   virtual ~CalculateTradeTickLatencyStatisticsSubProgram() override;

   int Run() const override;
};
