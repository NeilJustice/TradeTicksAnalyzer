#pragma once
class SubProgram;

class SubProgramFactory
{
public:
   virtual shared_ptr<SubProgram> NewSubProgram(ProgramMode programMode) const;
   virtual ~SubProgramFactory() = default;
};
