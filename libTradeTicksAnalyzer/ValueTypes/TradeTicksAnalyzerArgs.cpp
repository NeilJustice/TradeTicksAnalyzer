#include "pch.h"
#include "libTradeTicksAnalyzer/ValueTypes/TradeTicksAnalyzerArgs.h"

const string TradeTicksAnalyzerArgs::CommandLineUsage_calculate_trade_tick_latency_statistics_args =
R"(TradeTicksAnalyzer calculate-trade-tick-latency-statistics
      --trading-logs-folder=<InputFolderPath>
      --date=<YYYY-MM-DDW>
      --run-number=<Unsigned>
      [--parallel])";
const string TradeTicksAnalyzerArgs::CommandLineUsage_calculate_trade_tick_latency_statistics =
R"(Usage:
   )" + TradeTicksAnalyzerArgs::CommandLineUsage_calculate_trade_tick_latency_statistics_args;

const string TradeTicksAnalyzerArgs::CommandLineUsage_find_possible_bad_trade_ticks_args =
R"(TradeTicksAnalyzer find-possible-bad-trade-ticks
      --trading-logs-folder=<InputFolderPath>
      --date=<YYYY-MM-DDW>
      --run-number=<Unsigned>
      [--parallel])";
const string TradeTicksAnalyzerArgs::CommandLineUsage_find_possible_bad_trade_ticks =
R"(Usage:
   )" + TradeTicksAnalyzerArgs::CommandLineUsage_find_possible_bad_trade_ticks_args;

const string TradeTicksAnalyzerArgs::CommandLineUsage =
R"(TradeTicksAnalyzer

Usage:
   )" + TradeTicksAnalyzerArgs::CommandLineUsage_calculate_trade_tick_latency_statistics_args + R"(
   )" + TradeTicksAnalyzerArgs::CommandLineUsage_find_possible_bad_trade_ticks_args;
