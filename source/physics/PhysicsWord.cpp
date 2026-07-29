#include "physics/PhysicsWorld.h"
#include "physics/CollisionDetector.h"

using namespace PB_Physics;

void PhysicsWorld::Update(float dt) {

	this->applyGravityToBodies();

	for (RigidBody* body : bodies) {
		body->Integrate(dt);
	}
	int steps = 8;

	while(steps > 0) {
		this->detectCollisions();
		this->solveCollisions();
		this->floorCollision();
		steps--;
	}
}

void PhysicsWorld::detectCollisions() {
	for (size_t i = 0; i < bodies.size(); ++i) {
		for (size_t j = i + 1; j < bodies.size(); ++j) {
			Collision collision;

			if (CollisionDetector::checkCollision(bodies[i], bodies[j], collision)) {
				collisions.push_back(collision);
			}
		}
	}
}

void PhysicsWorld::solveCollisions() {
	for (Collision& collision : collisions) {
		RigidBody* a = collision.bodyA;
		RigidBody* b = collision.bodyB;

		Vec2 correction = collision.normal * (collision.penetration / 2.0f);

		a->position = a->position - correction;
		b->position = b->position + correction;

		Vec2 relativeVelocity = b->velocity - a->velocity;

		float velocityAlongNormal = relativeVelocity.dot(collision.normal);

		if(velocityAlongNormal > 0)
			continue;

		float j = -1.0f * velocityAlongNormal;

		j /= (1 / a->mass) + (1 / b->mass);

		Vec2 impulse = collision.normal * j;

		a->velocity = a->velocity - (impulse / a->mass);
		b->velocity = b->velocity + (impulse / b->mass);
	}
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
		Vec2 force = gravity * body->mass;
		body->AddForce(force);
	}
}