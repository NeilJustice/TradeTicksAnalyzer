#include "pch.h"
#include "libTickData/Components/Files/TextTradeTicks/MetalMock/MultipleTextTradeTicksFilesReaderMock.h"
#include "libTradeTicksAnalyzer/Components/SubPrograms/FindPossibleBadTextTradeTicksSubProgram.h"

TESTS(FindPossibleBadTextTradeTicksSubProgramTests)
AFACT(Run_Returns0)
EVIDENCE

FindPossibleBadTextTradeTicksSubProgram _findPossibleBadTextTradeTicksSubProgram;
// Base Constant Components
Time::ConsoleMock* p_consoleMock = nullptr;
// Constant Components
TickData::MultipleTextTradeTicksFilesReaderMock* _multipleTextTradeTicksFilesReaderMock = nullptr;

STARTUP
{
   // Base Constant Components
   _findPossibleBadTextTradeTicksSubProgram.p_console.reset(p_consoleMock = new Time::ConsoleMock);
   // Constant Components
   _findPossibleBadTextTradeTicksSubProgram._multipleTextTradeTicksFilesReader.reset(_multipleTextTradeTicksFilesReaderMock = new TickData::MultipleTextTradeTicksFilesReaderMock);
}

TEST(Run_Returns0)
{
   //const TickData::TradeTicksFileContent tradeTicksFileContent =
   //   _textTradeTicksFileReaderMock->ReadRealTimeTextTradeTicksFileMock.ReturnRandom();
   //
   const int exitCode = _findPossibleBadTextTradeTicksSubProgram.Run();
   //
   //METALMOCK(_textTradeTicksFileReaderMock->ReadRealTimeTextTradeTicksFileMock.CalledOnceWith(
   //   R"(X:\Trading\TradingProgram\PaperTradingLogs\2025-12-03W-1\Polygon\AllRealTimeTextTradeTicks\ABBV-RealTimeTradeTicks.txt)"));
   IS_ZERO(exitCode);
}

RUN_TESTS(FindPossibleBadTextTradeTicksSubProgramTests)
