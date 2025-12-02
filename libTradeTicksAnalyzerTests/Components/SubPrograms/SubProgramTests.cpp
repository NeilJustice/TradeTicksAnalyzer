#include "pch.h"
#include "libTradeTicksAnalyzer/Components/SubPrograms/SubProgram.h"

TESTS(SubProgramTests)
AFACT(DefaultConstructor_SetsFieldsToDefaultValues)
AFACT(Initialize_SetsArgsField)
AFACT(DerivedInitialize_DoesNothing)
// Actions
AFACT(Run_ThrowsLogicError)
EVIDENCE

SubProgram _subProgram;

TEST(DefaultConstructor_SetsFieldsToDefaultValues)
{
   const SubProgram subProgram;
   // Constant Components
   ARE_EQUAL("TradeTicksAnalyzer", subProgram.p_console->ProgramName());
   // Mutable Fields
   IS_DEFAULT_VALUE(subProgram.p_args);
}

TEST(Initialize_SetsArgsField)
{
   const TradeTicksAnalyzerArgs args = ZenUnit::Random<TradeTicksAnalyzerArgs>();
   //
   _subProgram.Initialize(args);
   //
   ARE_EQUAL(args, _subProgram.p_args);
}

TEST(DerivedInitialize_DoesNothing)
{
   _subProgram.DerivedInitialize();
}

// Actions

TEST(Run_ThrowsLogicError)
{
   THROWS_EXCEPTION(_subProgram.Run(),
      logic_error, "Unexpected call to base class function SubProgram::Run()");
}

RUN_TESTS(SubProgramTests)
