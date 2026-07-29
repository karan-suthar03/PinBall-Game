#include <iostream>
#include <raylib.h>
#include <vector>
#include "math/vec2.h"
using namespace PB_Math;
#include "game/Ball.h"
#include "physics/PhysicsWorld.h"
#include <string>
#include <core/Entity.h>
#include <game/Box.h>

using namespace PB_Physics;

void addBallAtPosition(std::vector<Entity*>& entities, PhysicsWorld& physicsWorld, const Vec2& position) {
    Ball* newBall = new Ball((GetRandomValue(1, 100) / 100.0f) * 20);
    newBall->rigidBody.position = position;
    newBall->rigidBody.mass = newBall->radius;
    newBall->rigidBody.velocity = Vec2(GetRandomValue(-0, 0), GetRandomValue(-100, 100));
    entities.push_back(newBall);
    physicsWorld.addRigidBody(&newBall->rigidBody);
}

void addBoxAtPositon(std::vector<Entity*>& entities, PhysicsWorld& physicsWorld, const Vec2& position) {

	float width = 20.0f;
	float height = 20.0f;
	Box* newBox = new Box(width, height);
	newBox->rigidBody.position = position;
	newBox->rigidBody.mass = width * height;
	entities.push_back(newBox);
	physicsWorld.addRigidBody(&newBox->rigidBody);
}

int main(){
    SetConfigFlags(FLAG_MSAA_4X_HINT);

    InitWindow(800, 600, "pinball game");

	std::vector<Entity*> entities;

	PhysicsWorld physicsWorld;

    int balls_count = 500;

 //   for(int i = 0; i < balls_count; ++i){
 //       addBallAtPosition(balls, physicsWorld, Vec2(GetRandomValue(0, 800), GetRandomValue(0, 600)));
	//}

	//addBoxAtPositon(entities, physicsWorld, Vec2(400, 300));

	SetTargetFPS(60);

    while (!WindowShouldClose()) {
        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
			addBoxAtPositon(entities, physicsWorld, Vec2(GetMouseX(), GetMouseY()));
		}

        physicsWorld.Update(1.0f / 60.0f);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (auto& entity : entities) {
            if(entity->drawable) {
                if (entity->drawable->getType() == PB_Graphics::DrawableType::BALL) {
                    RigidBody* body = entity->body;
					((static_cast<Ball*>(entity))->circleDrawable).drawCircle(body->position.x, body->position.y, static_cast<Ball*>(entity)->radius);
                } else if (entity->drawable->getType() == PB_Graphics::DrawableType::BOX) {
					RigidBody* body = entity->body;
                    ((static_cast<Box*>(entity))->boxDrawable).drawBox(body->position.x + static_cast<Box*>(entity)->width, body->position.y + static_cast<Box*>(entity)->height, static_cast<Box*>(entity)->width, static_cast<Box*>(entity)->height, body->rotation);
                }
            }
        }


		DrawText(std::to_string(GetFPS()).c_str(), 10, 10, 20, DARKGRAY);

        EndDrawing();
    }

    return 0;
}