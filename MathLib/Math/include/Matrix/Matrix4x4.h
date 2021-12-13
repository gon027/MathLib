#ifndef MATRIX4X4_H
#define MATRIX4X4_H

#include <string>

namespace gnLib {

	class Vector3;

	class Matrix4x4 {
	public:

		/// <summary>
		/// �P�ʍs����쐬����B
		/// </summary>
		/// <returns> �P�ʍs�� </returns>
		static Matrix4x4 identity();

		/// <summary>
		/// x�������Ƃ�����]�s����쐬����B
		/// </summary>
		/// <param name="_angle"> 
		/// ���W�A���P�ʂ̉�]�p�B
		/// ��]�������_�Ɍ������Č����Ƃ��A���v�ʂ�ɉ�]����B
		/// </param>
		/// <returns> x���̉�]�s�� </returns>
		static Matrix4x4 rotationX(float _angle);

		/// <summary>
		/// y�������Ƃ�����]�s����쐬����B
		/// </summary>
		/// <param name="_angle">
		/// ���W�A���P�ʂ̉�]�p�B
		/// ��]�������_�Ɍ������Č����Ƃ��A���v�ʂ�ɉ�]����B
		/// </param>
		/// <returns> y���̉�]�s�� </returns>
		static Matrix4x4 rotationY(float _angle);

		/// <summary>
		/// z�������Ƃ�����]�s����쐬����B
		/// </summary>
		/// <param name="_angle">
		/// ���W�A���P�ʂ̉�]�p�B
		/// ��]�������_�Ɍ������Č����Ƃ��A���v�ʂ�ɉ�]����B
		/// </param>
		/// <returns> z���̉�]�s�� </returns>
		static Matrix4x4 rotationZ(float _angle);

		/// <summary>
		/// �s�b�`�A���[�A���[��(�I�C���[�p)�Ɋ�Â��ĉ�]�s����쐬����B
		/// ��]�̏��Ԃ́A���[��(Z)�A�s�b�`(X)�A���[(Z)�̏��Ԃŉ�]����B
		/// </summary>
		/// <param name="_pitch"> x������̉�]�p </param>
		/// <param name="_yaw"> y������̉�]�p </param>
		/// <param name="_roll"> z������̉�]�p </param>
		/// <returns> ��]�s�� </returns>
		static Matrix4x4 rotationRollPitchYaw(float _pitch, float _yaw, float _roll);

		/// <summary>
		/// �s�b�`�A���[�A���[��(�I�C���[�p)���܂ރx�N�g����Â��ĉ�]�N�H�[�^�j�I�����쐬����B
		/// ��]�̏��Ԃ́A���[��(Z)�A�s�b�`(X)�A���[(Z)�̏��Ԃŉ�]����B
		/// </summary>
		/// <param name="_angles"> �s�b�`�A���[�A���[��(�I�C���[�p)���܂ރx�N�g�� </param>
		/// <returns> ��]�s�� </returns>
		static Matrix4x4 rotationRollPitchYaw(const class Vector3& _angles);

		/// <summary>
		/// x���Ay���Az���ɉ������g��E�k���s����쐬����B
		/// </summary>
		/// <param name="_scallX"> x���ɉ������{�� </param>
		/// <param name="_scallY"> y���ɉ������{�� </param>
		/// <param name="_scallZ"> z���ɉ������{�� </param>
		/// <returns> �X�P�[�����O�s�� </returns>
		static Matrix4x4 scaling(float _scallX, float _scallY, float _scallZ);

		/// <summary>
		///  x���Ay���Az�����܂ރx�N�g������Â��Ċg��E�k���s����쐬����B
		/// </summary>
		/// <param name="_scall"> �g��E�k�����܂ރx�N�g�� </param>
		/// <returns> �X�P�[�����O�s�� </returns>
		static Matrix4x4 scaling(const class Vector3& _scall);

		/// <summary>
		/// ���s�ړ����ꂽ�ϊ��s����쐬����B
		/// </summary>
		/// <param name="_offsetX"> x���ɉ��������s�ړ� </param>
		/// <param name="_offsetY"> y���ɉ��������s�ړ� </param>
		/// <param name="_offsetZ"> z���ɉ��������s�ړ� </param>
		/// <returns> ���s�ړ����ꂽ�ϊ��s�� </returns>
		static Matrix4x4 translation(float _offsetX, float _offsetY, float _offsetZ);

		/// <summary>
		/// ���s�ړ����ꂽ�ϊ��s����쐬����B
		/// </summary>
		/// <param name="_offset"> x���Ay���Az�����܂ރx�N�g�� </param>
		/// <returns> ���s�ړ����ꂽ�ϊ��s�� </returns>
		static Matrix4x4 translation(const class Vector3& _offset);

		/// <summary>
		/// ������W�n����Ƃ��A�J�����̈ʒu�A������A�œ_�����g�p���āA�r���[�s����쐬����B
		/// </summary>
		/// <param name="_eye"> �J�����̈ʒu </param>
		/// <param name="_focus"> �J�����̏œ_ </param>
		/// <param name="_up"> �J�����̏���� </param>
		/// <returns> �r���[�s�� </returns>
		static Matrix4x4 lookAtLH(const Vector3& _eye, const Vector3& _focus, const Vector3& _up);

		/// <summary>
		/// ������W�n�̐��ˉe�s����쐬����B
		/// </summary>
		/// <param name="_viewWidth"> �N���b�s���O���ʂ̐���̕� </param>
		/// <param name="_viewHeight"> �N���b�s���O���ʂ̐���̍��� </param>
		/// <param name="_nearZ"> �߂��̃N���b�s���O���ʂ̋��� </param>
		/// <param name="_farZ"> �����̃N���b�s���O���ʂ̋��� </param>
		/// <returns> ���ˉe�s�� </returns>
		static Matrix4x4 orthographicLH(float _viewWidth, float _viewHeight, float _nearZ, float _farZ);

		/// <summary>
		/// ������W�n�̓������e�s����쐬����B
		/// </summary>
		/// <param name="_fovAngleY"> ����p(���W�A���P��) </param>
		/// <param name="_aspectRatio"> �A�X�y�N�g�� </param>
		/// <param name="_nearZ"> �߂��̃N���b�s���O���ʂ̋���(0���傫���Ȃ���΂Ȃ�Ȃ�) </param>
		/// <param name="_farZ"> �����̃N���b�s���O���ʂ̋���(0���傫���Ȃ���΂Ȃ�Ȃ�)  </param>
		/// <returns> �������e�s�� </returns>
		static Matrix4x4 perspectiveFovLH(float _fovAngleY, float _aspectRatio, float _nearZ, float _farZ);

		/// <summary>
		/// ������W�n�̓������e�s����쐬����B
		/// </summary>
		/// <param name="_viewWidth"> �N���b�s���O���ʂ̐���̕� </param>
		/// <param name="_viewHeight"> �N���b�s���O���ʂ̐���̍��� </param>
		/// <param name="_nearZ"> �߂��̃N���b�s���O���ʂ̋��� </param>
		/// <param name="_farZ"> �����̃N���b�s���O���ʂ̋��� </param>
		/// <returns> �������e�s�� </returns>
		static Matrix4x4 perspectiveLH(float _viewWidth, float _viewHeight, float _nearZ, float _farZ);

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

		/// <summary>
		/// �s�񎮂��v�Z����B
		/// </summary>
		/// <returns> �s�� </returns>
		float determinant();

		/// <summary>
		/// �t�s����v�Z����B
		/// </summary>
		void inverse();

		/// <summary>
		/// �s���]�u�s��ɂ���B
		/// </summary>
		void transpose();

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
			float m[4][4];

			struct {
				float m00, m01, m02, m03;
				float m10, m11, m12, m13;
				float m20, m21, m22, m23;
				float m30, m31, m32, m33;
			};
		};
	};

}

#endif // !MATRIX4X4_H