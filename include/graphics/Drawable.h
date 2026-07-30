#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <core/Utils.h>

namespace PB_Graphics {


	enum class DrawableType {
		NONE,
		BALL,
		BOX
	};

	class Drawable {
	public:

		Drawable(DrawableType type) : type(type) {};

		virtual ~Drawable() = default;

		virtual void draw(PB_Utils::Transform* transform) const = 0;

		DrawableType getType() const {
			return type;
		}

	private:

		DrawableType type = DrawableType::NONE;
	};
}

#endif // DRAWABLE_H