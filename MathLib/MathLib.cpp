#include <iostream>
#include <Math/include/Matrix/Matrix4x4.h>
#include <Math/include/Matrix/Matrix4x3.h>
#include <Math/include/Quaternion/Quaternion.h>
#include <Math/include/Vector/Vector2.h>
#include <Math/include/Vector/Vector3.h>
using namespace std;
using namespace gnLib;

// 各クラスのサイズのテスト
void Test_ClassSize() {
    cout << "sizeof(Vector2) = "    << sizeof(Vector2)    << endl; // 4 * 2 = 8
    cout << "sizeof(Vector3) = "    << sizeof(Vector3)    << endl; // 4 * 3 = 12
    cout << "sizeof(Matrix4x4) = "  << sizeof(Matrix4x4)  << endl; // 4 * (4 * 4) = 64
    cout << "sizeof(Matrix4x3) = "  << sizeof(Matrix4x3)  << endl; // 4 * (4 * 3) = 48
    cout << "sizeof(Quaternion) = " << sizeof(Quaternion) << endl; // 4 * 4 = 16
    cout << endl;
}

// 転置行列のテスト
void Test_Matrix4x4_Transpose() {
    auto m = Matrix4x4{
       12.0f, 32.0f, 22.0f, 12.0f,
       20.0f, 93.0f, 57.0f, 17.0f,
       64.0f, 14.0f, 50.0f, 23.0f,
       71.0f, 77.0f, 14.0f, 11.0f
    };

    m.transpose();
    cout << m.toString() << endl;
}

// 逆行列のテスト
void Test_Matrix4x4_Inverse() {
    auto m = Matrix4x4{
        3.0f, 1.0f, 1.0f, 2.0f,
        5.0f, 1.0f, 3.0f, 4.0f,
        2.0f, 0.0f, 1.0f, 0.0f,
        1.0f, 3.0f, 2.0f, 1.0f
    };

    m.inverse();
    cout << "determinant = " << m.determinant() << endl;
    cout << m.toString() << endl;
}

// 行列の四則演算のテスト
void Test_Matrix4x4_Operater() {
    auto mx1 = Matrix4x4{
        2.0f, 3.0f, 6.0f, 2.0f,
        1.0f, 4.0f, 3.0f, 1.0f,
        2.0f, 1.0f, 5.0f, 5.0f,
        1.0f, 3.0f, 5.0f, 3.0f
    };
    
    auto mx2 = Matrix4x4{
        3, 1, 2, 2,
        5, 3, 3, 3,
        1, 2, 1, 5,
        3, 3, 4, 5
    };

    cout << "op1" << endl;
    auto op1 = mx1 + mx2;
    cout << op1.toString() << endl;

    cout << "op2" << endl;
    auto op2 = mx1 - mx2;
    cout << op2.toString() << endl;

    cout << "op3_1" << endl;
    auto op3_1 = mx1 * mx2;
    cout << op3_1.toString() << endl;

    cout << "op3_2" << endl;
    auto op3_2 = mx2 * mx1;
    cout << op3_2.toString() << endl;

    cout << "op4" << endl;
    auto op4 = mx1 * 2.0f;
    cout << op4.toString() << endl;

    cout << "op5" << endl;
    auto op5 = 2.0f * mx1;
    cout << op5.toString() << endl;

    // cout << "mx1 +=" << endl;
    // mx1 += mx2;
    // cout << mx1.toString() << endl; // op1と同じになる

    // cout << "mx1 -=" << endl;
    // mx1 -= mx2;
    // cout << mx1.toString() << endl; // op2と同じになる
    
    // cout << "mx1 +=" << endl;
    // mx1 *= mx2;
    // cout << mx1.toString() << endl; // op3_1と同じになる

    auto mx3 = Matrix4x4::identity();
    auto mx4 = Matrix4x4::identity();
    cout << "mx1 == mx2 = " << std::boolalpha << (mx1 == mx2) << endl;
    cout << "mx1 != mx2 = " << std::boolalpha << (mx1 != mx2) << endl;

    cout << "mx3 == mx4 = " << std::boolalpha << (mx3 == mx4) << endl;
    cout << "mx3 != mx4 = " << std::boolalpha << (mx3 != mx4) << endl;
}

int main()
{
    Test_ClassSize();

    Test_Matrix4x4_Transpose();

    Test_Matrix4x4_Inverse();

    Test_Matrix4x4_Operater();

}
