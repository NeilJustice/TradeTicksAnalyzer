#include "pch.h"
#include "libTradeTicksAnalyzer/Enums/ProgramMode.h"

TESTS(ProgramModeTests)
AFACT(ENUM_AS_STRING_ReturnsEnumAsString)
AFACT(OStreamInsertionOperator_WritesEnumAsStringToOStream_ReturnsOStream)
EVIDENCE

static void AssertEnumAsString(ProgramMode programMode, string_view expectedProgramModeString)
{
   const string_view programModeString = ENUM_AS_STRING(ProgramMode, programMode);
   ARE_EQUAL(expectedProgramModeString, programModeString);
}

TEST(ENUM_AS_STRING_ReturnsEnumAsString)
{
   AssertEnumAsString(ProgramMode::Unset, "Unset");
   AssertEnumAsString(ProgramMode::FindPossibleBadBinaryTradeTicks, "FindPossibleBadBinaryTradeTicks");
   AssertEnumAsString(ProgramMode::FindPossibleBadTextTradeTicks, "FindPossibleBadTextTradeTicks");
   AssertEnumAsString(ProgramMode::Invalid, "Invalid");
   AssertEnumAsString(ProgramMode::MaxValue, "MaxValue");
}

TEST(OStreamInsertionOperator_WritesEnumAsStringToOStream_ReturnsOStream)
{
   ostringstream oss;
   //
   oss << ProgramMode::Unset << ' ' << ProgramMode::MaxValue;
   //
   const string str = oss.str();
   ARE_EQUAL("Unset MaxValue", str);
}

RUN_TESTS(ProgramModeTests)
