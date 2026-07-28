#ifndef BALL_H
#define BALL_H

#include <RigidBody.h>
#include <raylib.h>
#include "CircleCollider.h"

namespace PB_Physics {
	class Ball {
	public:

		Ball(float radius) : radius(radius) {
			body.collider = &collider;
		}
		Ball(const Ball& other) = delete;


		Ball& operator=(const Ball& other) = delete;
		RigidBody body;

		float radius;
		CircleCollider collider{ radius };

		void draw() const;
	};
}

#endif // BALL_H	

