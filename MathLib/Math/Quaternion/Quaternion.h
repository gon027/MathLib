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

		Quaternion operator* (const Quaternion& _quaternion);
		bool operator== (const Quaternion& _quaternion);

		const std::string toString();

	private:
		float x;
		float y;
		float z;
		float w;
	};
}

#endif // !QUATERNION_H
