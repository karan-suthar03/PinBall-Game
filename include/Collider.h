#ifndef COLLIDER_H
#define COLLIDER_H

#include "vec2.h"
#include "RigidBody.h"



using namespace PB_Math;
namespace PB_Physics {

	class RigidBody;

	struct Collision {

		RigidBody* bodyA;
		RigidBody* bodyB;

		Vec2 normal;
		float penetration;
	};
	class Collider {
	public:
		virtual ~Collider() = default;

		virtual float getBottom(const Vec2& position) const = 0;
	};
}

#endif // !COLLIDER_H
