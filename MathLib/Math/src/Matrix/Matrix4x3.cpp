#include "../../include/Matrix/Matrix4x3.h"

#define tostr(value) std::to_string(value)

namespace gnLib {

	Matrix4x3 Matrix4x3::identity()
	{
		return {
			1.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 1.0f,
			0.0f, 0.0f, 0.0f,
		};
	}

	Matrix4x3::Matrix4x3()
		: m00(0.0f), m01(0.0f), m02(0.0f)
		, m10(0.0f), m11(0.0f), m12(0.0f)
		, m20(0.0f), m21(0.0f), m22(0.0f)
		, m30(0.0f), m31(0.0f), m32(0.0f)
	{
	}

	Matrix4x3::Matrix4x3(const Matrix4x3& _mat)
		: m00(_mat.m00), m01(_mat.m01), m02(_mat.m02)
		, m10(_mat.m10), m11(_mat.m11), m12(_mat.m12)
		, m20(_mat.m20), m21(_mat.m21), m22(_mat.m22)
		, m30(_mat.m30), m31(_mat.m31), m32(_mat.m32)
	{
	}

	Matrix4x3::Matrix4x3(
		float _m00, float _m01, float _m02, 
		float _m10, float _m11, float _m12, 
		float _m20, float _m21, float _m22, 
		float _m30, float _m31, float _m32
	)
		: m00(_m00), m01(_m01), m02(_m02)
		, m10(_m10), m11(_m11), m12(_m12)
		, m20(_m20), m21(_m21), m22(_m22)
		, m30(_m30), m31(_m31), m32(_m32)
	{
	}

	Matrix4x3::Matrix4x3(const float _mat[12])
		: m00(_mat[0]), m01(_mat[1]), m02(_mat[2])
		, m10(_mat[3]), m11(_mat[4]), m12(_mat[5])
		, m20(_mat[6]), m21(_mat[7]), m22(_mat[8])
		, m30(_mat[9]), m31(_mat[10]), m32(_mat[11])
	{
	}

	float Matrix4x3::determinant()
	{
		return 0.0f;
	}

	void Matrix4x3::inverse()
	{
	}

	// ˆê”Ô‰º‚Ì—ñ(m30, m31, m32)‚Í0.0f‚ð‘ã“ü‚·‚é
	void Matrix4x3::transpose()
	{
		std::swap(m01, m10);
		std::swap(m02, m20);
		std::swap(m12, m21);
		m30 = 0.0f;
		m31 = 0.0f;
		m32 = 0.0f;
	}

	const Matrix4x3 Matrix4x3::operator+(const Matrix4x3& _mat) const
	{
		return Matrix4x3();
	}

	const Matrix4x3 Matrix4x3::operator-(const Matrix4x3& _mat) const
	{
		return Matrix4x3();
	}

	const Matrix4x3 Matrix4x3::operator*(const Matrix4x3& _mat) const
	{
		return Matrix4x3();
	}

	const Matrix4x3 Matrix4x3::operator*(float _scalar) const
	{
		return Matrix4x3();
	}

	const Matrix4x3 operator*(float _scalar, const Matrix4x3& _mat)
	{
		return Matrix4x3();
	}

	const Matrix4x3& Matrix4x3::operator+=(const Matrix4x3& _mat)
	{
		return *this;
	}

	const Matrix4x3& Matrix4x3::operator-=(const Matrix4x3& _mat)
	{
		return *this;
	}

	const Matrix4x3& Matrix4x3::operator*=(const Matrix4x3& _mat)
	{
		return *this;
	}

	const bool Matrix4x3::operator==(const Matrix4x3& _rm) const
	{
		return false;
	}

	const bool Matrix4x3::operator!=(const Matrix4x3& _rm) const
	{
		return false;
	}

	const std::string Matrix4x3::toString()
	{
		return {
			"[ m00 = " + tostr(m00) + ", m01 = " + tostr(m01) + ", m02 = " + tostr(m02) + " ]\n"
			"[ m10 = " + tostr(m10) + ", m11 = " + tostr(m11) + ", m12 = " + tostr(m12) + " ]\n"
			"[ m20 = " + tostr(m20) + ", m21 = " + tostr(m21) + ", m22 = " + tostr(m22) + " ]\n"
			"[ m30 = " + tostr(m30) + ", m31 = " + tostr(m31) + ", m32 = " + tostr(m32) + " ]\n"
		};
	}

}