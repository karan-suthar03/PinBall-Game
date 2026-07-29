#include "graphics/BoxDrawable.h"
#include <raylib.h>

using namespace PB_Graphics;

void BoxDrawable::drawBox(float x, float y, float width, float height, float rotation) {
	DrawRectanglePro(
		Rectangle{ x , y, width, height },
		Vector2{ width, height},
		rotation * (180.0f / 3.14159265358979323846f),
		BLUE
	);
}