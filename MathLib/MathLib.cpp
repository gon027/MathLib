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

    // cout << "op3_2" << endl;
    // auto op3_2 = mx2 * mx1;
    // cout << op3_2.toString() << endl;
    // 
    // cout << "op4" << endl;
    // auto op4 = mx1 * 2.0f;
    // cout << op4.toString() << endl;
    // 
    // cout << "op5" << endl;
    // auto op5 = 2.0f * mx1;
    // cout << op5.toString() << endl;

    // cout << "mx1 +=" << endl;
    // mx1 += mx2;
    // cout << mx1.toString() << endl; // op1と同じになる

    // cout << "mx1 -=" << endl;
    // mx1 -= mx2;
    // cout << mx1.toString() << endl; // op2と同じになる
    
    cout << "mx1 +=" << endl;
    mx1 *= mx2;
    cout << mx1.toString() << endl; // op3_1と同じになる

    // auto mx3 = Matrix4x4::identity();
    // auto mx4 = Matrix4x4::identity();
    // cout << "mx1 == mx2 = " << std::boolalpha << (mx1 == mx2) << endl;
    // cout << "mx1 != mx2 = " << std::boolalpha << (mx1 != mx2) << endl;
    // 
    // cout << "mx3 == mx4 = " << std::boolalpha << (mx3 == mx4) << endl;
    // cout << "mx3 != mx4 = " << std::boolalpha << (mx3 != mx4) << endl;
}

// Matrix4x3のコンストラクタのテスト
void Test_Matrix4x3_Constractor() {
    auto mi = Matrix4x3::identity();
    cout << mi.toString() << endl;

    Matrix4x3 m1 {};
    cout << m1.toString() << endl;

    Matrix4x3 m2 {
        1, 1, 1,
        2, 2, 2,
        3, 3, 3,
        4, 4, 4
    };
    cout << m2.toString() << endl;

    Matrix4x3 m3{ m2 };
    cout << m3.toString() << endl;

    float fm[12]{
        5, 5, 5,
        6, 6, 6,
        7, 7, 7,
        8, 8, 8
    };
    Matrix4x3 m4{ fm };
    cout << m4.toString() << endl;
}

// Matrix4x3の転置行列のテスト
void Test_Matrix4x3_Transpose() {
    Matrix4x3 m{
        1, 1, 1,
        2, 2, 2,
        3, 3, 3,
        4, 4, 4
    };

    cout << m.toString() << endl;
    m.transpose();
    cout << m.toString() << endl;
}

// Matrix4x3の演算子のテスト
void Test_Matrix4x3_Operater() {
    Matrix4x3 mx1{
        1, 2, 3,
        4, 5, 6,
        7, 8, 9,
        10, 11, 12
    };

    Matrix4x3 mx2{
        1, 2, 3,
        1, 2, 3,
        1, 2, 3,
        1, 2, 3,
    };

    auto mx3 = Matrix4x3::identity();
    auto mx4 = Matrix4x3::identity();

    cout << "mx1 + mx2" << endl;
    auto res1 = mx1 + mx2;
    cout << res1.toString() << endl;

    cout << "mx1 - mx2" << endl;
    auto res2 = mx1 - mx2;
    cout << res2.toString() << endl;

    cout << "mx1 * mx2" << endl;
    auto res3 = mx1 * mx2;
    cout << res3.toString() << endl;

    cout << "mx2 * mx1" << endl;
    auto res4 = mx2 * mx1;
    cout << res4.toString() << endl;

    cout << "mx1 * 2.0f" << endl;
    auto res5 = mx1 * 2.0f;
    cout << res5.toString() << endl;

    cout << "2.0f * mx1" << endl;
    auto res6 = 2.0f * mx1;
    cout << res6.toString() << endl;

    // cout << "mx1 += mx2" << endl;
    // mx1 += mx2;
    // cout << mx1.toString() << endl;

    // cout << "mx1 -= mx2" << endl;
    // mx1 -= mx2;
    // cout << mx1.toString() << endl;

    // // mx1 * mx2と同じになる
    // cout << "mx1 *= mx2" << endl;
    // mx1 *= mx2;
    // cout << mx1.toString() << endl;

    // // mx2 * mx1と同じになる
    // cout << "mx2 *= mx1" << endl;
    // mx2 *= mx1;
    // cout << mx2.toString() << endl;

    cout << "mx1 == mx2" << endl;
    cout << std::boolalpha << (mx1 == mx2) << endl;

    cout << "mx1 != mx2" << endl;
    cout << std::boolalpha << (mx1 != mx2) << endl;

    cout << "mx3 == mx4" << endl;
    cout << std::boolalpha << (mx3 == mx4) << endl;

    cout << "mx3 != mx4" << endl;
    cout << std::boolalpha << (mx3 != mx4) << endl;
}

// Matrix4x3の行列式のテスト
void Test_Matrix4x3_Determinant() {
    Matrix4x3 m{
        1, 1, 1,
        2, 2, 10,
        3, 3, 3,
        4, 4, 4
    };

    // 3x3の行列式が帰ってくる
    // 1 * (6 - 30) + 2 * (3 - 3) + 3 * (2 - 2) = 24
    cout << m.determinant() << endl;
}

// Matrix4x3の逆行列のテスト
void Test_Matrix4x3_Inverse() {
    Matrix4x3 m{
        8, 5, 7,
        2, 2, 5,
        3, 5, 9,
        3, 4, 5
    };

    //cout << m.determinant() << endl;
    m.inverse();
    cout << m.toString() << endl;
}

// Quaternionのテスト
void Test_Quaternion() {
    auto q1 = Quaternion{ 1, 2, 3, 4 };
    auto q2 = Quaternion{ 5, 6, 7, 8 };
    auto q3 = q1 * q2;
    auto q4 = q2 * q1;
     
    cout << q3.toString() << endl;
    cout << q4.toString() << endl;
}

// Quaternion正規化テスト
void Test_Quaternion_Normalized() {
    auto q = Quaternion{ 1, 2, 3, 4 };

    cout << "SqrtLength = " << q.sqrtLength() << endl;
    cout << "Length = " << q.length() << endl;;
    cout << "Normalized = " << q.normalized().toString() << endl;
}

// Quaternion内積テスト
void Test_Quaternion_Dot() {
    auto q1 = Quaternion{ 7, 9, 2, 4 };
    auto q2 = Quaternion{ 5, 1, 8, 3 };
    auto a = q1.dot(q2);

    cout << a << endl;
}

// Quaternionの逆クォータニオンのテスト
void Test_Quaternion_Inverse() {
    auto q = Quaternion{ 7, 3, 1, 4 };
    auto cq = q.inverse();
    cout << q.toString() << endl;
    cout << cq.toString() << endl;

    auto r = q * cq;
    cout << r.toString() << endl;
}

int main()
{
    // Test_ClassSize();

    // Test_Matrix4x4_Transpose();
    // Test_Matrix4x4_Inverse();
    // Test_Matrix4x4_Operater();

    // Test_Matrix4x3_Constractor();
    // Test_Matrix4x3_Transpose();
    // Test_Matrix4x3_Operater();
    // Test_Matrix4x3_Determinant();
    // Test_Matrix4x3_Inverse();

    // Test_Quaternion();
    // Test_Quaternion_Normalized();
    // Test_Quaternion_Dot();
    // Test_Quaternion_Inverse();

    // Vector2 v{ 100.0f, 200.0f };
    // auto v2 = 2.0f * v;
    // cout << v2.toString() << endl;
    // cout << v2.half().toString() << endl;
    // 
    // Vector2 rv{ 100.0f, 200.0f };
    // cout << std::boolalpha << (v == rv) << endl;
    // cout << std::boolalpha << (v != rv) << endl;
    // cout << std::boolalpha << (v == v2) << endl;
    // cout << std::boolalpha << (v != v2) << endl;

    Vector3 v3{ 200.0f, 300.0f, 500.0f };
    auto v4 = 2.0f * v3;
    cout << v4.toString() << endl;
    cout << v4.half().toString() << endl;
    
    Vector3 v5{ 200.0f, 300.0f, 500.0f };
    cout << std::boolalpha << (v3 == v5) << endl;
    cout << std::boolalpha << (v3 != v5) << endl;
    cout << std::boolalpha << (v3 == v4) << endl;
    cout << std::boolalpha << (v3 != v4) << endl;
}
