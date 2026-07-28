#ifndef CIRCLE_COLLIDER_H
#define CIRCLE_COLLIDER_H

#include "Collider.h"
#include <iostream>

namespace PB_Physics {
	class CircleCollider : public Collider {
	public:
		CircleCollider(float radius = 1.0f) : radius(radius) {
		}
		float radius;

		float getBottom(const Vec2& position) const {
			return position.y + radius;
		}
	};
}

#endif // !CIRCLE_COLLIDER_H
