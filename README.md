# Polygen

Polygen is a versatile project template generator that streamlines the process of creating new development projects across multiple programming languages. It automatically sets up standardized project structures, complete with necessary configuration files, basic directory layouts, and starter code templates.

## Supported Languages
* C
* C++
* Python
* Julia
* Go
* Dart
* HTML
* Javascript

## Usage
To properly use Polygen, you can either download the release, or [build from source](#Building-from-source) - then add it to your `PATH`.

To generate a project, in your Shell run:

```Shell
polygen {PROJECT_NAME} {FLAG} {FLAG_PARAMETER}
```

The supported flags for polygen are:

* `--name (-n)`    
  * Sets the project name
  * Optional: If omitted, the first argument becomes the project name
* `--version (-v)`  
    * Displays the current version of Polygen
    * Example: `polygen -v`
* `--language (-l) `
    * Specifies the target programming language
    * Required: Must match one of the supported languages
    * example: `polygen PythonProj -l python (or py)`
* `--path (-p)`     
    * Defines the output directory for the project
    * Optional: Defaults to the current directory if not specified
    * Supports both relative and absolute paths
    * Example: `polygen CppProject -l cpp -p ~/projects/cpp`
* `--help (-h)`    
    * prints out these commands
    * Example: `polygen -h`

*1: The `--name | -n` flag is optional. if you dont use it, the first argument will be the projects name.

## Project Structures
### C
```
Project-Name/
|- lib/
|- test/
|- build/
|- include/
    |- {project-name}.h
|- src/
    |- main.c
    |- {project-name}.c
|- .gitignore
|- CMakeLists.txt
```
### C++
```
Project-Name/
|- lib/
|- test/
|- build/
|- include/
    |- {project-name}.hpp
|- src/
    |- main.cpp
    |- {project-name}.cpp
|- .gitignore
|- CMakeLists.txt
```
### Python
```
Project-Name/
|- src/
    |- __init__.py
    |- main.py
    |- {project-name}.py
|- .gitignore
|- requirements.txt
|- setup.py
```
### Julia
```
Project-Name/
|- data/
|- docs/
|- tests/
    |- runtests.jl
|- src/
    |- {project-name}.jl
|- Project.toml
|- Manifest.toml
|- .gitignore
```
### Go
```
Project-Name/
|- cmd/
    |- app
        |- main.go
|- internal/
    |- helpers/
        |- helpers.go
|- test/
    |- test.go
|- pkg/
|- api/
|- docs/
|- go.mod
|- go.sum
|- .gitnignore
```
### Dart
```
Project-Name/
|- bin/
    |- main.dart
|- lib/
    |- {project-name}.dart
|- tests/
    |- {project-name}_test.dart
|- pubspec.yaml
|- .gitignore
```
### HTML
```
Project-Name/
|- scripts/
    |- script.js
|- themes/
    |- theme.css
|- index.html
```
### Javascript
```
Project-Name/
|- src
    |- index.js
|- package.json
|- .gitignore
```

## Examples
1. Create a Python Project:
```Shell
polygen PythonProj -l py
```
This creates a basic python project with the structure above
2. Creating a C++ project in a specific location
```shell
polygen CppProj -l cpp -p D:/Cpp-Projects
```
This create a C++ project with a CMake Configuration in the sepcified directory.

# Building from source
## Prerequisites
* CMake (Version 3.16 or higher)
* C++ Compiler (GCC, Clang, MSVS, etc)
* Git

## Build Instructions
1. Clone the Repository
```shell
git clone https://github.com/zKiwiko/Polygen.git
cd Polygen
```
## Visual Studio Code Build Process
1. Required Extensions:
    * CMake Tools
    * C/C++ Extension Pack
2. Build Steps:
    1. Open the Cloned repository in VSCode
    2. Press `Ctrl + Shift + P` and select `CMake: Select a kit`
    3. Choose your preferred C++ compiler
    4. Press `Ctrl + Shift + B` and select `CMake: Build`
    5. The executable will be in `build/bin` directory

## Terminal Build Process
Execute the following commands in the order theyre listed:
```shell
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

# Contributing

I welcome any contributions to Polygen, heres how you can help with development:

## Submitting Changes
1. Fork the Repository
2. Create a new branch for your feature or fix
3. Submit a pull request

## Reporting Issues
* Use the issue tracker
* Provide detailed reproduction steps
* include system info and Polygen version

## Development Guidelines
* Follow the existing code style
* Add tests for new features
* Update documentation as needed
* Ensure all tests pass before submitting

