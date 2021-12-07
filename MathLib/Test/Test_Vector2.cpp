#include <iostream>
#include <Math/include/Math.hpp>
#include <DirectXMath.h>
using namespace std;

int main() {
	using namespace gnLib;

	Vector2 v1{ 10, 20 };
	cout << v1.sqrtLength() << endl;
	cout << v1.length() << endl;
	cout << std::sqrtf(v1.sqrtLength()) << endl;
	cout << v1.normalized().toString() << endl;

	auto v2 = Vector2{ v1.x / v1.length(), v1.y / v1.length() };
	cout << v2.toString() << endl;
}