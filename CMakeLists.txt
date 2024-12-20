cmake_minimum_required(VERSION 3.10)
project(Polygen)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Release)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -s -march=native -flto")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -flto")

set(PROJECT_SOURCES
    src/main.cpp 
    src/Polygen.cpp
)

add_executable(Polygen
    ${PROJECT_SOURCES}
)

target_include_directories(Polygen PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

set_target_properties(Polygen
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
