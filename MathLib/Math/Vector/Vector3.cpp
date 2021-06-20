#include "Vector2.h"
#include "Vector3.h"
#include <cmath>

namespace gnLib {

	Vector3 Vector3::Up      { 0.0f, 1.0f, 0.0f  };
	Vector3 Vector3::Down    { 0.0f, -1.0f, 0.0f };
	Vector3 Vector3::Left    { -1.0f, 0.0f, 0.0f };
	Vector3 Vector3::Right   { 1.0f, 0.0f, 0.0f  };
	Vector3 Vector3::Back    { 0.0f, 0.0f, -1.0f };
	Vector3 Vector3::Forward { 0.0f, 0.0f, 1.0f  };
	Vector3 Vector3::One     { 1.0f, 1.0f, 1.0f  };
	Vector3 Vector3::Zero    { 0.0f, 0.0f, 0.0f  };

	Vector3::Vector3()
		: x(0.0f)
		, y(0.0f)
		, z(0.0f)
	{ }

	Vector3::Vector3(const Vector2 & _vector)
		: x(_vector.x)
		, y(_vector.y)
		, z(0.0f)
	{ }

	Vector3::Vector3(const Vector3 & _vector)
		: x(_vector.x)
		, y(_vector.y)
		, z(_vector.z)
	{ }

	gnLib::Vector3::Vector3(float _x, float _y, float _z)
		: x(_x)
		, y(_y)
		, z(_z)
	{ }

	gnLib::Vector3::Vector3(float _xyz)
		: x(_xyz)
		, y(_xyz)
		, z(_xyz)
	{ }

	void Vector3::setPos(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}

	void Vector3::setPos(const Vector3 & _vector)
	{
		setPos(_vector.x, _vector.y, _vector.z);
	}

	const float Vector3::magnitude() const
	{
		return x * x + y * y + z * z;
	}

	const Vector3 Vector3::normalized() const
	{
		auto length = sqrMagnitude();

		return {
			x / length,
			y / length,
			z / length
		};
	}

	const float Vector3::sqrMagnitude() const
	{
		return sqrtf(magnitude());
	}

	const Vector3 Vector3::half() const
	{
		return Vector3{ x / 2.0f, y / 2.0f, z / 2.0f };
	}

	const float Vector3::dot(const Vector3 & _v)
	{
		return x * _v.x + y * _v.y + z * _v.z;
	}

	const Vector3 Vector3::cross(const Vector3 & _v)
	{
		return {
			y * _v.z - _v.y * z,
			-(x * _v.z - z * _v.x),
			x * _v.y - y * _v.x
		};
	}

	const Vector2 Vector3::toVector2()
	{
		return { x, y };
	}

	const Vector3 Vector3::operator+() const
	{
		return { x, y, z };
	}

	const Vector3 Vector3::operator-() const
	{
		return { -x, -y, -z };
	}

	const Vector3 Vector3::operator+(const Vector3 & _rvec) const
	{
		return { x + _rvec.x, y + _rvec.y, z + _rvec.z };
	}

	const Vector3 Vector3::operator-(const Vector3 & _rvec) const
	{
		return { x - _rvec.x, y - _rvec.y, z - _rvec.z };
	}

	const Vector3 Vector3::operator*(const Vector3 & _rvec) const
	{
		return { x * _rvec.x, y * _rvec.y, z * _rvec.z };
	}

	const Vector3 Vector3::operator/(const Vector3 & _rvec) const
	{
		return { x / _rvec.x, y / _rvec.y, z / _rvec.z };
	}

	const Vector3& Vector3::operator+=(const Vector3 & _rvec)
	{
		this->x += _rvec.x;
		this->y += _rvec.y;
		this->z += _rvec.z;
		return *this;
	}

	const Vector3& Vector3::operator-=(const Vector3 & _rvec)
	{
		this->x -= _rvec.x;
		this->y -= _rvec.y;
		this->z -= _rvec.z;
		return *this;
	}

	const Vector3& Vector3::operator*=(const Vector3 & _rvec)
	{
		this->x *= _rvec.x;
		this->y *= _rvec.y;
		this->z *= _rvec.z;
		return *this;
	}

	const Vector3& Vector3::operator/=(const Vector3 & _rvec)
	{
		this->x /= _rvec.x;
		this->y /= _rvec.y;
		this->z /= _rvec.z;
		return *this;
	}

	const bool Vector3::operator==(const Vector3 & _rvec) const
	{
		return (x == _rvec.x) && (y == _rvec.y) && (z == _rvec.z);
	}

	const bool Vector3::operator!=(const Vector3 & _rvec) const
	{
		return (x != _rvec.x) || (y != _rvec.y) || (z != _rvec.z);
	}

	const std::string Vector3::toString() const 
	{
		return "[x: " + std::to_string(x)
			+ ", y: " + std::to_string(y)
			+ ", z " + std::to_string(z)
			+ "]\n";
	}

}