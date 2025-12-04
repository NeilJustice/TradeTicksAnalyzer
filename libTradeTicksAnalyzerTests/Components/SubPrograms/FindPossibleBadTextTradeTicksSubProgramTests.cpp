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
// Mutable Fields
TradeTicksAnalyzerArgs p_args;

STARTUP
{
   // Base Constant Components
   _findPossibleBadTextTradeTicksSubProgram.p_console.reset(p_consoleMock = new Time::ConsoleMock);
   // Constant Components
   _findPossibleBadTextTradeTicksSubProgram._multipleTextTradeTicksFilesReader.reset(_multipleTextTradeTicksFilesReaderMock = new TickData::MultipleTextTradeTicksFilesReaderMock);
   // Mutable Fields
   _findPossibleBadTextTradeTicksSubProgram.p_args = p_args = ZenUnit::Random<TradeTicksAnalyzerArgs>();
}

TEST(Run_Returns0)
{
   const vector<TickData::TradeTicksFileContent> allTradeTicksFileContents =
      _multipleTextTradeTicksFilesReaderMock->ReadAllRealTimeTextTradeTicksFilesMock.ReturnRandom();
   //
   const int exitCode = _findPossibleBadTextTradeTicksSubProgram.Run();
   //
   METALMOCK(_multipleTextTradeTicksFilesReaderMock->ReadAllRealTimeTextTradeTicksFilesMock.CalledOnceWith(
      p_args.tradingLogsOutputFolderPath_dateDashRunNumber_Polygon_FilteredRealTimeTextTradeTicks, p_args.parallel));
   IS_ZERO(exitCode);
}

RUN_TESTS(FindPossibleBadTextTradeTicksSubProgramTests)
