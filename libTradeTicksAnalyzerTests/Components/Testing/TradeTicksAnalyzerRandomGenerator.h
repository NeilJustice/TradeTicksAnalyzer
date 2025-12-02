#pragma once

class TradeTicksAnalyzerRandomGenerator
{
public:
   static const TradeTicksAnalyzerRandomGenerator* Instance();
   virtual ~TradeTicksAnalyzerRandomGenerator() = default;
   virtual ProgramMode RandomProgramMode() const;
};
