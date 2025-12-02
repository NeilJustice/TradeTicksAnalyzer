#pragma once

struct TradeTicksAnalyzerArgs
{
   static const string CommandLineUsage_calculate_trade_tick_latencies_args;
   static const string CommandLineUsage_calculate_trade_tick_latencies;

   static const string CommandLineUsage_find_possible_bad_trade_ticks_args;
   static const string CommandLineUsage_find_possible_bad_trade_ticks;

   static const string CommandLineUsage;

   ProgramMode programMode = ProgramMode::Unset;
   string requiredString;
   bool parallel = false;
};
