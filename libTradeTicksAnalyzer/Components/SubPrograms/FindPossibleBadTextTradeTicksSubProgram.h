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
   // Constant Components
   unique_ptr<const TickData::MultipleTextTradeTicksFilesReader> _multipleTextTradeTicksFilesReader;
public:
   FindPossibleBadTextTradeTicksSubProgram();
   virtual ~FindPossibleBadTextTradeTicksSubProgram() override;

   int Run() const override;
};
