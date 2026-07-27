cmake_minimum_required(VERSION 3.20)

project(Pinball VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SRC_FILES
    "${PROJECT_SOURCE_DIR}/source/*.cpp"
)

add_executable(Pinball ${SRC_FILES})


target_include_directories(Pinball PRIVATE include)