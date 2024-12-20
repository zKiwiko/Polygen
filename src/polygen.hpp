#pragma once

#include <algorithm>
#include <string>

enum Flags {
    DETAILS,
    VERSION,
    NAME,
    LANGUAGE,
    PATH,
    HELP,
    UNKNOWN
};

enum Language {
    C,
    CPP,
    PYTHON,
    JULIA,
    GO,
    DART,
    HTML,
    JAVASCRIPT,
    INVALID
};

struct Template {
    std::string path;
    std::string content;
};

class Polygen {
private:
    std::string projectName;
    std::string projectPath;
    Language projectLang;
    
    std::string GenerateClassName() const {
        std::string className = projectName;
        className.erase(std::remove(className.begin(), className.end(), '-'), className.end());
        if (!className.empty())
            className[0] = std::toupper(className[0]);
        return className;
    }

    std::string ProcessTemplate(const std::string& content) const {
        std::string processed = content;
        std::string className = GenerateClassName();
        
        size_t pos;
        while ((pos = processed.find("{PROJECT_NAME}")) != std::string::npos) {
            processed.replace(pos, 14, projectName);
        }
        while ((pos = processed.find("{CLASS_NAME}")) != std::string::npos) {
            processed.replace(pos, 12, className);
        }
        
        return processed;
    }

public:
    Polygen(const std::string& name, const std::string& path, Language lang)
        : projectName(name), projectPath(path), projectLang(lang) {}
    
    static Flags ParseFlags(std::string& flag);
    static Language ParseLanguage(const std::string& lang);
    bool CreateProject();
    bool CreateDirectoryStructure();
    bool CreateTemplateFiles();
    static void PrintHelp();
    static void PrintVersion();
};