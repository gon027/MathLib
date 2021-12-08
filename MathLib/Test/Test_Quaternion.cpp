#include <iostream>
#include <Math/include/Math.hpp>
#include <DirectXMath.h>
#include <chrono>
#include <string_view>
using namespace std;
using namespace chrono;

struct Timer {
	Timer()
		: start(system_clock::now())
		, end() {}

	template<class duration = chrono::milliseconds>
	void printTime(std::string_view _sv, std::string_view _s) {
		end = system_clock::now();
		auto elapsed = chrono::duration_cast<duration>(end - start).count();
		cout << _sv << elapsed << _s << endl;

		start = system_clock::now();
	}

private:
	system_clock::time_point start{};
	system_clock::time_point end{};
};

constexpr unsigned int MAX_COUNT = 100'000'000;

float toRadian(float _angle) {
	return _angle * 3.141592f / 180.0f;
}

int main() {
	using namespace gnLib;

	// Timer t{};
	// 
	// auto r = toRadian(45.0f);
	// 
	// for (size_t i = 0; i < MAX_COUNT; ++i) {
	// 	auto q = Quaternion::rotationAxis({ 1, 0, 0 }, r);
	// 	auto m = Quaternion::toMatrix(q);
	// 	// cout << m.toString() << endl;
	// }
	// t.printTime("Quaternion = ", "ms");
	// 
	// for (size_t i = 0; i < MAX_COUNT; ++i) {
	// 	auto m = Matrix4x4::rotationRollPitchYaw(r, 0, 0);
	// }
	// t.printTime("Matrix = ", "ms");

	auto q = Quaternion::rotationAxis({ 1, 0, 0 }, toRadian(45.f));

	auto m1 = Quaternion::toMatrix(q);
	cout << m1.toString() << endl;

	cout << q.toMatrix().toString() << endl;
}