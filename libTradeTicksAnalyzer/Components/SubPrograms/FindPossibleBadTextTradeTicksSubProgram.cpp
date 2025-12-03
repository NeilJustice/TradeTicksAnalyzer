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
      _textTradeTicksFileReader->ReadTextTradeTicksFile(
         R"(X:\Trading\TradingProgram\PaperTradingLogs\2025-12-03W-1\Polygon\AllRealTimeTextTradeTicks\ABBV-RealTimeTradeTicks.txt)",
         0,
         false);
   return 0;
}
