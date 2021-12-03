#ifndef QUATERNION_H
#define QUATERNION_H

#include <string>

namespace gnLib {

	class Quaternion {
	public:
		static Quaternion identity();

	public:
		Quaternion(float _x, float _y, float _z, float _w);
		~Quaternion() = default;

		const float length();

		const float sqrtLength();

		Quaternion normalized();

		Quaternion conjugate();

		Quaternion inverse();

		const float dot(const Quaternion& _q);

		const float cross(const Quaternion& _q);

		const Quaternion operator* (const Quaternion& _q) const;

		const bool operator== (const Quaternion& _q) const;

		const bool operator!= (const Quaternion& _q) const;

		const std::string toString();

	public:
		float x;
		float y;
		float z;
		float w;
	};

}

#endif // !QUATERNION_H
