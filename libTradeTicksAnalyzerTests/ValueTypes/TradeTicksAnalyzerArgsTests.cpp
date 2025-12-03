#include "pch.h"
#include "libTradeTicksAnalyzer/ValueTypes/TradeTicksAnalyzerArgs.h"

TESTS(TradeTicksAnalyzerArgsTests)
AFACT(DefaultConstructor_SetsFieldsToDefaultValues)
AFACT(CommandLineUsage_calculate_trade_tick_latencies_AreExpectedStrings)
AFACT(CommandLineUsage_find_possible_bad_trade_ticks_AreExpectedStrings)
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

TEST(CommandLineUsage_calculate_trade_tick_latencies_AreExpectedStrings)
{
   const string expectedArgs =
R"(TradeTicksAnalyzer calculate-trade-tick-latency-statistics
      --trading-logs-folder=<InputFolderPath>
      --date=<YYYY-MM-DDW>
      [--parallel])";
   ARE_EQUAL(expectedArgs, TradeTicksAnalyzerArgs::CommandLineUsage_calculate_trade_tick_latencies_args);

const string expectedUsage =
R"(Usage:
   )" + TradeTicksAnalyzerArgs::CommandLineUsage_calculate_trade_tick_latencies_args;
   ARE_EQUAL(expectedUsage, TradeTicksAnalyzerArgs::CommandLineUsage_calculate_trade_tick_latencies);
}

TEST(CommandLineUsage_find_possible_bad_trade_ticks_AreExpectedStrings)
{
const string expectedArgs =
R"(TradeTicksAnalyzer find-possible-bad-trade-ticks
      --trading-logs-folder=<InputFolderPath>
      --date=<YYYY-MM-DDW>
      [--parallel])";
   ARE_EQUAL(expectedArgs, TradeTicksAnalyzerArgs::CommandLineUsage_find_possible_bad_trade_ticks_args);

const string expectedUsage =
R"(Usage:
   )" + TradeTicksAnalyzerArgs::CommandLineUsage_find_possible_bad_trade_ticks_args;
   ARE_EQUAL(expectedUsage, TradeTicksAnalyzerArgs::CommandLineUsage_find_possible_bad_trade_ticks);
}

TEST(CommandLineUsage_IsExpectedString)
{
   ARE_EQUAL(R"(TradeTicksAnalyzer

Usage:
   TradeTicksAnalyzer calculate-trade-tick-latency-statistics
      --trading-logs-folder=<InputFolderPath>
      --date=<YYYY-MM-DDW>
      [--parallel]
   TradeTicksAnalyzer find-possible-bad-trade-ticks
      --trading-logs-folder=<InputFolderPath>
      --date=<YYYY-MM-DDW>
      [--parallel])", TradeTicksAnalyzerArgs::CommandLineUsage);
}

RUN_TESTS(TradeTicksAnalyzerArgsTests)
