#include "pch.h"
#include "libTradeTicksAnalyzerTests/ValueTypes/ZenUnit/TradeTicksAnalyzerArgsEqualizerAndRandom.h"

TESTS(TradeTicksAnalyzerArgsEqualizerAndRandomTests)
AFACT(ZenUnitEqualizer_ThrowsIfAnyFieldsNotEqual)
AFACT(TestableRandomTradeTicksAnalyzerArgs_ReturnsAllNonDefaultFields)
EVIDENCE

TEST(ZenUnitEqualizer_ThrowsIfAnyFieldsNotEqual)
{
   ZENUNIT_EQUALIZER_TEST_SETUP(TradeTicksAnalyzerArgs);
   ZENUNIT_EQUALIZER_THROWS_WHEN_FIELD_NOT_EQUAL(TradeTicksAnalyzerArgs, programMode, ProgramMode::FindPossibleBadTradeTicks);
   ZENUNIT_EQUALIZER_THROWS_WHEN_FIELD_NOT_EQUAL(TradeTicksAnalyzerArgs, tradingLogsInputFolderPath, ZenUnit::Random<fs::path>());
   ZENUNIT_EQUALIZER_THROWS_WHEN_FIELD_NOT_EQUAL(TradeTicksAnalyzerArgs, date, ZenUnit::Random<Time::Date>());
   ZENUNIT_EQUALIZER_THROWS_WHEN_FIELD_NOT_EQUAL(TradeTicksAnalyzerArgs, runNumber, ZenUnit::RandomNon0<unsigned>());
   ZENUNIT_EQUALIZER_THROWS_WHEN_FIELD_NOT_EQUAL(TradeTicksAnalyzerArgs, parallel, true);
}

TEST(TestableRandomTradeTicksAnalyzerArgs_ReturnsAllNonDefaultFields)
{
   ZenUnit::RandomGeneratorMock randomGeneratorMock;
   Time::TimeRandomGeneratorMock timeRandomGeneratorMock;
   TradeTicksAnalyzerRandomGeneratorMock tradeTicksAnalyzerRandomGeneratorMock;

   const ProgramMode programMode = tradeTicksAnalyzerRandomGeneratorMock.RandomProgramModeMock.ReturnRandom();

   const fs::path tradingLogsInputFolderPath = randomGeneratorMock.FilesystemPathMock.ReturnRandom();

   const Time::Date date = timeRandomGeneratorMock.RandomDateMock.ReturnRandom();

   const unsigned runNumber = randomGeneratorMock.UnsignedMock.ReturnRandom();

   const bool parallel = randomGeneratorMock.BoolMock.ReturnRandom();
   //
   const TradeTicksAnalyzerArgs randomArgs = ZenUnit::TestableRandomTradeTicksAnalyzerArgs(
      &randomGeneratorMock,
      &timeRandomGeneratorMock,
      &tradeTicksAnalyzerRandomGeneratorMock);
   //
   METALMOCKTHEN(tradeTicksAnalyzerRandomGeneratorMock.RandomProgramModeMock.CalledOnce()).Then(
   METALMOCKTHEN(randomGeneratorMock.FilesystemPathMock.Called())).Then(
   METALMOCKTHEN(timeRandomGeneratorMock.RandomDateMock.CalledOnce())).Then(
   METALMOCKTHEN(randomGeneratorMock.UnsignedMock.CalledOnce())).Then(
   METALMOCKTHEN(randomGeneratorMock.BoolMock.CalledOnce()));
   TradeTicksAnalyzerArgs expectedRandomArgs;
   expectedRandomArgs.programMode = programMode;
   expectedRandomArgs.tradingLogsInputFolderPath = tradingLogsInputFolderPath;
   expectedRandomArgs.date = date;
   expectedRandomArgs.runNumber = runNumber;
   expectedRandomArgs.parallel = parallel;
   ARE_EQUAL(expectedRandomArgs, randomArgs);
}

RUN_TESTS(TradeTicksAnalyzerArgsEqualizerAndRandomTests)
