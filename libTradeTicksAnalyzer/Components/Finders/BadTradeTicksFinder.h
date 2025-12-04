#pragma once
namespace Utils
{
   class FileAndFolderPathsGetter;
}

class BadTradeTicksFinder
{
   friend class BadTradeTicksFinderTests;
private:
   // Owned Constant Components
   unique_ptr<const Utils::FileAndFolderPathsGetter> _fileAndFolderPathsGetter;
   // Non-Owned Constant Components
   const Utils::Logger* _logger;
public:
   BadTradeTicksFinder();
   virtual ~BadTradeTicksFinder();
   virtual void Initialize(const Utils::Logger* logger);
   // Actions
   virtual void FindAllPossibleBadTradeTicks(
      const fs::path& realTimeTextTradeTicksInputFolderPath,
      const fs::path& possibleBadTradeTicksOutputFolderPath,
      bool parallel) const;
};
