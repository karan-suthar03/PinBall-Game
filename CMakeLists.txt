cmake_minimum_required(VERSION 3.20)

project(Pinball VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(libs/raylib)

add_executable(Pinball 
"source/main.cpp"
"source/physics/RigidBody.cpp"    
 "source/Ball.cpp" "source/physics/PhysicsWord.cpp" "source/physics/CollisionDetector.cpp" "include/Physics/BoxCollider.h" "source/physics/BoxCollider.cpp" "include/game/Box.h" "include/graphics/Drawable.h" "include/graphics/CircleDrawable.h" "include/core/Entity.h" "include/graphics/BoxDrawable.h" "source/graphics/BoxDrawable.cpp" "source/graphics/CircleDrawable.cpp" "include/graphics/Renderer.h" "include/core/Engine.h" "source/core/Engine.cpp" "include/physics/CollisionSolver.h" "source/physics/CollisionSolver.cpp" "source/math/Vec2.cpp")

target_include_directories(Pinball PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(Pinball PRIVATE raylib)