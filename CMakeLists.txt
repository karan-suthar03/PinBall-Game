cmake_minimum_required(VERSION 3.20)

project(Pinball VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(libs/raylib)

add_executable(Pinball 
"source/main.cpp"
"source/physics/RegidBody.cpp"    
"source/math/vec2.cpp"  "include/Ball.h" "source/Ball.cpp")

target_include_directories(Pinball PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(Pinball PRIVATE raylib)