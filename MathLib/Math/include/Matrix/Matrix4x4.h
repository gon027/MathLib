#ifndef MATRIX4X4_H
#define MATRIX4X4_H

#include <string>

namespace gnLib {

	class Matrix4x4 {
	public:
		static Matrix4x4 identity();

		static Matrix4x4 rotationX(float _angle);
		static Matrix4x4 rotationY(float _angle);
		static Matrix4x4 rotationZ(float _angle);

		// x: phtch, y: yaw, z: roll
		// âÒì]Ç∑ÇÈèáî‘ z -> x -> y
		static Matrix4x4 rotationRollPitchYaw(float _pitch, float _yaw, float _roll);
		static Matrix4x4 rotationRollPitchYaw(const class Vector3& _angles);

		static Matrix4x4 scaling(float _scallX, float _scallY, float _scallZ);
		static Matrix4x4 scaling(const class Vector3& _scall);

		static Matrix4x4 translation(float _offsetX, float _offsetY, float _offsetZ);
		static Matrix4x4 translation(const class Vector3& _offset);

	public:
		Matrix4x4();
		Matrix4x4(const Matrix4x4& _m);
		Matrix4x4(
			float _m00, float _m01, float _m02, float _m03,
			float _m10, float _m11, float _m12, float _m13,
			float _m20, float _m21, float _m22, float _m23,
			float _m30, float _m31, float _m32, float _m33
		);
		Matrix4x4(const float _m[16]);
		~Matrix4x4() = default;

		// çsóÒéÆ
		float determinant();

		// ãtçsóÒ
		void inverse();

		// ì]íuçsóÒ
		void transpose();

		// operator
		const Matrix4x4 operator+(const Matrix4x4& _m) const;

		const Matrix4x4 operator-(const Matrix4x4& _m) const;

		const Matrix4x4 operator*(const Matrix4x4& _m) const;
		const Matrix4x4 operator*(float _scalar) const;
		const friend Matrix4x4 operator*(float _scalar, const Matrix4x4& _m);

		const Matrix4x4& operator+=(const Matrix4x4& _m);

		const Matrix4x4& operator-=(const Matrix4x4& _m);

		const Matrix4x4& operator*=(const Matrix4x4& _m);

		const bool operator==(const Matrix4x4& _m) const;

		const bool operator!=(const Matrix4x4& _m) const;

		const std::string toString();

	public:
		union {
			struct {
				float m00, m01, m02, m03;
				float m10, m11, m12, m13;
				float m20, m21, m22, m23;
				float m30, m31, m32, m33;
			};

			float m[4][4];
		};
	};

}

#endif // !MATRIX4X4_H