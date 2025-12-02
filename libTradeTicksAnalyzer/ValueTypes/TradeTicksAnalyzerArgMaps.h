#pragma once

struct TradeTicksAnalyzerArgMaps
{
   map<string, docopt::Value> docoptArgs_calculate_trade_tick_latencies;
   map<string, docopt::Value> docoptArgs_find_possible_bad_trade_ticks;
};
