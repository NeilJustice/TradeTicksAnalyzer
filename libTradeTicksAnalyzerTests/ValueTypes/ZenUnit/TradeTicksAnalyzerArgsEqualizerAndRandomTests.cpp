#include "pch.h"
#include "libTradeTicksAnalyzerTests/ValueTypes/ZenUnit/TradeTicksAnalyzerArgsEqualizerAndRandom.h"

TESTS(TradeTicksAnalyzerArgsEqualizerAndRandomTests)
AFACT(ZenUnitEqualizer_ThrowsIfAnyFieldsNotEqual)
AFACT(TestableRandomTradeTicksAnalyzerArgs_ReturnsAllNonDefaultFields)
EVIDENCE

TEST(ZenUnitEqualizer_ThrowsIfAnyFieldsNotEqual)
{
   ZENUNIT_EQUALIZER_TEST_SETUP(TradeTicksAnalyzerArgs);
   ZENUNIT_EQUALIZER_THROWS_WHEN_FIELD_NOT_EQUAL(TradeTicksAnalyzerArgs, programMode, ProgramMode::ProgramModeA);
   ZENUNIT_EQUALIZER_THROWS_WHEN_FIELD_NOT_EQUAL(TradeTicksAnalyzerArgs, requiredString, ZenUnit::Random<string>());
   ZENUNIT_EQUALIZER_THROWS_WHEN_FIELD_NOT_EQUAL(TradeTicksAnalyzerArgs, parallel, true);
}

TEST(TestableRandomTradeTicksAnalyzerArgs_ReturnsAllNonDefaultFields)
{
   ZenUnit::RandomGeneratorMock randomGeneratorMock;

   const string requiredString = randomGeneratorMock.StringMock.ReturnRandom();

   TradeTicksAnalyzerRandomGeneratorMock tradeTicksAnalyzerRandomGeneratorMock;
   const ProgramMode programMode = tradeTicksAnalyzerRandomGeneratorMock.RandomProgramModeMock.ReturnRandom();

   const bool parallel = randomGeneratorMock.BoolMock.ReturnRandom();
   //
   const TradeTicksAnalyzerArgs randomArgs = ZenUnit::TestableRandomTradeTicksAnalyzerArgs(&randomGeneratorMock, &tradeTicksAnalyzerRandomGeneratorMock);
   //
   METALMOCKTHEN(tradeTicksAnalyzerRandomGeneratorMock.RandomProgramModeMock.CalledOnce()).Then(
   METALMOCKTHEN(randomGeneratorMock.StringMock.Called())).Then(
   METALMOCKTHEN(randomGeneratorMock.BoolMock.CalledOnce()));
   TradeTicksAnalyzerArgs expectedRandomArgs;
   expectedRandomArgs.programMode = programMode;
   expectedRandomArgs.requiredString = requiredString;
   expectedRandomArgs.parallel = parallel;
   ARE_EQUAL(expectedRandomArgs, randomArgs);
}

RUN_TESTS(TradeTicksAnalyzerArgsEqualizerAndRandomTests)
