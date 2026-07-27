#ifndef VECT2_H
#define VECT2_H

namespace PB_Math {
	class Vec2 {
	public:
		float x;
		float y;
		Vec2(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}

		Vec2 operator+(const Vec2& other) const;

		Vec2 operator*(float scalar) const;

		Vec2 operator/(float scalar) const;
	};
}

#endif // VECT2_H