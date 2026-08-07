#include "graphics/CircleDrawable.h"
#include <raylib.h>
#include <core/Utils.h>
#include <cmath>

using namespace PB_Graphics;

void CircleDrawable::draw(PB_Utils::Transform* transform) const {

	DrawCircleV(Vector2{transform->position.x,transform->position.y}, radius, RED); // vector version bcoz normal one dont support float

	DrawLine(
		transform->position.x,
		transform->position.y,
		transform->position.x + radius * cos(transform->rotation),
		transform->position.y + radius * sin(transform->rotation),
		BLACK
	);

}
