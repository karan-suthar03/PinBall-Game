#include "core/Engine.h"
#include <game/Box.h>
#include <math/vec2.h>
#include <game/Ball.h>
#include <raylib.h>
#include <vector>

void Engine::update(float dt) {
	physicsWorld.Update(dt);
}

void Engine::addBoxAtPosition(const Vec2& position) {

	float width = 20.0f;
	float height = 20.0f;
	Box* newBox = new Box(width, height);
	newBox->rigidBody.position = position;
	newBox->rigidBody.mass = width * height;
	entities.push_back(newBox);
	physicsWorld.addRigidBody(&newBox->rigidBody);
}

void Engine::addBallAtPosition(const Vec2& position) {
	Ball* newBall = new Ball(10);
	newBall->rigidBody.position = position;
	newBall->rigidBody.mass = newBall->radius * newBall->radius * PI;
	newBall->rigidBody.velocity = Vec2(GetRandomValue(-0, 0), GetRandomValue(-100, 100));
	entities.push_back(newBall);
	physicsWorld.addRigidBody(&newBall->rigidBody);
}

void Engine::render() {
	// i'll have to fix this mess next

	for (auto& entity : entities) {
		if (entity->drawable) {
			if (entity->drawable->getType() == PB_Graphics::DrawableType::BALL) {
				PB_Physics::RigidBody* body = entity->body;
				((static_cast<Ball*>(entity))->circleDrawable).drawCircle(body->position.x, body->position.y, static_cast<Ball*>(entity)->radius);
			}
			else if (entity->drawable->getType() == PB_Graphics::DrawableType::BOX) {
				PB_Physics::RigidBody* body = entity->body;
				((static_cast<Box*>(entity))->boxDrawable).drawBox(body->position.x + static_cast<Box*>(entity)->width, body->position.y + static_cast<Box*>(entity)->height, static_cast<Box*>(entity)->width, static_cast<Box*>(entity)->height, body->rotation);
			}
		}
	}
}