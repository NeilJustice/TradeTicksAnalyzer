#pragma once

class SubProgram
{
   friend class SubProgramTests;
protected:
   // Constant Components
   unique_ptr<const Time::Console> p_console;
   // Mutable Fields
   TradeTicksAnalyzerArgs p_args;
public:
   SubProgram();
   virtual ~SubProgram();
   virtual void Initialize(const TradeTicksAnalyzerArgs& args);
   virtual void DerivedInitialize();
   // Actions
   virtual int Run() const;
};
