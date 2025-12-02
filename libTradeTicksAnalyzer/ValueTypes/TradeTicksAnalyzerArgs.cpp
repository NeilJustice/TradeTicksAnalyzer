#include "pch.h"
#include "libTradeTicksAnalyzer/ValueTypes/TradeTicksAnalyzerArgs.h"

const string TradeTicksAnalyzerArgs::CommandLineUsage_program_mode_a_args =
R"(programname program-mode-a
      --required-string=<String>
      [--parallel])";
const string TradeTicksAnalyzerArgs::CommandLineUsage_program_mode_a =
R"(Usage:
   )" + TradeTicksAnalyzerArgs::CommandLineUsage_program_mode_a_args;

const string TradeTicksAnalyzerArgs::CommandLineUsage_program_mode_b_args =
R"(programname program-mode-b
      --required-string=<String>
      [--parallel])";
const string TradeTicksAnalyzerArgs::CommandLineUsage_program_mode_b =
R"(Usage:
   )" + TradeTicksAnalyzerArgs::CommandLineUsage_program_mode_b_args;

const string TradeTicksAnalyzerArgs::CommandLineUsage =
R"(TradeTicksAnalyzer

Usage:
   )" + TradeTicksAnalyzerArgs::CommandLineUsage_program_mode_a_args + R"(
   )" + TradeTicksAnalyzerArgs::CommandLineUsage_program_mode_b_args;
