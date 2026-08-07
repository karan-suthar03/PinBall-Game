#include "math/vec2.h"
#include <math.h>


using namespace PB_Math;

float Vec2::length() const {
    return fast_sqrt(x * x + y * y);
}

float Vec2::getDistanceSquared() const noexcept {
    return x * x + y * y;
}

Vec2 Vec2::normalize() const {
    float len = length();
	if (len == 0) {
		return Vec2(0, 0);
    }
    return (*this) / len;
}

Vec2 Vec2::rotate(float angle) const
{
    float cosA = cos(angle);
    float sinA = sin(angle);
	return Vec2(x * cosA - y * sinA, x * sinA + y * cosA);
}

Vec2 Vec2::rotate(float c, float s) const
{
	return Vec2(x * c - y * s, x * s + y * c);
}

Vec2 Vec2::operator+(const Vec2& other) const {
	return Vec2(x + other.x, y + other.y);
}

Vec2 Vec2::operator-(const Vec2& other) const {
	return Vec2(x - other.x, y - other.y);
}

Vec2 Vec2::operator*(float scalar) const {
	return Vec2(x * scalar, y * scalar);
}

Vec2 Vec2::operator/(float scalar) const {
	return Vec2(x / scalar, y / scalar);
}

float Vec2::dot(const Vec2& other) const {
    return x * other.x + y * other.y;
}

bool Vec2::operator==(const Vec2& other) const {
    return x == other.x && y == other.y;
}