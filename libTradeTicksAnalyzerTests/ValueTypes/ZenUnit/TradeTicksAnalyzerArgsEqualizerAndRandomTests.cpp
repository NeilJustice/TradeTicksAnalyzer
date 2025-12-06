#include "pch.h"
#include "libTradeTicksAnalyzerTests/ValueTypes/ZenUnit/TradeTicksAnalyzerArgsEqualizerAndRandom.h"

TESTS(TradeTicksAnalyzerArgsEqualizerAndRandomTests)
AFACT(ZenUnitEqualizer_ThrowsIfAnyFieldsNotEqual)
AFACT(TestableRandomTradeTicksAnalyzerArgs_ReturnsAllNonDefaultFields)
EVIDENCE

TEST(ZenUnitEqualizer_ThrowsIfAnyFieldsNotEqual)
{
   ZENUNIT_EQUALIZER_TEST_SETUP(TradeTicksAnalyzerArgs);
   ZENUNIT_EQUALIZER_THROWS_WHEN_FIELD_NOT_EQUAL(TradeTicksAnalyzerArgs, programMode, ProgramMode::FindPossibleBadTextTradeTicks);
   ZENUNIT_EQUALIZER_THROWS_WHEN_FIELD_NOT_EQUAL(TradeTicksAnalyzerArgs, tradingLogsInputFolderPath, ZenUnit::Random<fs::path>());
   ZENUNIT_EQUALIZER_THROWS_WHEN_FIELD_NOT_EQUAL(TradeTicksAnalyzerArgs, dateWithDayOfWeek, ZenUnit::Random<Time::DateWithDayOfWeek>());
   ZENUNIT_EQUALIZER_THROWS_WHEN_FIELD_NOT_EQUAL(TradeTicksAnalyzerArgs, runNumber, ZenUnit::RandomNon0<unsigned>());
   ZENUNIT_EQUALIZER_THROWS_WHEN_FIELD_NOT_EQUAL(TradeTicksAnalyzerArgs, parallel, true);
   // Calculated Fields
   ZENUNIT_EQUALIZER_THROWS_WHEN_FIELD_NOT_EQUAL(TradeTicksAnalyzerArgs, tradingLogsInputFolderPath_dateDashRunNumber_Polygon_FilteredRealTimeTextTradeTicks, ZenUnit::Random<fs::path>());
   ZENUNIT_EQUALIZER_THROWS_WHEN_FIELD_NOT_EQUAL(TradeTicksAnalyzerArgs, tradingLogsOutputFolderPath_dateDashRunNumber_Polygon_FilteredRealTimeTextTradeTicksDashPossibleBad, ZenUnit::Random<fs::path>());
}

TEST(TestableRandomTradeTicksAnalyzerArgs_ReturnsAllNonDefaultFields)
{
   ZenUnit::RandomGeneratorMock randomGeneratorMock;
   Time::TimeRandomGeneratorMock timeRandomGeneratorMock;
   TradeTicksAnalyzerRandomGeneratorMock tradeTicksAnalyzerRandomGeneratorMock;

   const ProgramMode programMode = tradeTicksAnalyzerRandomGeneratorMock.RandomProgramModeMock.ReturnRandom();

   const float badTickChangePercentThreshold = randomGeneratorMock.FloatMock.ReturnRandom();

   const fs::path tradingLogsInputFolderPath = ZenUnit::Random<fs::path>();
   const fs::path tradingLogsOutputFolderPath = ZenUnit::Random<fs::path>();
   const fs::path tradingLogsInputFolderPath_dateDashRunNumber_Polygon_FilteredRealTimeTextTradeTicks = ZenUnit::Random<fs::path>();
   const fs::path tradingLogsOutputFolderPath_dateDashRunNumber_Polygon_FilteredRealTimeTextTradeTicksDashPossibleBad = ZenUnit::Random<fs::path>();
   randomGeneratorMock.FilesystemPathMock.ReturnValues(
      tradingLogsInputFolderPath,
      tradingLogsOutputFolderPath,
      tradingLogsInputFolderPath_dateDashRunNumber_Polygon_FilteredRealTimeTextTradeTicks,
      tradingLogsOutputFolderPath_dateDashRunNumber_Polygon_FilteredRealTimeTextTradeTicksDashPossibleBad);

   const Time::DateWithDayOfWeek dateWithDayOfWeek = timeRandomGeneratorMock.RandomDateWithDayOfWeekMock.ReturnRandom();

   const unsigned runNumber = randomGeneratorMock.UnsignedMock.ReturnRandom();

   const bool parallel = randomGeneratorMock.BoolMock.ReturnRandom();
   //
   const TradeTicksAnalyzerArgs randomArgs = ZenUnit::TestableRandomTradeTicksAnalyzerArgs(
      &randomGeneratorMock,
      &timeRandomGeneratorMock,
      &tradeTicksAnalyzerRandomGeneratorMock);
   //
   METALMOCK(randomGeneratorMock.FilesystemPathMock.CalledNTimes(4));
   METALMOCKTHEN(tradeTicksAnalyzerRandomGeneratorMock.RandomProgramModeMock.CalledOnce()).Then(
   METALMOCKTHEN(randomGeneratorMock.FilesystemPathMock.Called())).Then(
   METALMOCKTHEN(timeRandomGeneratorMock.RandomDateWithDayOfWeekMock.CalledOnce())).Then(
   METALMOCKTHEN(randomGeneratorMock.UnsignedMock.CalledOnce())).Then(
   METALMOCKTHEN(randomGeneratorMock.FloatMock.CalledOnce())).Then(
   METALMOCKTHEN(randomGeneratorMock.FilesystemPathMock.Called())).Then(
   METALMOCKTHEN(randomGeneratorMock.BoolMock.CalledOnce())).Then(
   // Calculated Fields
   METALMOCKTHEN(randomGeneratorMock.FilesystemPathMock.Called())).Then(
   METALMOCKTHEN(randomGeneratorMock.FilesystemPathMock.Called()));
   TradeTicksAnalyzerArgs expectedRandomArgs;
   expectedRandomArgs.programMode = programMode;
   expectedRandomArgs.tradingLogsInputFolderPath = tradingLogsInputFolderPath;
   expectedRandomArgs.dateWithDayOfWeek = dateWithDayOfWeek;
   expectedRandomArgs.runNumber = runNumber;
   expectedRandomArgs.badTickChangePercentThreshold = badTickChangePercentThreshold;
   expectedRandomArgs.tradingLogsOutputFolderPath = tradingLogsOutputFolderPath;
   expectedRandomArgs.parallel = parallel;
   // Calculated Fields
   expectedRandomArgs.tradingLogsInputFolderPath_dateDashRunNumber_Polygon_FilteredRealTimeTextTradeTicks = tradingLogsInputFolderPath_dateDashRunNumber_Polygon_FilteredRealTimeTextTradeTicks;
   expectedRandomArgs.tradingLogsOutputFolderPath_dateDashRunNumber_Polygon_FilteredRealTimeTextTradeTicksDashPossibleBad = tradingLogsOutputFolderPath_dateDashRunNumber_Polygon_FilteredRealTimeTextTradeTicksDashPossibleBad;
   ARE_EQUAL(expectedRandomArgs, randomArgs);
}

RUN_TESTS(TradeTicksAnalyzerArgsEqualizerAndRandomTests)
