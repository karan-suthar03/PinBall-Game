#include "core/Engine.h"
#include <game/Box.h>
#include <math/vec2.h>
#include <game/Ball.h>
#include <raylib.h>
#include <vector>
#include <core/Utils.h>
#include <physics/RigidBody.h>
#include <core/Entity.h>

static void loadLand(Engine* engine) {
	float width = 1000.0f;
	float height = 200.0f;

	Box* ground = new Box(width, height);

	ground->rigidBody.position = Vec2(400, 600 + (height / 2));
	ground->rigidBody.mass = width * height * 10000;
	ground->rigidBody.inertia = ground->rigidBody.mass * (width * width + height * height) / 12.0f;
	ground->rigidBody.staticBody = true;

	engine->entities.push_back(ground);
	engine->physicsWorld.addRigidBody(&ground->rigidBody);
}

Engine::Engine() {
	//addBallAtPosition(Vec2(400, 300));
	loadLand(this);
}

void Engine::update(float dt) {
	physicsWorld.Update(dt);
}

void Engine::addBoxAtPosition(const Vec2& position) {
	float width = 40.0f;
	float height = 20.0f;
	Box* newBox = new Box(width, height);
	newBox->rigidBody.position = position;
	newBox->rigidBody.mass = width * height;
	newBox->rigidBody.staticBody = false;

	newBox->rigidBody.inertia = newBox->rigidBody.mass * (width * width + height * height) / 12.0f;

	entities.push_back(newBox);
	physicsWorld.addRigidBody(&newBox->rigidBody);
}

void Engine::addBallAtPosition(const Vec2& position) {
	Ball* newBall = new Ball(10);
	newBall->rigidBody.position = position;
	newBall->rigidBody.mass = newBall->radius * newBall->radius * PI;
	newBall->rigidBody.velocity = Vec2(GetRandomValue(-0, 0), GetRandomValue(-100, 100));
	//newBall->rigidBody.velocity = Vec2(10,0);

	newBall->rigidBody.inertia = 0.5f * newBall->rigidBody.mass * newBall->radius * newBall->radius;

	entities.push_back(newBall);
	physicsWorld.addRigidBody(&newBall->rigidBody);
}

void Engine::render() {
	// i'll have to fix this mess next

	for (auto& entity : entities) {
		if (entity->drawable) {

			PB_Utils::Transform transfrom;
			transfrom.position = entity->body->position;
			transfrom.rotation = entity->body->rotation;

			entity->drawable->draw(&transfrom);
		}
	}
}