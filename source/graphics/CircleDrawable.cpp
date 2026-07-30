#include "graphics/CircleDrawable.h"
#include <raylib.h>
#include <core/Utils.h>

using namespace PB_Graphics;

void CircleDrawable::draw(PB_Utils::Transform* transform) const {

	DrawCircleV(Vector2{transform->position.x,transform->position.y}, radius, RED); // vector version bcoz normal one dont support float

}
