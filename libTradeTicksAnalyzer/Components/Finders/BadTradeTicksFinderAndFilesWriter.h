#pragma once
namespace Functional
{
   template<typename ClassType, typename ElementType>
   class OneArgMemberFunctionForEacher;

   template<typename ClassType, typename Arg1Type>
   class VoidOneArgTryCatchCaller;
}
namespace Utils
{
   class FileAndFolderPathsGetter;
}
namespace TickData
{
   class TextTradeTicksFileReader;
}
class BadTradeTicksDeterminer;
class TradeTicksAnalyzerMessageWriter;

class BadTradeTicksFinderAndFilesWriter
{
   friend class BadTradeTicksFinderAndFilesWriterTests;
private:
   // Function Callers
   using _forEacher_fsPathType = Functional::OneArgMemberFunctionForEacher<BadTradeTicksFinderAndFilesWriter, fs::path>;
   unique_ptr<const _forEacher_fsPathType> _forEacher_fsPath;

   using _tryCatchCaller_fsPathType = Functional::VoidOneArgTryCatchCaller<BadTradeTicksFinderAndFilesWriter, const fs::path&>;
   unique_ptr<const _tryCatchCaller_fsPathType> _tryCatchCaller_fsPath;
   // Constant Components
   unique_ptr<const BadTradeTicksDeterminer> _badTradeTicksDeterminer;
   unique_ptr<const Utils::FileAndFolderPathsGetter> _fileAndFolderPathsGetter;
   unique_ptr<const TickData::TextTradeTicksFileReader> _textTradeTicksFileReader;
   // Mutable Components
   unique_ptr<TradeTicksAnalyzerMessageWriter> _tradeTicksAnalyzerMessageWriter;
   // Mutable Fields
   TradeTicksAnalyzerArgs _args;
public:
   BadTradeTicksFinderAndFilesWriter();
   virtual ~BadTradeTicksFinderAndFilesWriter();
   virtual void Initialize(const TradeTicksAnalyzerArgs& args, const Utils::Logger* logger);
   // Actions
   virtual void FindAllPossibleBadTradeTicks(
      const fs::path& realTimeTextTradeTicksInputFolderPath, bool parallel) const;
private:
   void TryCatchCall_FindPossibleBadTradeTicks(
      const fs::path& realTimeTextTradeTicksInputFilePath, size_t realTimeTextTradeTicksInputFilePathIndex) const;

   void FindPossibleBadTradeTicks(
      const fs::path& realTimeTextTradeTicksInputFilePath) const;

   void ExceptionHandler_FindPossibleBadTradeTicks(
      string_view exceptionClassNameAndMessage, const fs::path& realTimeTextTradeTicksInputFilePath) const;
};
