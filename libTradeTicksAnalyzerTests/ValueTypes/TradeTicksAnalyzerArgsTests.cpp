#include "pch.h"
#include "libTradeTicksAnalyzer/ValueTypes/TradeTicksAnalyzerArgs.h"

TESTS(TradeTicksAnalyzerArgsTests)
AFACT(DefaultConstructor_SetsFieldsToDefaultValues)
AFACT(CommandLineUsage_program_mode_a_AreExpectedStrings)
AFACT(CommandLineUsage_program_mode_b_AreExpectedStrings)
AFACT(CommandLineUsage_IsExpectedString)
EVIDENCE

TEST(DefaultConstructor_SetsFieldsToDefaultValues)
{
   const TradeTicksAnalyzerArgs defaultArgs;
   TradeTicksAnalyzerArgs expectedDefaultArgs;
   expectedDefaultArgs.programMode = ProgramMode::Unset;
   expectedDefaultArgs.requiredString = "";
   expectedDefaultArgs.parallel = false;
   ARE_EQUAL(expectedDefaultArgs, defaultArgs);
}

TEST(CommandLineUsage_program_mode_a_AreExpectedStrings)
{
   const string expectedArgs =
R"(programname program-mode-a
      --required-string=<String>
      [--parallel])";
   ARE_EQUAL(expectedArgs, TradeTicksAnalyzerArgs::CommandLineUsage_program_mode_a_args);

const string expectedUsage =
R"(Usage:
   )" + TradeTicksAnalyzerArgs::CommandLineUsage_program_mode_a_args;
   ARE_EQUAL(expectedUsage, TradeTicksAnalyzerArgs::CommandLineUsage_program_mode_a);
}

TEST(CommandLineUsage_program_mode_b_AreExpectedStrings)
{
const string expectedArgs =
R"(programname program-mode-b
      --required-string=<String>
      [--parallel])";
   ARE_EQUAL(expectedArgs, TradeTicksAnalyzerArgs::CommandLineUsage_program_mode_b_args);

const string expectedUsage =
R"(Usage:
   )" + TradeTicksAnalyzerArgs::CommandLineUsage_program_mode_b_args;
   ARE_EQUAL(expectedUsage, TradeTicksAnalyzerArgs::CommandLineUsage_program_mode_b);
}

TEST(CommandLineUsage_IsExpectedString)
{
   ARE_EQUAL(R"(TradeTicksAnalyzer : Program description

Usage:
   programname program-mode-a
      --required-string=<String>
      [--parallel]
   programname program-mode-b
      --required-string=<String>
      [--parallel])", TradeTicksAnalyzerArgs::CommandLineUsage);
}

RUN_TESTS(TradeTicksAnalyzerArgsTests)
