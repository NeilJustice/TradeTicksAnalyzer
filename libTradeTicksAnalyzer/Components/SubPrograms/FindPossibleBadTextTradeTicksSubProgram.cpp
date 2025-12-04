#include "pch.h"
#include "libTickData/Components/Files/TextTradeTicks/MultipleTextTradeTicksFilesReader.h"
#include "libTradeTicksAnalyzer/Components/SubPrograms/FindPossibleBadTextTradeTicksSubProgram.h"

FindPossibleBadTextTradeTicksSubProgram::FindPossibleBadTextTradeTicksSubProgram()
   // Constant Components
   : _multipleTextTradeTicksFilesReader(make_unique<TickData::MultipleTextTradeTicksFilesReader>())
{
}

FindPossibleBadTextTradeTicksSubProgram::~FindPossibleBadTextTradeTicksSubProgram()
{
}

int FindPossibleBadTextTradeTicksSubProgram::Run() const
{

   //const TickData::TradeTicksFileContent tradeTicksFileContent =
   //   _textTradeTicksFileReader->ReadRealTimeTextTradeTicksFile(
   //      R"(X:\Trading\TradingProgram\PaperTradingLogs\2025-12-03W-1\Polygon\AllRealTimeTextTradeTicks\ABBV-RealTimeTradeTicks.txt)");
   return 0;
}
