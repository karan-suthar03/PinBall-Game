#include "Ball.h"

using namespace PB_Physics;

void Ball::draw() const {
	DrawCircle(static_cast<int>(body.position.x), static_cast<int>(body.position.y), radius, RED);
}