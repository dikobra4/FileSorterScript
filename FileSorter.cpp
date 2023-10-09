#include "FileSorter.h"
#include <iostream>
#include <set>
#include <algorithm>

void FileSorter::sortFiles(const std::filesystem::path& directory){
    for (const auto& entry : std::filesystem::directory_iterator(directory)) {
        if (std::filesystem::is_regular_file(entry)) {
            std::string fileType = determineFileType(entry);
            std::filesystem::path destination = directory / fileType;
            std::filesystem::create_directories(destination);
            moveFile(entry, destination / entry.path().filename());
        }
    }
}

std::string FileSorter::determineFileType(const std::filesystem::path& file) const {
    static const std::set<std::string> imageExtentions{".jpg", ".jpeg", ".png", ".gif", };
    static const std::set<std::string> docExtentions{".doc", ".docx", ".pdf", };
    static const std::set<std::string> videoExtentions{".mp4", ".mkv", ".avi", };
    static const std::set<std::string> audioExtentions{".mp3", ".wav", };
    static const std::set<std::string> textExtentions{".txt", ".md", };
    static const std::set<std::string> archivesExtentions{".exe", ".zip", ".tar", ".gz", ".7z", };

    std::string extension = file.extension().string();
    std::transform(extension.begin(), extension.end(), extension.begin(), ::tolower);


    if (imageExtentions.count(extension)) {      
        return "Images";  
    }
    if (docExtentions.count(extension)) {
        return "Documents";
    }
    if (videoExtentions.count(extension)) {
        return "Videos";
    }
    if (audioExtentions.count(extension)) {
        return "Audios";
    }
    if (textExtentions.count(extension)) {
        return "Text";
    }
    if (archivesExtentions.count(extension)) {
        return "Archives";
    }
    return "Others";
}


void FileSorter::moveFile(const std::filesystem::path& file, const std::filesystem::path& destination) {
    std::filesystem::rename(file, destination);
}