#include <filesystem>
#include <string>

class FileSorter{
public:
    void sortFiles(const std::filesystem::path& directory);
private:
    std::string determineFileType(const std::filesystem::path& file) const;
    void moveFile(const std::filesystem::path& file, const std::filesystem::path& destination);
};