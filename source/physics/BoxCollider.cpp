#include "physics/BoxCollider.h"
#include "math/vec2.h"
#include <array>
#include <cmath>

using namespace PB_Physics;

std::array<Vec2, 4> BoxCollider::getWorldVertices(const Vec2& position, float rotation) const {
	std::array<Vec2, 4> vertices;
	float cosA = cos(rotation);
	float sinA = sin(rotation);

	vertices[0] = Vec2(- halfExtents.x, - halfExtents.y).rotate(cosA, sinA) + position;
	vertices[1] = Vec2(+halfExtents.x, -halfExtents.y).rotate(cosA, sinA) + position;
	vertices[2] = Vec2(+ halfExtents.x, + halfExtents.y).rotate(cosA, sinA) + position;
	vertices[3] = Vec2(- halfExtents.x, + halfExtents.y).rotate(cosA, sinA) + position;
	return vertices;
}