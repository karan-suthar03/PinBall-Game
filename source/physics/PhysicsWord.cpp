#include "PhysicsWorld.h"

using namespace PB_Physics;

void PhysicsWorld::Update(float dt) {

	this->applyGravityToBodies();

	for (RigidBody* body : bodies) {
		body->Integrate(dt);
	}

	this->floorCollision();
}

void PhysicsWorld::floorCollision() {
	float floorY = 600.0f;
	for (RigidBody* body : bodies) {
		if (body->position.y + 10.0f > floorY) {
			body->position.y = floorY - 10.0f;
			body->velocity.y *= -1;
		}
	}
}

void PhysicsWorld::applyGravityToBodies() {
	Vec2 gravity(0, 300);
	for (RigidBody* body : bodies) {
		Vec2 force = gravity * body->mass;
		body->AddForce(force);
	}
}