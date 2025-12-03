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
   const TickData::TradeTicksFileContent tradeTicksFileContent =
      _textTradeTicksFileReader->ReadRealTimeTextTradeTicksFile(
         R"(X:\Trading\TradingProgram\PaperTradingLogs\2025-12-03W-1\Polygon\AllRealTimeTextTradeTicks\ABBV-TradeTicks.txt)");
   return 0;
}
