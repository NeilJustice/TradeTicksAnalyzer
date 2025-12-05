#include "pch.h"
#include "libTradeTicksAnalyzer/Components/SubPrograms/FindPossibleBadTextTradeTicksSubProgram.h"
#include "libTradeTicksAnalyzerTests/Components/Finders/MetalMock/BadTradeTicksFinderAndFilesWriterMock.h"

TESTS(FindPossibleBadTextTradeTicksSubProgramTests)
AFACT(DerivedInitialize_DoesSo)
// Actions
AFACT(Run_Returns0)
EVIDENCE

FindPossibleBadTextTradeTicksSubProgram _findPossibleBadTextTradeTicksSubProgram;
// Base Constant Components
Time::ConsoleMock* p_consoleMock = nullptr;
// Mutable Components
BadTradeTicksFinderAndFilesWriterMock* _badTradeTicksFinderAndFilesWriterMock = nullptr;
// Mutable Fields
TradeTicksAnalyzerArgs p_args;

STARTUP
{
   // Base Constant Components
   _findPossibleBadTextTradeTicksSubProgram.p_console.reset(p_consoleMock = new Time::ConsoleMock);
   // Mutable Components
   _findPossibleBadTextTradeTicksSubProgram._badTradeTicksFinderAndFilesWriter.reset(_badTradeTicksFinderAndFilesWriterMock = new BadTradeTicksFinderAndFilesWriterMock);
   // Mutable Fields
   _findPossibleBadTextTradeTicksSubProgram.p_args = p_args = ZenUnit::Random<TradeTicksAnalyzerArgs>();
}

TEST(DerivedInitialize_DoesSo)
{
   _badTradeTicksFinderAndFilesWriterMock->InitializeMock.Expect();
   //
   _findPossibleBadTextTradeTicksSubProgram.DerivedInitialize();
   //
   METALMOCK(_badTradeTicksFinderAndFilesWriterMock->InitializeMock.CalledOnceWith(p_args, p_consoleMock));
}

// Actions

TEST(Run_Returns0)
{
   _badTradeTicksFinderAndFilesWriterMock->FindAllPossibleBadTradeTicksAndWriteResultsFilesMock.Expect();
   //
   const int exitCode = _findPossibleBadTextTradeTicksSubProgram.Run();
   //
   METALMOCK(_badTradeTicksFinderAndFilesWriterMock->FindAllPossibleBadTradeTicksAndWriteResultsFilesMock.CalledOnceWith(
      p_args.tradingLogsInputFolderPath_dateDashRunNumber_Polygon_FilteredRealTimeTextTradeTicks, p_args.parallel));
   IS_ZERO(exitCode);
}

RUN_TESTS(FindPossibleBadTextTradeTicksSubProgramTests)
