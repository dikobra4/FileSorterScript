#include "FileSorter.h"
#include <iostream>

int main() {
    std::string directory;    
    std::cout << "Enter target directory: ";
    std::cin >> directory;

    FileSorter sorter;
    sorter.sortFiles(directory);
    return 0;
}