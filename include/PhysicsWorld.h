#ifndef PHYSICS_WORLD_H
#define PHYSICS_WORLD_H

#include <vector>
#include <RigidBody.h>

using namespace PB_Physics;

namespace PB_Physics {
	class PhysicsWorld {
	public:
		void Update(float dt);

		void floorCollision();

		void applyGravityToBodies();

		void addRigidBody(RigidBody* body) {
			bodies.push_back(body);
		}

	private:
		std::vector<RigidBody*> bodies;
	};
}

#endif // PHYSICS_WORLD_H