#include "vec2.h"


using namespace PB_Math;

Vec2 Vec2::operator+(const Vec2& other) const {
	return Vec2(x + other.x, y + other.y);
}

Vec2 Vec2::operator*(float scalar) const {
	return Vec2(x * scalar, y * scalar);
}


Vec2 Vec2::operator/(float scalar) const {
	return Vec2(x / scalar, y / scalar);
}