#ifndef BALL_H
#define BALL_H

#include <RegidBody.h>
#include <raylib.h>

namespace PB_Physics {
	class Ball {
	public:
		RegidBody body;

		float radius = 10.0f;

		void draw() const;
	};
}

#endif // !BALL_H	

