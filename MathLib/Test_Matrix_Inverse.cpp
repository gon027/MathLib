#include <iostream>

#include "Math/include/Math.hpp"

int main() {
	using namespace gnLib;

	Matrix4x4 mat{
		2.0f, 3.0f, 6.0f, 3.0f,
		1.0f, 3.0f, 2.0f, 8.2f,
		3.3f, 2.6f, 1.5f, 2.5f,
		1.2f, 5.2f, 2.4f, 2.1f
	};
	std::cout << mat.toString() << std::endl;

	{
		auto invMat = mat;
		std::cout << invMat.toString() << std::endl;

		invMat.inverse();
		std::cout << invMat.toString() << std::endl;
	}

	
}