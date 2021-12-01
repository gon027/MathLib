#ifndef MATRIX4X4_H
#define MATRIX4X4_H

#include <string>

namespace gnLib {

	class Matrix4x4 {
	public:
		static Matrix4x4 identity();

	public:
		Matrix4x4();
		Matrix4x4(const Matrix4x4& _mat);
		Matrix4x4(
			float _m00, float _m01, float _m02, float _m03,
			float _m10, float _m11, float _m12, float _m13,
			float _m20, float _m21, float _m22, float _m23,
			float _m30, float _m31, float _m32, float _m33
		);
		Matrix4x4(const float _mat[16]);
		~Matrix4x4() = default;

		// çsóÒéÆ
		float determinant();

		// ãtçsóÒ
		void inverse();

		// ì]íuçsóÒ
		void transpose();

		// operator
		const Matrix4x4 operator+(const Matrix4x4& _mat) const;

		const Matrix4x4 operator-(const Matrix4x4& _mat) const;

		const Matrix4x4 operator*(const Matrix4x4& _mat) const;
		const Matrix4x4 operator*(float _scalar) const;
		const friend Matrix4x4 operator*(float _scalar, const Matrix4x4& _mat);

		const Matrix4x4& operator+=(const Matrix4x4& _mat);

		const Matrix4x4& operator-=(const Matrix4x4& _mat);

		const Matrix4x4& operator*=(const Matrix4x4& _mat);

		const bool operator==(const Matrix4x4& _rm) const;

		const bool operator!=(const Matrix4x4& _rm) const;

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