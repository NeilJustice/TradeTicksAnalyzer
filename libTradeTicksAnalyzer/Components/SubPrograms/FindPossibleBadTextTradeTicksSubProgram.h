#pragma once
#include "libTradeTicksAnalyzer/Components/SubPrograms/SubProgram.h"
namespace TickData
{
   class MultipleTextTradeTicksFilesReader;
}

class FindPossibleBadTextTradeTicksSubProgram : public SubProgram
{
   friend class FindPossibleBadTextTradeTicksSubProgramTests;
private:
   // Mutable Components
   unique_ptr<TickData::MultipleTextTradeTicksFilesReader> _multipleTextTradeTicksFilesReader;
public:
   FindPossibleBadTextTradeTicksSubProgram();
   virtual ~FindPossibleBadTextTradeTicksSubProgram() override;
   void DerivedInitialize() override;
   // Actions
   int Run() const override;
};
