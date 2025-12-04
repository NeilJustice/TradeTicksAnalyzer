#pragma once
#include "libTradeTicksAnalyzer/Components/SubPrograms/SubProgram.h"
class BadTradeTicksFinder;

class FindPossibleBadTextTradeTicksSubProgram : public SubProgram
{
   friend class FindPossibleBadTextTradeTicksSubProgramTests;
private:
   // Mutable Components
   unique_ptr<BadTradeTicksFinder> _badTradeTicksFinder;
public:
   FindPossibleBadTextTradeTicksSubProgram();
   virtual ~FindPossibleBadTextTradeTicksSubProgram() override;
   void DerivedInitialize() override;
   // Actions
   int Run() const override;
};
