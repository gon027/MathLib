#ifndef QUATERNION_H
#define QUATERNION_H

#include <string>

namespace gnLib {

	class Vector3;
	class Matrix4x4;

	class Quaternion {
	public:

		/// <summary>
		/// �P�ʃN�H�[�^�j�I�����쐬����
		/// </summary>
		/// <returns> �P�ʃN�H�[�^�j�I�� </returns>
		static Quaternion identity();

		/// <summary>
		/// �C�ӂ̎��ɉ�]������]�N�H�[�^�j�I�����쐬����B
		/// </summary>
		/// <param name="_axis"> ��]����\��3D�x�N�g�� </param>
		/// <param name="_angle"> 
		/// ���W�A���P�ʂ̉�]�p�B
		/// ��]�������_�Ɍ������Č����Ƃ��A���v�ʂ�ɉ�]����B
		/// </param>
		/// <returns> ��]�N�H�[�^�j�I�� </returns>
		static Quaternion rotationAxis(const Vector3& _axis, float _angle);

		/// <summary>
		/// ��]�s�񂩂��]�N�H�[�^�j�I�����쐬����B
		/// </summary>
		/// <param name="_m"> ��]�s�� </param>
		/// <returns> ��]�N�H�[�^�j�I�� </returns>
		static Quaternion rotationMatrix(const Matrix4x4& _m);

		/// <summary>
		/// �s�b�`�A���[�A���[��(�I�C���[�p)�Ɋ�Â��ĉ�]�N�H�[�^�j�I�����쐬����B
		/// ��]�̏��Ԃ́A���[��(Z)�A�s�b�`(X)�A���[(Z)�̏��Ԃŉ�]����B
		/// </summary>
		/// <param name="_pitch"> x������̉�]�p </param>
		/// <param name="_yaw"> y������̉�]�p </param>
		/// <param name="_roll"> y������̉�]�p </param>
		/// <returns> ��]�N�H�[�^�j�I�� </returns>
		static Quaternion rotationRollPitchYaw(float _pitch, float _yaw, float _roll);

		/// <summary>
		/// �s�b�`�A���[�A���[��(�I�C���[�p)���܂ރx�N�g����Â��ĉ�]�N�H�[�^�j�I�����쐬����B
		/// ��]�̏��Ԃ́A���[��(Z)�A�s�b�`(X)�A���[(Z)�̏��Ԃŉ�]����B
		/// </summary>
		/// <param name="_angles"> �s�b�`�A���[�A���[��(�I�C���[�p)���܂ރx�N�g�� </param>
		/// <returns> ��]�N�H�[�^�j�I�� </returns>
		static Quaternion rotationRollPitchYaw(const Vector3& _angles);

		// static Quaternion euler(float _x, float _y, float _z);

	public:
		Quaternion(float _x, float _y, float _z, float _w);
		~Quaternion() = default;

		/// <summary>
		/// �N�H�[�^�j�I���̑傫�����v�Z����B
		/// </summary>
		/// <returns> �N�H�[�^�j�I���̑傫�� </returns>
		const float length();

		/// <summary>
		/// �N�H�[�^�j�I���̑傫����2����v�Z����B
		/// </summary>
		/// <returns> �N�H�[�^�j�I���̑傫����2�� </returns>
		const float sqrtLength();

		/// <summary>
		/// �N�H�[�^�j�I���𐳋K�����܂��B
		/// </summary>
		/// <returns> ���K�����ꂽ�N�H�[�^�j�I�� </returns>
		Quaternion normalized();

		/// <summary>
		/// �����N�H�[�^�j�I��
		/// </summary>
		/// <returns> �����N�H�[�^�j�I�� </returns>
		Quaternion conjugate();

		/// <summary>
		/// �t�N�H�[�^�j�I��
		/// </summary>
		/// <returns> �t�N�H�[�^�j�I�� </returns>
		Quaternion inverse();

		/// <summary>
		/// �N�H�[�^�j�I�������]�s����쐬���܂��B
		/// </summary>
		/// <returns> ��]�s�� </returns>
		Matrix4x4 toMatrix();

		/// <summary>
		/// �N�H�[�^�j�I���̓���
		/// </summary>
		/// <param name="_q"> �N�H�[�^�j�I�� </param>
		/// <returns> �N�H�[�^�j�I���̓��� </returns>
		const float dot(const Quaternion& _q);

		const Quaternion operator* (const Quaternion& _q) const;

		const Quaternion operator*= (const Quaternion& _q);

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
