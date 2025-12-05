#include "pch.h"
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
// Mutable Fields
TradeTicksAnalyzerArgs p_args;

STARTUP
{
   // Base Constant Components
   _findPossibleBadTextTradeTicksSubProgram.p_console.reset(p_consoleMock = new Time::ConsoleMock);
   // Mutable Components
   _findPossibleBadTextTradeTicksSubProgram._badTradeTicksFinder.reset(_badTradeTicksFinderMock = new BadTradeTicksFinderMock);
   // Mutable Fields
   _findPossibleBadTextTradeTicksSubProgram.p_args = p_args = ZenUnit::Random<TradeTicksAnalyzerArgs>();
}

TEST(DerivedInitialize_DoesSo)
{
   _badTradeTicksFinderMock->InitializeMock.Expect();
   //
   _findPossibleBadTextTradeTicksSubProgram.DerivedInitialize();
   //
   METALMOCK(_badTradeTicksFinderMock->InitializeMock.CalledOnceWith(p_args, p_consoleMock));
}

// Actions

TEST(Run_Returns0)
{
   _badTradeTicksFinderMock->FindAllPossibleBadTradeTicksMock.Expect();
   //
   const int exitCode = _findPossibleBadTextTradeTicksSubProgram.Run();
   //
   METALMOCK(_badTradeTicksFinderMock->FindAllPossibleBadTradeTicksMock.CalledOnceWith(
      p_args.tradingLogsInputFolderPath_dateDashRunNumber_Polygon_FilteredRealTimeTextTradeTicks,
      p_args.tradingLogsOutputFolderPath_dateDashRunNumber_Polygon_FilteredRealTimeTextTradeTicksDashPossibleBadTradeTicks,
      p_args.parallel));
   IS_ZERO(exitCode);
}

RUN_TESTS(FindPossibleBadTextTradeTicksSubProgramTests)
