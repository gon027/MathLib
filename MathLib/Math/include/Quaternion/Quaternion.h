#ifndef QUATERNION_H
#define QUATERNION_H

#include <string>

namespace gnLib {

	class Vector3;
	class Matrix4x4;

	class Quaternion {
	public:
		// �P�ʃN�H�[�^�j�I���𐶐�
		static Quaternion identity();

		static Quaternion rotationAxis(const Vector3& _axis, float _angle);

		static Quaternion rotationMatrix(const Matrix4x4& _m);

		// x: phtch, y: yaw, z: roll
		// ��]���鏇�� z -> x -> y
		static Quaternion rotationRollPitchYaw(float _pitch, float _yaw, float _roll);
		static Quaternion rotationRollPitchYaw(const Vector3& _angles);

		// static Quaternion euler(float _x, float _y, float _z);

		// ��]�s��ɕϊ�
		static Matrix4x4 toMatrix(const Quaternion& _q);

	public:
		Quaternion(float _x, float _y, float _z, float _w);
		~Quaternion() = default;

		const float length();

		const float sqrtLength();

		Quaternion normalized();

		Quaternion conjugate();

		Quaternion inverse();

		const float dot(const Quaternion& _q);

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
