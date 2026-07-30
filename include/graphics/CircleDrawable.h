#ifndef CIRCLE_RENDERER_H
#define CIRCLE_RENDERER_H

#include "Drawable.h"
#include <core/Utils.h>
namespace PB_Graphics {
	class CircleDrawable : public Drawable {
	private:
		float radius;
	public:
		CircleDrawable(float radius) : Drawable(DrawableType::BALL), radius(radius) {
		}

		void draw(PB_Utils::Transform* transoform) const;

	};
}

#endif // !CIRCLE_RENDERER_H
