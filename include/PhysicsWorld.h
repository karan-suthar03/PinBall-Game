#ifndef PHYSICS_WORLD_H
#define PHYSICS_WORLD_H

#include <vector>
#include <RigidBody.h>

using namespace PB_Physics;

namespace PB_Physics {
	class PhysicsWorld {
	public:
		void Update(float dt);

		void detectCollisions();

		void solveCollisions();

		void floorCollision();

		void applyGravityToBodies();

		void addRigidBody(RigidBody* body) {
			bodies.push_back(body);
		}

	private:
		std::vector<RigidBody*> bodies;
		std::vector<Collision> collisions;

		const Vec2 gravity = Vec2(0, 980);
	};
}

#endif // PHYSICS_WORLD_H