#include <iostream>
#include <chrono>
#include <string_view>
#include <Math/include/Math.hpp>
#include <DirectXMath.h>
using namespace std;
using namespace chrono;
using namespace gnLib;

constexpr int MAX_LOOP = 10;
constexpr int MAX_COUNT = 1'000'000;

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

Matrix4x4 srt(const Matrix4x4& _s, const Matrix4x4& _r, const Matrix4x4& _t) {
	auto result = _s * _r;
	result.m30 = _t.m30;
	result.m31 = _t.m31;
	result.m32 = _t.m32;
	return result;
}

int main() {
	Timer timer;

	// 721mx
	//for (auto i = 0; i < MAX_COUNT; ++i) {
		auto s = Matrix4x4::scaling({ 2.0f, 2.0f, 2.0f });
		auto r = Matrix4x4::rotationRollPitchYaw(100, 100, 100);
		auto t = Matrix4x4::translation({ 2.0f, 2.0f, 2.0f });
		// auto asrt = s * r * t;

		// cout << 1 << endl;
		auto sr = srt(s, r, t);

	//}

	// timer.printTime("gnLIbMath = ", "ms");
	// 
	// // 1652mx
	// for (auto i = 0; i < MAX_COUNT; ++i) {
	// 	auto r = DirectX::XMMatrixRotationRollPitchYaw(100, 100, 100);
	// 	auto s = DirectX::XMMatrixScaling(2, 2, 2);
	// 	auto t = DirectX::XMMatrixTranslation(2, 2, 2);
	// 	auto srt = s * r * t;
	// }
	// timer.printTime("DirectXMath = ", "ms");
}