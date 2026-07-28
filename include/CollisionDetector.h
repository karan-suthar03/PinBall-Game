#ifndef COLLISION_DETECTOR_H
#define COLLISION_DETECTOR_H

#include "RigidBody.h"
#include "Collider.h"

namespace PB_Physics {

	class CollisionDetector {
	public:
		static bool checkCollision(RigidBody* bodyA, RigidBody* bodyB, Collision& collision);

	private:
		static bool checkCircleCircleCollision(RigidBody* bodyA, RigidBody* bodyB, Collision& collision);
	};
}

#endif // COLLISION_DETECTOR_H