#include "FileSorter.h"
#include <iostream>
#include <algorithm>


int requestMenuSelect(){ 
    std::cout << "Choose one of the following:" << std::endl;
    std::cout << "1. Show all files in target directory" << std::endl;
    std::cout << "2. Sort files by extension" << std::endl;
    std::cout << "3. Exit" << std::endl;

    int menuSelect;
    std::cout << "Your choice: ";
    std::cin >> menuSelect;
    return menuSelect;
}


int main() {
    std::string directory;    
    std::cout << "Enter target directory: ";
    std::cin >> directory;
    std::cout << "Base directory: " << directory << std::endl;

    if(!std::filesystem::exists(directory)) {
        std::cout << "Path does not exist: " << directory << std::endl;
        return 1;
    }

    FileSorter sorter;
    int menuSelect = 0;

    while (menuSelect != 3)
    {
        menuSelect = requestMenuSelect();
        if (menuSelect == 1){
            std::cout << "Path before calling showFiles: " << directory << std::endl;
            sorter.showFiles(directory);
        }
        else if (menuSelect == 2){
            sorter.sortFiles(directory);    
        }
    }

    return 0;
}