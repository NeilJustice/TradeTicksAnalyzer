#include "pch.h"
#include "libTickData/Components/Files/TextTradeTicks/MetalMock/MultipleTextTradeTicksFilesReaderMock.h"
#include "libTradeTicksAnalyzer/Components/SubPrograms/FindPossibleBadTextTradeTicksSubProgram.h"
#include "libTradeTicksAnalyzerTests/Components/Finders/MetalMock/BadTradeTicksFinderMock.h"

TESTS(FindPossibleBadTextTradeTicksSubProgramTests)
AFACT(DerivedInitialize_DoesSo)
// Actions
AFACT(Run_Returns0)
EVIDENCE

FindPossibleBadTextTradeTicksSubProgram _findPossibleBadTextTradeTicksSubProgram;
// Base Constant Components
Time::ConsoleMock* p_consoleMock = nullptr;
// Mutable Components
BadTradeTicksFinderMock* _badTradeTicksFinderMock = nullptr;
TickData::MultipleTextTradeTicksFilesReaderMock* _multipleTextTradeTicksFilesReaderMock = nullptr;
// Mutable Fields
TradeTicksAnalyzerArgs p_args;

STARTUP
{
   // Base Constant Components
   _findPossibleBadTextTradeTicksSubProgram.p_console.reset(p_consoleMock = new Time::ConsoleMock);
   // Mutable Components
   _findPossibleBadTextTradeTicksSubProgram._badTradeTicksFinder.reset(_badTradeTicksFinderMock = new BadTradeTicksFinderMock);
   _findPossibleBadTextTradeTicksSubProgram._multipleTextTradeTicksFilesReader.reset(_multipleTextTradeTicksFilesReaderMock = new TickData::MultipleTextTradeTicksFilesReaderMock);
   // Mutable Fields
   _findPossibleBadTextTradeTicksSubProgram.p_args = p_args = ZenUnit::Random<TradeTicksAnalyzerArgs>();
}

TEST(DerivedInitialize_DoesSo)
{
   _multipleTextTradeTicksFilesReaderMock->InitializeMock.Expect();
   _badTradeTicksFinderMock->InitializeMock.Expect();
   //
   _findPossibleBadTextTradeTicksSubProgram.DerivedInitialize();
   //
   METALMOCKTHEN(_multipleTextTradeTicksFilesReaderMock->InitializeMock.CalledOnceWith(p_consoleMock)).Then(
   METALMOCKTHEN(_badTradeTicksFinderMock->InitializeMock.CalledOnceWith(p_consoleMock)));
}

// Actions

TEST(Run_Returns0)
{
   const vector<TickData::TradeTicksFileContent> allTradeTicksFileContents =
      _multipleTextTradeTicksFilesReaderMock->ReadAllRealTimeTextTradeTicksFilesMock.ReturnRandom();
   _badTradeTicksFinderMock->FindAllPossibleBadTradeTicksMock.Expect();
   //
   const int exitCode = _findPossibleBadTextTradeTicksSubProgram.Run();
   //
   METALMOCKTHEN(_multipleTextTradeTicksFilesReaderMock->ReadAllRealTimeTextTradeTicksFilesMock.CalledOnceWith(
      p_args.tradingLogsInputFolderPath_dateDashRunNumber_Polygon_FilteredRealTimeTextTradeTicks, p_args.parallel)).Then(
   METALMOCKTHEN(_badTradeTicksFinderMock->FindAllPossibleBadTradeTicksMock.CalledOnceWith(
      allTradeTicksFileContents,
      p_args.tradingLogsOutputFolderPath_dateDashRunNumber_Polygon_FilteredRealTimeTextTradeTicksDashPossibleBadTradeTicks,
      p_args.parallel)));
   IS_ZERO(exitCode);
}

RUN_TESTS(FindPossibleBadTextTradeTicksSubProgramTests)
