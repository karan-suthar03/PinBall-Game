#include "graphics/CircleDrawable.h"
#include <raylib.h>

using namespace PB_Graphics;

void CircleDrawable::drawCircle(float x, float y, float radius) {
	DrawCircleV(Vector2{ x, y }, radius, RED); // vector version bcoz normal one dont support float
}