#include <iostream>
#include <Math/include/Math.hpp>
#include <DirectXMath.h>
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

// _Matrix4x4のRotationテスト
void Test_Matrix4x4_Rotation() {
    auto x = Matrix4x4::rotationX(10.0f);
    cout << x.toString() << endl;

    auto y = Matrix4x4::rotationY(45.0f);
    cout << y.toString() << endl;

    auto z = Matrix4x4::rotationZ(30.0f);
    cout << z.toString() << endl;

    auto zxy = z * x * y;
    cout << zxy.toString() << endl;

    auto a = Matrix4x4::rotationRollPitchYaw({ 10.f, 45.f, 30.f });
    cout << a.toString() << endl;
}

void print_XMMatrix(const DirectX::XMMATRIX& _m) {
    auto x = _m.r[0].m128_f32;
    auto y = _m.r[1].m128_f32;
    auto z = _m.r[2].m128_f32;
    auto w = _m.r[3].m128_f32;

    cout << "[ x = " << x[0] << ", y = " << x[1] << ", z = " << x[2] << ", w = " << x[3] << " ]" << endl;
    cout << "[ x = " << y[0] << ", y = " << y[1] << ", z = " << y[2] << ", w = " << y[3] << " ]" << endl;
    cout << "[ x = " << z[0] << ", y = " << z[1] << ", z = " << z[2] << ", w = " << z[3] << " ]" << endl;
    cout << "[ x = " << w[0] << ", y = " << w[1] << ", z = " << w[2] << ", w = " << w[3] << " ]" << endl;
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

    // Test_Matrix4x4_Rotation();

    using namespace DirectX;

    // auto xlh = XMMatrixLookAtLH(
    //     { 10, 20, -5 },
    //     { 0, 0, 0 },
    //     { 0, 1, 0 }
    // );
    // print_XMMatrix(xlh);
    // // xlh.r[0].m128_f32[0];
    // 
    // auto lh = Matrix4x4::lookAtLH(
    //     { 10, 20, -5 },
    //     { 0, 0, 0 },
    //     { 0, 1, 0 }
    // );
    // cout << lh.toString() << endl;

    // auto xog = XMMatrixOrthographicLH(
    //     640, 480, 0.5f, 100.0f
    // );
    // print_XMMatrix(xog);
    // 
    // auto og = Matrix4x4::orthographicLH(
    //     640, 480, 0.5f, 100.0f
    // );
    // cout << og.toString() << endl;

    // auto fovAngle = (45.0f * 3.141592f / 180.0f);
    // auto aspect = (640.0f / 480.0f);
    // 
    // auto xper = XMMatrixPerspectiveFovLH(
    //     fovAngle, aspect, 0.5f, 100.0f
    // );
    // print_XMMatrix(xper);
    // 
    // auto per = Matrix4x4::perspectiveFovLH(
    //     fovAngle, aspect, 0.5f, 100.0f
    // );
    // cout << per.toString() << endl;

    // auto xperlh = XMMatrixPerspectiveLH(
    //     640, 480, 0.5f, 100.0f
    // );
    // print_XMMatrix(xperlh);
    // 
    // auto perlh = Matrix4x4::perspectiveLH(
    //     640, 480, 0.5f, 100.0f
    // );
    // cout << perlh.toString() << endl;
}
