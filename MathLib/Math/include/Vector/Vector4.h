#pragma once

#include <string>

namespace gnLib {

	class Vector3;
    class Matrix4x4;

	class Vector4 {
    public:
        static Vector4 Zero;
        static Vector4 One;

	public:
		float x;
		float y;
		float z;
		float w;

	public:
		Vector4();
		Vector4(float _x, float _y, float _z, float _w);
		Vector4(float _xyzw);
		~Vector4() = default;

        const float length() const;

        const float sqrtLength() const;

        const Vector4 normalized() const;

        const Vector3 toVector3() const;

        const Vector4 operator+() const;

        const Vector4 operator-() const;

        const Vector4 operator+(const Vector4& _v) const;

        const Vector4 operator-(const Vector4& _v) const;

        const Vector4 operator*(const Vector4& _v) const;

        const Vector4 operator*(const Matrix4x4& _mat) const;

        const Vector4 operator/(const Vector4& _v) const;

        const Vector4& operator+=(const Vector4& _v);

        const Vector4& operator-=(const Vector4& _v);

        const Vector4& operator*=(const Vector4& _v);

        const Vector4& operator/=(const Vector4& _v);

        const bool operator==(const Vector4& _v) const;

        const bool operator!=(const Vector4& _v) const;

        const std::string toString() const;
	};

    const Vector4 operator*(float _scaler, const Vector4& _v);

    const Vector4 operator*(const Matrix4x4&, const Vector4& _v);

}