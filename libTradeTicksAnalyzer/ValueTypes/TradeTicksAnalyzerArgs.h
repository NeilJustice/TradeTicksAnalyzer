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
   Time::DateWithDayOfWeek dateWithDayOfWeek;
   unsigned runNumber = 0;
   fs::path tradingLogsOutputFolderPath;
   bool parallel = false;
   // Calculated Fields
   fs::path tradingLogsInputFolderPath_dateDashRunNumber_Polygon_FilteredRealTimeTextTradeTicks;
};
