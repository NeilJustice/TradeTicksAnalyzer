#pragma once

class BadTradeTicksFinder
{
   friend class BadTradeTicksFinderTests;
private:
   // Non-Owned Constant Components
   const Utils::Logger* _logger;
public:
   BadTradeTicksFinder();
   virtual ~BadTradeTicksFinder();
   virtual void Initialize(const Utils::Logger* logger);
   // Actions

};
