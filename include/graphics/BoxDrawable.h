#ifndef BOX_DRAWABLE_H
#define BOX_DRAWABLE_H

#include "Drawable.h"

namespace PB_Graphics {
	class BoxDrawable : public Drawable {
	public:
		BoxDrawable() : Drawable(DrawableType::BOX) {
		}
		void drawBox(float x, float y, float width, float height, float rotation);
	private:
	};
}

#endif // BOX_DRAWABLE_H