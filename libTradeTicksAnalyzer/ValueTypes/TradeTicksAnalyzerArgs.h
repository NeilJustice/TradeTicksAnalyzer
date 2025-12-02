#pragma once

struct TradeTicksAnalyzerArgs
{
   static const string CommandLineUsage_program_mode_a_args;
   static const string CommandLineUsage_program_mode_a;

   static const string CommandLineUsage_program_mode_b_args;
   static const string CommandLineUsage_program_mode_b;

   static const string CommandLineUsage;

   ProgramMode programMode = ProgramMode::Unset;
   string requiredString;
   bool parallel = false;
};
