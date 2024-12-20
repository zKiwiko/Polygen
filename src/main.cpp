#include "polygen.hpp"
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
    std::string projectName;
    std::string projectPath = fs::current_path().string();
    Language projectLang = INVALID;

    bool projectNameSet = false;

    if(argc < 2) {
        Polygen::PrintHelp();
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];

        if (!projectNameSet && arg[0] != '-') {
            projectName = arg;
            projectNameSet = true;
            continue;
        }

        Flags flag = Polygen::ParseFlags(arg);
        
        switch (flag) {
            case NAME:
                if (i + 1 < argc) projectName = argv[++i];
                break;
            case LANGUAGE:
                if (i + 1 < argc) projectLang = Polygen::ParseLanguage(argv[++i]);
                break;
            case PATH:
                if (i + 1 < argc) projectPath = argv[++i];
                break;
            case VERSION:
                Polygen::PrintVersion();
                return 0;
            case HELP:
                Polygen::PrintHelp();
                return 0;
            default:
                std::cerr << "Unknown option: " << arg << '\n';
                return 1;
        }
    }

    if(projectName.empty()) {
        std::cerr << "Project name is required.\n";
        return 1;
    }

    if(projectLang == INVALID) {
        std::cerr << "Valid programming language is required.\n";
        return 1;
    }

    Polygen generator(projectName, projectPath, projectLang);
    if(!generator.CreateProject()) {
        std::cerr << "Failed to create project.\n";
        return 1;
    }

    std::cout << "Successfully created: " << projectName << " project at: " << projectPath << '\n';

    return 0;
}