#pragma once

struct TradeTicksAnalyzerArgs
{
   static const string CommandLineUsage_calculate_trade_tick_latency_statistics_args;
   static const string CommandLineUsage_calculate_trade_tick_latency_statistics;

   static const string CommandLineUsage_find_possible_bad_trade_ticks_args;
   static const string CommandLineUsage_find_possible_bad_trade_ticks;

   static const string CommandLineUsage;

   ProgramMode programMode = ProgramMode::Unset;
   fs::path tradingLogsInputFolderPath;
   Time::Date date;
   unsigned runNumber = 0;
   fs::path outputFolderPath;
   bool parallel = false;
};
