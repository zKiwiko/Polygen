constexpr const char* CPP_CMAKE = R"(
cmake_minimum_required(VERSION 3.10)
project({PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable({PROJECT_NAME}
    src/main.cpp
    src/{CLASS_NAME}.cpp
    )

target_include_directories({PROJECT_NAME} PRIVATE include)
)";

constexpr const char* CPP_MAIN = R"(
#include "{CLASS_NAME}.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    {CLASS_NAME} app;
    return 0;
}
)";

constexpr const char* CPP_CLASS_HEADER = R"(
#pragma once

class {CLASS_NAME} {
private:
    // Private members

public:
    {CLASS_NAME}();
    ~{CLASS_NAME}();
    
    // Public methods
};
)";

constexpr const char* CPP_CLASS_SRC = R"(
#include "{CLASS_NAME}.hpp"

{CLASS_NAME}::{CLASS_NAME}() {
    // Constructor implementation
}

{CLASS_NAME}::~{CLASS_NAME}() {
    // Destructor implementation
}
)";

constexpr const char* C_CMAKE = R"(
cmake_minimum_required(VERSION 3.10)
project({PROJECT_NAME})

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable({PROJECT_NAME}
    src/main.c
    src/{CLASS_NAME}.c
)

target_include_directories({PROJECT_NAME} PRIVATE include)
)";

constexpr const char* C_MAIN = R"(
#include "{CLASS_NAME}.h"
#include <stdio.h>

int main(int argc, char* argv[]) {
    {CLASS_NAME} app;
    return 0;
}
)";

constexpr const char* C_CLASS_HEADER = R"(
#pragma once

typedef struct {CLASS_NAME} {
    // Private members
} {CLASS_NAME};

{CLASS_NAME}* {CLASS_NAME}_new();
void {CLASS_NAME}_destroy({CLASS_NAME}* instance);

// Public methods
void {CLASS_NAME}_example_method({CLASS_NAME}* instance);
)";

constexpr const char* C_CLASS_SRC = R"(
#include "{CLASS_NAME}.h"
#include <stdio.h>

{CLASS_NAME}* {CLASS_NAME}_new() {
    {CLASS_NAME}* instance = malloc(sizeof({CLASS_NAME}));
    if (instance) {
        // Initialize members
    }
    return instance;
}

void {CLASS_NAME}_destroy({CLASS_NAME}* instance) {
    if (instance) {
        // Cleanup members
        free(instance);
    }
}

void {CLASS_NAME}_example_method({CLASS_NAME}* instance) {
    if (instance) {
        printf("Method for %s\n", #CLASS_NAME);
    }
}
)";

constexpr const char* PY_REQUIREMENTS = R"(
# List of dependencies for {PROJECT_NAME}
)";

constexpr const char* PY_SETUP = R"(
from setuptools import setup, find_packages

setup(
    name="{PROJECT_NAME}",
    version="0.1",
    packages=find_packages(),
    install_requires=[
        # Add dependencies here
    ],
)
)";

constexpr const char* PY_MAIN = R"(
from {CLASS_NAME} import {CLASS_NAME}

def main():
    app = {CLASS_NAME}()
    app.example_method()

if __name__ == "__main__":
    main()
)";

constexpr const char* PY_CLASS_SRC = R"(
class {CLASS_NAME}:
    def __init__(self):
        # Initialize members
        pass

    def example_method(self):
        print(f"Method for {CLASS_NAME}")
)";

constexpr const char* JS_PACKAGE = R"(
{
    "name": "{PROJECT_NAME}",
    "version": "1.0.0"
}
)";

constexpr const char* JS_MAIN = R"(
console.log("{PROJECT_NAME}");
)";

constexpr const char* JL_MAIN = R"(
function MAIN()

    println("Hello World")

end

MAIN()
)";

constexpr const char* GO_MAIN = R"(
package main

import (
    "fmt"
)

func main() {
    fmt.Println("Hello World")
}
)";

constexpr const char* GO_CLASS_SRC = R"(
package {CLASS_NAME}

func Greet(name string) string {
    return "Hello
}
)";

constexpr const char* GO_HELPER_SRC = R"(
package helpers

import "strings"

func ToUpper(input string) string {
    return strings.ToUpper(input)
}
)";

constexpr const char* GO_MOD = R"(
module {PROJECT_NAME}

go 1.20
)";

constexpr const char* DART_MAIN = R"(
import `package:{PROJECT_NAME}/{PROJECT_NAME}.dart`;

void main() {
    print(greet("World!"));
}
)";

constexpr const char* DART_CLASS_SRC = R"(
String greet(String name) {
    return 'Hello, $name!';
}
)";

constexpr const char* DART_DEPENDENCIES = R"(
name: {PROJECT_NAME}
description: A simple Dart project.
version: 0.1.0
environment:
  sdk: ">=2.19.0 <3.0.0"

dependencies:
  # Add any external dependencies here

dev_dependencies:
  test: ^1.21.0
)";

constexpr const char* HTML_MAIN = R"(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="A brief description of your webpage.">
    <meta name="author" content="Your Name">
    <title>{CLASS_NAME}</title>
    <link rel="stylesheet" href="themes/theme.css">
</head>
<body>
    <header>
        <nav>
            <ul>
                <li><a href="#home">Home</a></li>
                <li><a href="#about">About</a></li>
                <li><a href="#contact">Contact</a></li>
            </ul>
        </nav>
    </header>

    <main>
        <section id="home">
            <h1>Welcome to My Website</h1>
            <p>This is a basic HTML template.</p>
        </section>

        <section id="about">
            <h2>About</h2>
            <p>Information about the website or the author goes here.</p>
        </section>

        <section id="contact">
            <h2>Contact</h2>
            <form action="#" method="POST">
                <label for="name">Name:</label>
                <input type="text" id="name" name="name" required>
                
                <label for="email">Email:</label>
                <input type="email" id="email" name="email" required>
                
                <label for="message">Message:</label>
                <textarea id="message" name="message" required></textarea>
                
                <button type="submit">Send</button>
            </form>
        </section>
    </main>

    <footer>
        <p>&copy; 2024 Your Name. All rights reserved.</p>
    </footer>
    
    <script src="scripts/script.js"></script> <!-- Link to your JavaScript file -->
</body>
</html>
)";

constexpr const char* HTML_JS_SRC = R"(
console.log("Hello World");
)";

constexpr const char* HTML_CSS_SRC = R"(
* {
    font-family: "JetBrains Mono";
}

header {

}

body {

}

footer {

}
)";