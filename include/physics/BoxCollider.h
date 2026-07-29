#ifndef BOX_COLLIDER_H
#define BOX_COLLIDER_H

#include "Collider.h"
#include "math/vec2.h"
#include <array>


namespace PB_Physics {
	class BoxCollider : public Collider {
	public:
		Vec2 halfExtents;

		BoxCollider(float width = 1.0f, float height = 1.0f) : halfExtents(width * 0.5f, height * 0.5f) {}

		float getBottom(const Vec2& position) const override {
			return position.y + halfExtents.y;
		}

		ColliderType getType() const override {
			return ColliderType::BOX;
		}

		std::array<Vec2, 4> getWorldVertices(const Vec2& position, float rotation) const;
	};
}

#endif // BOX_COLLIDER_H