#ifndef BALL_H
#define BALL_H

#include <physics/RigidBody.h>
#include <physics/CircleCollider.h>
#include "core/Entity.h"
#include <graphics/CircleDrawable.h>

class Ball : public Entity {
public:

	Ball(float radius) : radius(radius), circleCollider(radius), circleDrawable(radius) {
		rigidBody.collider = &circleCollider;

		collider = &circleCollider;
		body = &rigidBody;
		drawable = &circleDrawable;
	}
	Ball(const Ball& other) = delete;
	Ball& operator=(const Ball& other) = delete;

	PB_Physics::RigidBody rigidBody;

	float radius;
	PB_Physics::CircleCollider circleCollider;
	PB_Graphics::CircleDrawable circleDrawable;
};

#endif // BALL_H	

