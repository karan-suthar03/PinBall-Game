#ifndef BOX_COLLIDER_H
#define BOX_COLLIDER_H

#include "Collider.h"
#include "math/vec2.h"
#include <array>
#include <cfloat>
#include <algorithm>


namespace PB_Physics {
	class BoxCollider : public Collider {
	public:
		Vec2 halfExtents;

		std::array<Vec2, 4> cachedVertices;
		Vec2 cachedPosition;
		float cachedRotation = 0.0f;
		bool dirty = true;

		BoxCollider(float width = 1.0f, float height = 1.0f) : halfExtents(width * 0.5f, height * 0.5f) {}

		float getBottom(const Vec2& position) const override {
			return position.y + halfExtents.y;
		}

		ColliderType getType() const override {
			return ColliderType::BOX;
		}

		std::array<Vec2, 4> getWorldVertices(const Vec2& position, float rotation);

		std::array<Vec2, 2> getAABB(const Vec2& position, float rotation) {
			Vec2 min = Vec2(FLT_MAX, FLT_MAX);
			Vec2 max = Vec2(-FLT_MAX, -FLT_MAX);

			auto vertices = getWorldVertices(position, rotation);

			for (const auto& vertex : vertices) {
				min.x = std::min(min.x, vertex.x);
				min.y = std::min(min.y, vertex.y);
				max.x = std::max(max.x, vertex.x);
				max.y = std::max(max.y, vertex.y);
			}

			return { min, max };
		}
	};
}

#endif // BOX_COLLIDER_H