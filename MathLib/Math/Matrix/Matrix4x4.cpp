#include "Matrix4x4.h"
#include <string>
#include <cmath>
#include <iostream>

#define tostr(value) std::to_string(value)

namespace gnLib {

    namespace {

        // 3x3行列の行列式
        const float determinant3x3(
            float _m00, float _m01, float _m02,
            float _m10, float _m11, float _m12,
            float _m20, float _m21, float _m22) 
        {
            // 対角
            const float a0{ _m00 * _m11 * _m22 };
            const float a1{ _m01 * _m12 * _m20 };
            const float a2{ _m02 * _m10 * _m21 };

            // 非対角
            const float b0{ _m02 * _m11 * _m20 };
            const float b1{ _m01 * _m10 * _m22 };
            const float b2{ _m00 * _m12 * _m21 };

            return a0 + a1 + a2 - b0 - b1 - b2;
        }
    }

    Matrix4x4 Matrix4x4::identity()
    {
        return Matrix4x4(
            1.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 1.0f
        );
    }

    Matrix4x4::Matrix4x4(const Matrix4x4& _mat)
        : m00(_mat.m00), m01(_mat.m01), m02(_mat.m02), m03(_mat.m03)
        , m10(_mat.m10), m11(_mat.m11), m12(_mat.m12), m13(_mat.m13)
        , m20(_mat.m20), m21(_mat.m21), m22(_mat.m22), m23(_mat.m23)
        , m30(_mat.m30), m31(_mat.m31), m32(_mat.m32), m33(_mat.m33)
    {
    }

    Matrix4x4::Matrix4x4(
        float _m00, float _m01, float _m02, float _m03,
        float _m10, float _m11, float _m12, float _m13,
        float _m20, float _m21, float _m22, float _m23,
        float _m30, float _m31, float _m32, float _m33)
        : m00(_m00), m01(_m01), m02(_m02), m03(_m03)
        , m10(_m10), m11(_m11), m12(_m12), m13(_m13)
        , m20(_m20), m21(_m21), m22(_m22), m23(_m23)
        , m30(_m30), m31(_m31), m32(_m32), m33(_m33)
    {
        std::cout << "Matrix4x4::Constracter" << std::endl;
    }

    Matrix4x4::Matrix4x4(const float _mat[16])
        : m00(_mat[0]), m01(_mat[1]), m02(_mat[2]), m03(_mat[3])
        , m10(_mat[4]), m11(_mat[5]), m12(_mat[6]), m13(_mat[7])
        , m20(_mat[8]), m21(_mat[9]), m22(_mat[10]), m23(_mat[11])
        , m30(_mat[12]), m31(_mat[13]), m32(_mat[14]), m33(_mat[15])
    {
    }

                        const float Matrix4x4::determinant()
    {
        float a0{ m00 * determinant3x3(m11, m12, m13, m21, m22, m23, m31, m32, m33) };
        float a1{ m10 * determinant3x3(m01, m02, m03, m21, m22, m23, m31, m32, m33) };
        float a2{ m20 * determinant3x3(m01, m02, m03, m11, m12, m13, m31, m32, m33) };
        float a3{ m30 * determinant3x3(m01, m02, m03, m11, m12, m13, m21, m22, m23) };

        return a0 - a1 + a2 - a3;
    }

    const Matrix4x4 Matrix4x4::inverse()
    {
        const float det = determinant();

        // 行列式が0の時、逆行列ではなく元の行列を返す
        if (std::abs(det) < 0.00001f) {
            return { *this };
        }

        const float inv = 1 / det;

        // 各余韻子を計算
        const float n00{ inv * determinant3x3(m11, m12, m13, m21, m22, m23, m31, m32, m33) };
        const float n10{ -inv * determinant3x3(m10, m12, m13, m20, m22, m23, m30, m32, m33) };
        const float n20{ inv * determinant3x3(m10, m11, m13, m20, m21, m23, m30, m31, m33) };
        const float n30{ -inv * determinant3x3(m10, m11, m12, m20, m21, m22, m30, m31, m32) };

        const float n01{ -inv * determinant3x3(m01, m02, m03, m21, m22, m23, m31, m32, m33) };
        const float n11{ inv * determinant3x3(m00, m02, m03, m20, m22, m23, m30, m32, m33) };
        const float n21{ -inv * determinant3x3(m00, m01, m03, m20, m21, m23, m30, m31, m33) };
        const float n31{ inv * determinant3x3(m00, m01, m02, m20, m21, m22, m30, m31, m32) };

        const float n02{ inv * determinant3x3(m01, m02, m03, m11, m12, m13, m31, m32, m33) };
        const float n12{ -inv * determinant3x3(m00, m02, m03, m10, m12, m13, m30, m32, m33) };
        const float n22{ inv * determinant3x3(m00, m01, m03, m10, m11, m13, m30, m31, m33) };
        const float n32{ -inv * determinant3x3(m00, m01, m02, m10, m11, m12, m30, m31, m32) };

        const float n03{ -inv * determinant3x3(m01, m02, m03, m11, m12, m13, m21, m22, m23) };
        const float n13{ inv * determinant3x3(m00, m02, m03, m10, m12, m13, m20, m22, m23) };
        const float n23{ -inv * determinant3x3(m00, m01, m03, m10, m11, m13, m20, m21, m23) };
        const float n33{ inv * determinant3x3(m00, m01, m02, m10, m11, m12, m20, m21, m22) };

        
        return {
            n00, n01, n02, n03,
            n10, n11, n12, n13,
            n20, n21, n22, n23,
            n30, n31, n32, n33
        };
        
    }

    const Matrix4x4 Matrix4x4::transpose()
    {
        return {
            m00, m10, m20, m30,
            m01, m11, m21, m31,
            m02, m12, m22, m32,
            m03, m13, m23, m33
        };
    }

    const std::string Matrix4x4::toString()
    {
        return
            "[ m00 = " + tostr(m00) + ", m01 = " + tostr(m01) + ", m02 = " + tostr(m02) + ", m03 =  " + tostr(m03) + " ]\n"
            "[ m10 = " + tostr(m10) + ", m11 = " + tostr(m11) + ", m12 = " + tostr(m12) + ", m13 =  " + tostr(m13) + " ]\n"
            "[ m20 = " + tostr(m20) + ", m21 = " + tostr(m21) + ", m22 = " + tostr(m22) + ", m23 =  " + tostr(m23) + " ]\n"
            "[ m30 = " + tostr(m30) + ", m31 = " + tostr(m31) + ", m32 = " + tostr(m32) + ", m33 =  " + tostr(m33) + " ]\n";
    }

    const Matrix4x4 Matrix4x4::operator+(const Matrix4x4& _mat)
    {
        return Matrix4x4(
            m00 + _mat.m00, m01 + _mat.m01, m02 + _mat.m02, m03 + _mat.m03,
            m10 + _mat.m10, m11 + _mat.m11, m12 + _mat.m12, m13 + _mat.m13,
            m20 + _mat.m20, m21 + _mat.m21, m22 + _mat.m22, m23 + _mat.m23,
            m30 + _mat.m30, m31 + _mat.m31, m32 + _mat.m32, m33 + _mat.m33
        );
    }

    const Matrix4x4 Matrix4x4::operator-(const Matrix4x4& _mat)
    {
        return Matrix4x4(
            m00 - _mat.m00, m01 - _mat.m01, m02 - _mat.m02, m03 - _mat.m03,
            m10 - _mat.m10, m11 - _mat.m11, m12 - _mat.m12, m13 - _mat.m13,
            m20 - _mat.m20, m21 - _mat.m21, m22 - _mat.m22, m23 - _mat.m23,
            m30 - _mat.m30, m31 - _mat.m31, m32 - _mat.m32, m33 - _mat.m33
        );
    }

    const Matrix4x4 Matrix4x4::operator*(const Matrix4x4& _mat)
    {
        const float nm00{ m00 * _mat.m00 + m01 * _mat.m10 + m02 * _mat.m20 + m03 * _mat.m30 };
        const float nm01{ m00 * _mat.m01 + m01 * _mat.m11 + m02 * _mat.m21 + m03 * _mat.m31 };
        const float nm02{ m00 * _mat.m02 + m01 * _mat.m12 + m02 * _mat.m22 + m03 * _mat.m32 };
        const float nm03{ m00 * _mat.m03 + m01 * _mat.m13 + m02 * _mat.m23 + m03 * _mat.m33 };

        const float nm10{ m10 * _mat.m00 + m11 * _mat.m10 + m12 * _mat.m20 + m13 * _mat.m30 };
        const float nm11{ m10 * _mat.m01 + m11 * _mat.m11 + m12 * _mat.m21 + m13 * _mat.m31 };
        const float nm12{ m10 * _mat.m02 + m11 * _mat.m12 + m12 * _mat.m22 + m13 * _mat.m32 };
        const float nm13{ m10 * _mat.m03 + m11 * _mat.m13 + m12 * _mat.m23 + m13 * _mat.m33 };

        const float nm20{ m20 * _mat.m00 + m21 * _mat.m10 + m22 * _mat.m20 + m23 * _mat.m30 };
        const float nm21{ m20 * _mat.m01 + m21 * _mat.m11 + m22 * _mat.m21 + m23 * _mat.m31 };
        const float nm22{ m20 * _mat.m02 + m21 * _mat.m12 + m22 * _mat.m22 + m23 * _mat.m32 };
        const float nm23{ m20 * _mat.m03 + m21 * _mat.m13 + m22 * _mat.m23 + m23 * _mat.m33 };

        const float nm30{ m30 * _mat.m00 + m31 * _mat.m10 + m32 * _mat.m20 + m33 * _mat.m30 };
        const float nm31{ m30 * _mat.m01 + m31 * _mat.m11 + m32 * _mat.m21 + m33 * _mat.m31 };
        const float nm32{ m30 * _mat.m02 + m31 * _mat.m12 + m32 * _mat.m22 + m33 * _mat.m32 };
        const float nm33{ m30 * _mat.m03 + m31 * _mat.m13 + m32 * _mat.m23 + m33 * _mat.m33 };

        return Matrix4x4(
            nm00, nm01, nm02, nm03,
            nm10, nm11, nm12, nm13,
            nm20, nm21, nm22, nm23,
            nm30, nm31, nm32, nm33
        );
    }

    const Matrix4x4 Matrix4x4::operator*(float _scalar)
    {
        return {
            m00 * _scalar, m01 * _scalar, m02 * _scalar, m03 * _scalar,
            m10 * _scalar, m11 * _scalar, m12 * _scalar, m13 * _scalar,
            m20 * _scalar, m21 * _scalar, m22 * _scalar, m23 * _scalar,
            m30 * _scalar, m31 * _scalar, m32 * _scalar, m33 * _scalar
        };
    }

    const Matrix4x4 operator*(float _scalar, const Matrix4x4& _mat)
    {
        return {
           _scalar* _mat.m00, _scalar * _mat.m01, _scalar * _mat.m02, _scalar * _mat.m03,
           _scalar* _mat.m10, _scalar * _mat.m11, _scalar * _mat.m12, _scalar * _mat.m13,
           _scalar* _mat.m20, _scalar * _mat.m21, _scalar * _mat.m22, _scalar * _mat.m23,
           _scalar* _mat.m30, _scalar * _mat.m31, _scalar * _mat.m32, _scalar * _mat.m33
        };
    }

    Matrix4x4& operator*=(Matrix4x4& _m, const Matrix4x4& _mat)
    {
        _m = _m * _mat;
        return _m;
    }
}