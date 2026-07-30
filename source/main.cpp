#include <raylib.h>
#include "math/vec2.h"
using namespace PB_Math;
#include <string>
#include <core/Engine.h>

int main(){
    ::SetConfigFlags(FLAG_MSAA_4X_HINT);

    ::InitWindow(800, 600, "pinball game");

    Engine engine;

	::SetTargetFPS(60);

    //for (int i = 0; i < 1; i++)
    //{
    //    engine.addBoxAtPosition(Vec2(GetRandomValue(1, 600), GetRandomValue(1, 400)));
    //}

    while (!::WindowShouldClose()) {
        if (::IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            engine.addBallAtPosition(Vec2(::GetMouseX(), ::GetMouseY()));
        }
        if (::IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
            engine.addBoxAtPosition(Vec2(::GetMouseX(), ::GetMouseY()));
        }

        engine.update(1.0f/60.0f);

        ::BeginDrawing();
        ::ClearBackground(::RAYWHITE);

        engine.render();

        ::DrawText(std::to_string(::GetFPS()).c_str(), 10, 10, 20, ::DARKGRAY);
        ::DrawText(std::to_string(engine.num_of_entities()).c_str(), 10, 30, 20, ::DARKGRAY);
        ::EndDrawing();
    }

    return 0;
}