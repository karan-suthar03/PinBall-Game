#ifndef RIGID_BODY_H
#define RIGID_BODY_H

#include "vec2.h"
#include "Collider.h"

using namespace PB_Math;


namespace PB_Physics {
	class RigidBody {
	public:

		Vec2 position = Vec2(0,0);
		Vec2 force = Vec2(0,0);
		Vec2 velocity = Vec2(0,0);

		float mass = 1.0f;

		void AddForce(Vec2& f);

		void Integrate(float dt);

		Collider* collider = nullptr;

	};
}




#endif // RIGID_BODY_H