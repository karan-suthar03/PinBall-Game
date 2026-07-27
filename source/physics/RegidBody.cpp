#include "RegidBody.h"
void PB_Physics::RegidBody::AddForce(Vec2& f) {
	force = force + f;
}

void PB_Physics::RegidBody::Integrate(float dt) {
	Vec2 acc = force / mass;

	velocity = velocity + acc * dt;
	position = position + velocity * dt;

	force = Vec2(0, 0);
}