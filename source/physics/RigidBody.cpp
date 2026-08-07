#include "physics/RigidBody.h"
#include <cmath>


#define PI 3.14159265358979323846f


void PB_Physics::RigidBody::AddForce(Vec2& f) {
	acceleration = acceleration + f;
}

void PB_Physics::RigidBody::Integrate(float dt) {
    Vec2 acc = acceleration / mass;

	velocity = velocity + acc * dt;
	position = position + velocity * dt;

    acceleration = Vec2(0, 0);

    float angularAcc = angularAcceleration / inertia;

	angularVelocity = angularVelocity + angularAcc * dt;

	rotation = rotation + angularVelocity * dt;

    angularAcceleration = 0;

	angularVelocity *= 0.98f;
	velocity = velocity * 0.98f;

    rotation = fmod(rotation, 2 * PI);
}

void PB_Physics::RigidBody::addTorque(float torque) {
	angularAcceleration += torque;
}