#ifndef COLLIDER_H
#define COLLIDER_H

#include "math/vec2.h"
#include "RigidBody.h"



using namespace PB_Math;
namespace PB_Physics {

	enum class ColliderType {
		CIRCLE,
		BOX,
		COUNT
	};

	enum class CollisionType {
		CIRCLE_CIRCLE,
		CIRCLE_BOX,
		BOX_BOX,
		COUNT
	};

	class RigidBody;

	struct Collision {

		RigidBody* bodyA;
		RigidBody* bodyB;

		Vec2 normal;
		float penetration;

		CollisionType type;

		Vec2 contactPoint;

		Collision()
			: bodyA(nullptr), bodyB(nullptr), normal(0.0f, 0.0f), penetration(0.0f), type(CollisionType::COUNT), contactPoint(0.0f, 0.0f)
		{}
	};


	class Collider {
	public:
		virtual ~Collider() = default;

		virtual float getBottom(const Vec2& position) const = 0;

		virtual ColliderType getType() const = 0;
	};
}

#endif // !COLLIDER_H
