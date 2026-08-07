#ifndef COLLISION_DETECTOR_H
#define COLLISION_DETECTOR_H

#include "RigidBody.h"
#include "Collider.h"
#include <vector>

namespace PB_Physics {

	class CollisionDetector {
	public:
		static bool checkCollision(RigidBody* bodyA, RigidBody* bodyB, Collision& collision);
		static void detectCollisions( const std::vector<RigidBody*>& bodies, std::vector<Collision>& collisions);

	private:

		static bool checkCircleCircleCollision(RigidBody* bodyA, RigidBody* bodyB, Collision& collision);
		static bool checkBoxBoxCollision(RigidBody* a, RigidBody* b, Collision& collision);
		static bool checkCircleBoxCollision(RigidBody* circleBody, RigidBody* boxBody, Collision& collision);

	};
}

#endif // COLLISION_DETECTOR_H