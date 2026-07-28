#include <iostream>
#include <raylib.h>
#include <vector>
#include "Ball.h"
#include "PhysicsWorld.h"

void addBallAtPosition(std::vector<PB_Physics::Ball*>& balls, PB_Physics::PhysicsWorld& physicsWorld, const Vec2& position) {
	PB_Physics::Ball* newBall = new PB_Physics::Ball(GetRandomValue(1, 50));
    newBall->body.position = position;
    newBall->body.mass = newBall->radius;
    newBall->body.velocity = Vec2(GetRandomValue(-100, 100), GetRandomValue(-100, 100));
    balls.push_back(newBall);
    physicsWorld.addRigidBody(&newBall->body);
}

int main(){

    InitWindow(800, 600, "pinball game");

	std::vector<PB_Physics::Ball*> balls;

	PhysicsWorld physicsWorld;

    int count = 0;

    while (!WindowShouldClose()) {
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
			addBallAtPosition(balls, physicsWorld, Vec2(GetMouseX(), GetMouseY()));
		}

        if (count % 60 == 0) {
            addBallAtPosition(balls, physicsWorld, Vec2(400, 300));
        }


        count++;
        physicsWorld.Update(GetFrameTime());

        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (auto& ball : balls) {
            ball->draw();
        }

        EndDrawing();
    }

    return 0;
}