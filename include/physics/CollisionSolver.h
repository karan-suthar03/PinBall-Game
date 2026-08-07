#ifndef COLLISION_SOLVER_H
#define COLLISION_SOLVER_H
#include "RigidBody.h"
#include "Collider.h"
#include <vector>

namespace PB_Physics {
	class CollisionSolver {
	public:
		static void solveCollision(Collision& collision);
		static void solveCollisions(std::vector<Collision>& collisions);
	};
}


#endif // !COLLISION_SOLVER_H
