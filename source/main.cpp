#include <iostream>
#include <raylib.h>
#include <vector>
#include "Ball.h"
#include "PhysicsWorld.h"
#include <string>

void addBallAtPosition(std::vector<PB_Physics::Ball*>& balls, PB_Physics::PhysicsWorld& physicsWorld, const Vec2& position) {
    PB_Physics::Ball* newBall = new PB_Physics::Ball((GetRandomValue(1, 100) / 100.0f) * 20);
    newBall->body.position = position;
    newBall->body.mass = newBall->radius;
    newBall->body.velocity = Vec2(GetRandomValue(-0, 0), GetRandomValue(-100, 100));
    balls.push_back(newBall);
    physicsWorld.addRigidBody(&newBall->body);
}

int main(){

    InitWindow(800, 600, "pinball game");

	std::vector<PB_Physics::Ball*> balls;

	PhysicsWorld physicsWorld;

    int balls_count = 50;

    for(int i = 0; i < balls_count; ++i){
        addBallAtPosition(balls, physicsWorld, Vec2(GetRandomValue(0, 800), GetRandomValue(0, 600)));
	}

	SetTargetFPS(60);

    while (!WindowShouldClose()) {
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
			addBallAtPosition(balls, physicsWorld, Vec2(GetMouseX(), GetMouseY()));
		}

        physicsWorld.Update(1.0f / 60.0f);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (auto& ball : balls) {
            ball->draw();
        }


		DrawText(std::to_string(GetFPS()).c_str(), 10, 10, 20, DARKGRAY);

        EndDrawing();
    }

    return 0;
}