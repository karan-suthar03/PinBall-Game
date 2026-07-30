#ifndef BOX_DRAWABLE_H
#define BOX_DRAWABLE_H

#include "Drawable.h"
#include <core/Utils.h>

namespace PB_Graphics {
	class BoxDrawable : public Drawable {
	private:
		float width;
		float height;
	public:
		BoxDrawable(float width, float height) : Drawable(DrawableType::BOX), width(width), height(height) {
		}
		void draw(PB_Utils::Transform* transoform) const;

	};
}

#endif // BOX_DRAWABLE_H