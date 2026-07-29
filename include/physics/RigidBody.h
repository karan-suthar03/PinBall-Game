#ifndef RIGID_BODY_H
#define RIGID_BODY_H

#include "math/vec2.h"

using namespace PB_Math;


namespace PB_Physics {

	class Collider;
	class RigidBody {
	public:

		Vec2 position = Vec2(0,0);
		Vec2 acceleration = Vec2(0,0);
		Vec2 velocity = Vec2(0,0);


		float rotation = 0;
		float angularVelocity = 0;
		float angularAcceleration = 0;


		float mass = 1.0f;

		void AddForce(Vec2& f);

		void addTorque(float torque);

		void Integrate(float dt);

		Collider* collider = nullptr;

	};
}




#endif // RIGID_BODY_H