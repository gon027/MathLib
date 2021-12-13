#pragma once

// �x�N�g��
#include "Vector/Vector2.h"
#include "Vector/Vector3.h"

// �s��
// #include "Matrix/Matrix4x3.h"
#include "Matrix/Matrix4x4.h"

// �N�H�[�^�j�I��
#include "Quaternion/Quaternion.h"

namespace gnLib {
	
	constexpr float pi = 3.14159265359f;

	inline float toRadian(float _angle) {
		return _angle * pi / 180.0f;
	}

	inline float toDegrees(float _radian) {
		return _radian * 180.0f / pi;
	}

}