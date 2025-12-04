#include "pch.h"
#include "libTradeTicksAnalyzer/Components/Finders/BadTradeTicksFinder.h"

BadTradeTicksFinder::BadTradeTicksFinder()
   // Non-Owned Constant Components
   : _logger(nullptr)
{
}

BadTradeTicksFinder::~BadTradeTicksFinder()
{
}

// Actions

void BadTradeTicksFinder::Initialize(const Utils::Logger* logger)
{
   _logger = logger;
}
