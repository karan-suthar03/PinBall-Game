#include "physics/CollisionDetector.h"
#include "physics/CircleCollider.h"

using namespace PB_Physics;

bool CollisionDetector::checkCollision(RigidBody* a, RigidBody* b, Collision& collision) {

	if(a->collider->getType() == ColliderType::CIRCLE && b->collider->getType() == ColliderType::CIRCLE) {
		return checkCircleCircleCollision(a, b, collision);
	}

	return false;
}


bool CollisionDetector::checkCircleCircleCollision(RigidBody* a, RigidBody* b, Collision& collision) {
	CircleCollider* ca =
		static_cast<CircleCollider*>(a->collider);

	CircleCollider* cb =
		static_cast<CircleCollider*>(b->collider);

	Vec2 delta = b->position - a->position;
	
	float distanceSqared = delta.getDistanceSquared();

	if (distanceSqared < (ca->radius + cb->radius) * (ca->radius + cb->radius)) {

		collision.bodyA = a;
		collision.bodyB = b;

		collision.normal = delta.normalize();

		float distance = delta.length();
		collision.penetration = (ca->radius + cb->radius) - distance;

		return true;
	}

	return false;
}