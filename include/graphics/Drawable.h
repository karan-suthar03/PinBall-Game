#ifndef DRAWABLE_H
#define DRAWABLE_H

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

		DrawableType getType() const {
			return type;
		}

	private:

		DrawableType type = DrawableType::NONE;
	};
}

#endif // DRAWABLE_H