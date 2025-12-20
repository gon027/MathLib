#include "../../include/Vector/Vector4.h"
#include "../../include/Vector/Vector3.h"
#include "../../include/Matrix/Matrix4x4.h"

#include <cmath>

namespace gnLib {

	Vector4 Vector4::Zero{ 0.0f, 0.0f, 0.0f, 0.0f };
	Vector4 Vector4::One{ 1.0f, 1.0f, 1.0f, 1.0f };

	Vector4::Vector4()
		: x{ 0.0f }
		, y{ 0.0f }
		, z{ 0.0f }
		, w{ 0.0f }
	{
	}

	Vector4::Vector4(float _x, float _y, float _z, float _w)
		: x{ _x }
		, y{ _y }
		, z{ _z }
		, w{ _w }
	{
	}

	Vector4::Vector4(float _xyzw)
		: x{ _xyzw }
		, y{ _xyzw }
		, z{ _xyzw }
		, w{ _xyzw }
	{
	}

	const float Vector4::length() const {
		return std::sqrtf(sqrtLength());
	}

	const float Vector4::sqrtLength() const
	{
		return x * x + y * y + z * z + w * w;
	}

	const Vector4 Vector4::normalized() const
	{
		auto len{ length() };
		if (len <= 0.001f) {
			return Vector4::Zero;
		}

		const auto oneOverLen{ 1.0f / len };
		return {
			x * oneOverLen,
			y * oneOverLen,
			z * oneOverLen,
			w * oneOverLen,
		};
	}

	const Vector3 Vector4::toVector3() const
	{
		return { x, y, z };
	}

	const Vector4 Vector4::operator+() const {
		return { x, y, z, w };
	}

	const Vector4 Vector4::operator-() const
	{
		return { -x, -y, -z, -w };
	}

	const Vector4 Vector4::operator+(const Vector4& _v) const
	{
		return { x + _v.x, y + _v.y, z + _v.z, w + _v.w };
	}

	const Vector4 Vector4::operator-(const Vector4& _v) const
	{
		return { x - _v.x, y - _v.y, z - _v.z, w - _v.w };
	}

	const Vector4 Vector4::operator*(const Vector4& _v) const
	{
		return { x * _v.x, y * _v.y, z * _v.z, w * _v.w };
	}

	const Vector4 Vector4::operator/(const Vector4& _v) const
	{
		return { x / _v.x, y / _v.y, z / _v.z, w / _v.w };
	}

	const Vector4& Vector4::operator+=(const Vector4& _v)
	{
		this->x += _v.x;
		this->y += _v.y;
		this->z += _v.z;
		this->w += _v.w;
		return *this;
	}

	const Vector4& Vector4::operator-=(const Vector4& _v)
	{
		this->x -= _v.x;
		this->y -= _v.y;
		this->z -= _v.z;
		this->w -= _v.w;
		return *this;
	}

	const Vector4& Vector4::operator*=(const Vector4& _v)
	{
		this->x *= _v.x;
		this->y *= _v.y;
		this->z *= _v.z;
		this->w *= _v.w;
		return *this;
	}

	const Vector4& Vector4::operator/=(const Vector4& _v) {
		this->x /= _v.x;
		this->y /= _v.y;
		this->z /= _v.z;
		this->w /= _v.w;
		return *this;
	}

	const bool Vector4::operator==(const Vector4& _v) const
	{
		return (x == _v.x) && (y == _v.y) && (z == _v.z) && (w == _v.w);
	}

	const bool Vector4::operator!=(const Vector4& _v) const
	{
		return !(*this == _v);
	}

	const std::string Vector4::toString() const
	{
		return {
			" [x: " + std::to_string(x) +
			", y: " + std::to_string(y) +
			", z: " + std::to_string(z) +
			", w: " + std::to_string(w) + "]\n"
		};
	}

	const Vector4 operator*(float _scaler, const Vector4& _v)
	{
		return {
			_scaler * _v.x,
			_scaler * _v.y,
			_scaler * _v.z,
			_scaler * _v.w,
		};
	}

	const Vector4 operator*(const Matrix4x4& _mat, const Vector4& _v)
	{
		return Vector4{
			_v.x * _mat.m00 + _v.y * _mat.m10 + _v.z * _mat.m20 + _v.w * _mat.m30,
			_v.x * _mat.m01 + _v.y * _mat.m11 + _v.z * _mat.m21 + _v.w * _mat.m31,
			_v.x * _mat.m02 + _v.y * _mat.m12 + _v.z * _mat.m22 + _v.w * _mat.m32,
			_v.x * _mat.m03 + _v.y * _mat.m13 + _v.z * _mat.m23 + _v.w * _mat.m33,
		};
	}

}