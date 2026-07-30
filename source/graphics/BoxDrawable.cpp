#include "graphics/BoxDrawable.h"
#include <raylib.h>
#include <core/Utils.h>

using namespace PB_Graphics;

void PB_Graphics::BoxDrawable::draw(PB_Utils::Transform* transoform) const {
	::DrawRectanglePro(
		Rectangle{ transoform->position.x, transoform->position.y, width, height },
		Vector2{ width/2, height/2 },
		transoform->rotation * (180.0f / 3.14159265358979323846f),
		BLUE
	);
}
