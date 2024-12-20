#include "polygen.hpp"
#include "templates.hpp"

#include <iostream>
#include <fstream>
#include <system_error>
#include <filesystem>
#include <vector>
#include <map>

namespace fs = std::filesystem;

const std::map<Language, std::vector<std::string>> directories = {
        {C, {"src", "include", "lib", "test", "build"}},
        {CPP, {"src", "include", "lib", "test", "build"}},
        {PYTHON, {"src", "tests", "docs", "data"}},
        {JULIA, {"src", "tests", "docs", "data"}},
        {DART, {"bin", "lib", "tests"}},
        {JAVASCRIPT, {"src", "public", "components", "styles", "tests"}},
        {GO, {"cmd", "internal", "pkg", "api", "docs"}},
        {HTML, {"scripts", "themes"}}
    };
    
const std::map<Language, std::vector<Template>> templates = {
    {C, {
        {".gitignore", "build/\n*.o\n*.exe\n.vscode/\n"},
        {"CMakeLists.txt", C_CMAKE},
        {"src/main.c", C_MAIN},
        {"include/{CLASS_NAME}.h", C_CLASS_HEADER},
        {"src/{CLASS_NAME}.c", C_CLASS_SRC}
    }},
    {CPP, {
        {".gitignore", "build/\n*.o\n*.exe\n.vscode/\n"},
        {"CMakeLists.txt", CPP_CMAKE},
        {"src/main.cpp", CPP_MAIN},
        {"include/{CLASS_NAME}.hpp", CPP_CLASS_HEADER},
        {"src/{CLASS_NAME}.cpp", CPP_CLASS_SRC}
    }},
    {PYTHON, {
        {".gitignore", "__pycache__/\n*.pyc\n.env\n"},
        {"requirements.txt", PY_REQUIREMENTS},
        {"setup.py", PY_SETUP},
        {"src/__init__.py", ""},
        {"src/main.py", PY_MAIN},
        {"src/{CLASS_NAME}.py", PY_CLASS_SRC}
    }},
    {JULIA, {
            {".gitignore", "test/"},
            {"src/{CLASS_NAME}.jl", JL_MAIN},
            {"tests/runtests.jl", ""},
            {"Project.toml", ""},
            {"Manifest.toml", ""}
    }},
    {GO, {
        {"cmd/app/main.go", GO_MAIN},
        {"pkg/{CLASS_NAME}/{CLASS_NAME}.go", GO_CLASS_SRC},
        {"internal/helpers/helpers.go", GO_HELPER_SRC},
        {"test/test.go", ""},
        {"go.mod", GO_MOD},
        {"go.sum", ""},
        {".gitignore", "*.exe\n*.so\n*.out\nbin/\nobj/"}
    }},
    {DART, {
        {"bin/main.dart", DART_MAIN},
        {"lib/{CLASS_NAME}.dart", DART_CLASS_SRC},
        {"tests/{CLASS_NAME}_test.dart", ""},
        {"pubspec.yaml", DART_DEPENDENCIES},
        {".gitignore", ".dart_tool/\n.packages\npubspec.lock\n.idea/\n.vscode\n*.log"}
    }},
    {HTML, {
        {"index.html", HTML_MAIN},
        {"scripts/script.js", HTML_JS_SRC},
        {"themes/theme.css", HTML_CSS_SRC}
    }},
    {JAVASCRIPT, {
        {".gitignore", "node_modules/\n.env\ndist/\n"},
        {"package.json", JS_PACKAGE},
        {"src/index.js", JS_MAIN}
    }}
};

Flags Polygen::ParseFlags(std::string& flag) {
    if(flag == "--detail" || flag == "-d") return DETAILS;
    if(flag == "--version" || flag == "-v") return VERSION;
    if(flag == "--name" || flag == "-n") return NAME;
    if(flag == "--language" || flag == "-l") return LANGUAGE;
    if(flag == "--path" || flag == "-p") return PATH;
    if(flag == "--help" || flag == "-h") return HELP;
    return UNKNOWN;
}

Language Polygen::ParseLanguage(const std::string& lang) {
    if(lang == "c") { return C; }
    if(lang == "cpp" || lang == "c++") { return CPP; }
    if(lang == "python" || lang == "py") { return PYTHON; }
    if(lang == "julia" || lang == "jl") { return JULIA; }
    if(lang == "go") { return GO; }
    if(lang == "dart") { return DART; }
    if(lang == "html") { return HTML; }
    if(lang == "javascript" || lang == "js") { return JAVASCRIPT; }
    return INVALID;
}

bool Polygen::CreateProject() {
    if(!CreateDirectoryStructure()) {
        std::cerr << "Failed to create directory structure.\n";
        return false;
    }
    if(!CreateTemplateFiles()) {
        std::cerr << "Failed to create template files.\n";
        return false;
    }

    return true;
}

bool Polygen::CreateDirectoryStructure() {
    std::error_code ec;

    fs::path root = fs::path(projectPath) / projectName;
    if(!fs::create_directories(root, ec)) {
        if(ec) {
            std::cerr << "Error creating root directory: " << ec.message() << '\n';
            return false;
        }
    }

    auto it = directories.find(projectLang);
    if(it != directories.end()) {
        for(const auto& dir : it->second) {
            fs::path dirPath = root / dir;
            if(!fs::create_directories(dirPath, ec) && ec) {
                std::cerr << "Error creating directory " << dir << ": " << ec.message() << '\n';
                return false;
            }
        }
    }
    return true;
}

bool Polygen::CreateTemplateFiles() {
    fs::path rootPath = fs::path(projectPath) / projectName;
    
    auto it = templates.find(projectLang);
    if (it != templates.end()) {
        for (const auto& tmpl : it->second) {
            std::string processedPath = ProcessTemplate(tmpl.path);
            fs::path filePath = rootPath / processedPath;
            
            fs::create_directories(filePath.parent_path());
            
            std::ofstream file(filePath);
            if (!file) {
                std::cerr << "Failed to create file: " << processedPath << '\n';
                return false;
            }
            std::string processedContent = ProcessTemplate(tmpl.content);
            file << processedContent;
        }
    }
    
    return true;
}

void Polygen::PrintHelp() {
    std::cout << "Polygen - Project Generator\n"
              << "Usage: polygen [options]\n\n"
              << "Options:\n"
              << "  -n, --name <name>         Project name\n"
              << "  -l, --language <lang>      Programming language (cpp, python, javascript, rust, go)\n"
              << "  -p, --path <path>         Project path (optional)\n"
              << "  -v, --version             Show version\n"
              << "  -h, --help                Show this help message\n";
}

void Polygen::PrintVersion() {
    std::cout << "Polygen v1.0.0\n";
}