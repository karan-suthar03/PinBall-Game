#include "physics/PhysicsWorld.h"
#include "physics/CollisionDetector.h"
#include <physics/RigidBody.h>
#include <physics/Collider.h>
#include <math/vec2.h>
#include "physics/CollisionSolver.h"

using namespace PB_Physics;

void PhysicsWorld::Update(float dt) {

	this->applyGravityToBodies();


	int steps = 8;

	while(steps > 0) {
		this->detectCollisions();
		this->solveCollisions();
		//this->floorCollision();
		steps--;
	}

	for (RigidBody* body : bodies) {
		body->Integrate(dt);
	}
}

void PhysicsWorld::detectCollisions() {

	CollisionDetector::detectCollisions(bodies, collisions);

}

void PhysicsWorld::solveCollisions() {
	CollisionSolver::solveCollisions(collisions);
	collisions.clear();
}

void PhysicsWorld::floorCollision() {
	float floorY = 600.0f;
	for (RigidBody* body : bodies) {
		Collider* collider = body->collider;
		float bottom = collider->getBottom(body->position);
		if (bottom > floorY)
		{
			float penetration = bottom - floorY;

			body->position.y -= penetration;

			body->velocity.x *= 0.99f;
			body->velocity.y *= -0.99f;
		}
	}
}

void PhysicsWorld::applyGravityToBodies() {
	for (RigidBody* body : bodies) {
		if (body->staticBody) continue;
		Vec2 force = gravity * body->mass;
		body->AddForce(force);
	}
}