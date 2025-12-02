#include "pch.h"
#include "libTradeTicksAnalyzer/Components/SubPrograms/SubProgram.h"

SubProgram::SubProgram()
   // Constant Components
   : p_console(make_unique<Time::Console>("TradeTicksAnalyzer"))
{
}

SubProgram::~SubProgram()
{
}

void SubProgram::Initialize(const TradeTicksAnalyzerArgs& args)
{
   p_args = args;
}

void SubProgram::DerivedInitialize()
{
}

// Actions

int SubProgram::Run() const
{
   throw logic_error("Unexpected call to base class function SubProgram::Run()");
}
