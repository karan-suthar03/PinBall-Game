#ifndef BALL_H
#define BALL_H

#include <RigidBody.h>
#include <raylib.h>

namespace PB_Physics {
	class Ball {
	public:
		Ball() = default;

		Ball(const Ball& other) = delete;


		Ball& operator=(const Ball& other) = delete;
		RigidBody body;

		float radius = 10.0f;

		void draw() const;
	};
}

#endif // !BALL_H	

