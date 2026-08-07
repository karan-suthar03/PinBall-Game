#include "physics/BoxCollider.h"
#include "math/vec2.h"
#include <array>
#include <cmath>

using namespace PB_Physics;

std::array<Vec2, 4> BoxCollider::getWorldVertices(const Vec2& position, float rotation) {
	if (dirty || position != cachedPosition || rotation != cachedRotation) {
		float cosA = cos(rotation);
		float sinA = sin(rotation);

		cachedVertices[0] = Vec2(-halfExtents.x, -halfExtents.y).rotate(cosA, sinA) + position;
		cachedVertices[1] = Vec2(halfExtents.x, -halfExtents.y).rotate(cosA, sinA) + position;
		cachedVertices[2] = Vec2(halfExtents.x, halfExtents.y).rotate(cosA, sinA) + position;
		cachedVertices[3] = Vec2(-halfExtents.x, halfExtents.y).rotate(cosA, sinA) + position;

		cachedPosition = position;
		cachedRotation = rotation;
		dirty = false;
	}
	return cachedVertices;
}