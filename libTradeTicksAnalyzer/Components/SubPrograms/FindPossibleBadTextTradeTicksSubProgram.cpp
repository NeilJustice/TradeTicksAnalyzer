#include "pch.h"
#include "libTickData/Components/Files/TextTradeTicks/TextTradeTicksFileReader.h"
#include "libTradeTicksAnalyzer/Components/SubPrograms/FindPossibleBadTextTradeTicksSubProgram.h"

FindPossibleBadTextTradeTicksSubProgram::FindPossibleBadTextTradeTicksSubProgram()
   // Constant Components
   : _textTradeTicksFileReader(make_unique<TickData::TextTradeTicksFileReader>())
{
}

FindPossibleBadTextTradeTicksSubProgram::~FindPossibleBadTextTradeTicksSubProgram()
{
}

int FindPossibleBadTextTradeTicksSubProgram::Run() const
{


   return 0;
}
