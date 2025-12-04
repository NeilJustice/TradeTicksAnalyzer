#pragma once
namespace Functional
{
   template<typename ClassType, typename ElementType>
   class OneArgMemberFunctionForEacher;
}
namespace Utils
{
   class FileAndFolderPathsGetter;
}
class TradeTicksAnalyzerMessageWriter;

class BadTradeTicksFinder
{
   friend class BadTradeTicksFinderTests;
private:
   // Function Callers
   using _forEacher_fsPathType = Functional::OneArgMemberFunctionForEacher<BadTradeTicksFinder, fs::path>;
   unique_ptr<const _forEacher_fsPathType> _forEacher_fsPath;
   // Constant Components
   unique_ptr<const Utils::FileAndFolderPathsGetter> _fileAndFolderPathsGetter;
   // Mutable Components
   unique_ptr<TradeTicksAnalyzerMessageWriter> _tradeTicksAnalyzerMessageWriter;
public:
   BadTradeTicksFinder();
   virtual ~BadTradeTicksFinder();
   virtual void Initialize(const Utils::Logger* logger);
   // Actions
   virtual void FindAllPossibleBadTradeTicks(
      const fs::path& realTimeTextTradeTicksInputFolderPath,
      const fs::path& possibleBadTradeTicksOutputFolderPath,
      bool parallel) const;
private:
   void TryCatchCall_FindPossibleBadTradeTicks(
      const fs::path& realTimeTextTradeTicksInputFilePath,
      size_t realTimeTextTradeTicksInputFilePathIndex) const;

   void FindPossibleBadTradeTicks(
      const fs::path& realTimeTextTradeTicksInputFilePath) const;

   void ExceptionHandler_FindPossibleBadTradeTicks(
      string_view exceptionClassNameAndMessage,
      const fs::path& realTimeTextTradeTicksInputFilePath) const;
};
