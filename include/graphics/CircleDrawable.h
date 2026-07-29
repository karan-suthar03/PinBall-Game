#ifndef CIRCLE_RENDERER_H
#define CIRCLE_RENDERER_H

#include "Drawable.h"
#include <raylib.h>
namespace PB_Graphics {
	class CircleDrawable : public Drawable {
	public:
		CircleDrawable() : Drawable(DrawableType::BALL) {
		}
		void drawCircle(float x, float y, float radius);

	private:
	};
}

#endif // !CIRCLE_RENDERER_H
