#ifndef VECT2_H
#define VECT2_H

namespace PB_Math {

	


    class Vec2 {
    public:
        float x;
        float y;

        float length() const;

        float getDistanceSquared() const noexcept;

        Vec2 normalize() const;

        Vec2 rotate(float angle) const;

        Vec2 rotate(float c, float s) const;

        Vec2 perpendicular() const {
            return Vec2(-y, x);
        }

        Vec2 operator+(const Vec2& other) const;

        Vec2 operator-(const Vec2& other) const;

        Vec2 operator-() const {
            return Vec2(-x, -y);
        }

        Vec2 operator*(float scalar) const;

        Vec2 operator/(float scalar) const;

        float dot(const Vec2& other) const;

        bool operator==(const Vec2& other) const;

        static float fast_sqrt(float x) {
            float xhalf = 0.5f * x;
			int i = *(int*)&x;            // Evil floating point bit hack
			i = 0x5f3759df - (i >> 1);    // What the...
            x = *(float*)&i;
			x = x * (1.5f - xhalf * x * x); // 1st iteration of Newton's method
			return x * xhalf * 2.0f;       // Multiply by x to get sqrt(x)
        }
    };

}

#endif // VECT2_H