#include "pch.h"
#include "libTickData/Components/Files/TextTradeTicks/MetalMock/TextTradeTicksFileReaderMock.h"
#include "libTradeTicksAnalyzer/Components/SubPrograms/FindPossibleBadTextTradeTicksSubProgram.h"

TESTS(FindPossibleBadTextTradeTicksSubProgramTests)
AFACT(Run_Returns0)
EVIDENCE

FindPossibleBadTextTradeTicksSubProgram _findPossibleBadTextTradeTicksSubProgram;
// Base Constant Components
Time::ConsoleMock* p_consoleMock = nullptr;
// Constant Components
TickData::TextTradeTicksFileReaderMock* _textTradeTicksFileReaderMock = nullptr;

STARTUP
{
   // Base Constant Components
   _findPossibleBadTextTradeTicksSubProgram.p_console.reset(p_consoleMock = new Time::ConsoleMock);
   // Constant Components
   _findPossibleBadTextTradeTicksSubProgram._textTradeTicksFileReader.reset(_textTradeTicksFileReaderMock = new TickData::TextTradeTicksFileReaderMock);
}

TEST(Run_Returns0)
{
   const TickData::TradeTicksFileContent tradeTicksFileContent =
      _textTradeTicksFileReaderMock->ReadHistoricalTextTradeTicksFileMock.ReturnRandom();
   //
   const int exitCode = _findPossibleBadTextTradeTicksSubProgram.Run();
   //
   METALMOCK(_textTradeTicksFileReaderMock->ReadHistoricalTextTradeTicksFileMock.CalledOnceWith(
      R"(X:\Trading\TradingProgram\PaperTradingLogs\2025-12-03W-1\Polygon\AllRealTimeTextTradeTicks\ABBV-TradeTicks.txt)",
      0,
      false));
   IS_ZERO(exitCode);
}

RUN_TESTS(FindPossibleBadTextTradeTicksSubProgramTests)
