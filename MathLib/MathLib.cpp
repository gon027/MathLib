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

int main()
{
    Test_ClassSize();

    // Matrix4x4 m = Matrix4x4::identity();
    auto m = Matrix4x4{
        1.0f, 2.0f, 3.0f, 4.0f,
        1.0f, 2.0f, 3.0f, 4.0f,
        1.0f, 2.0f, 3.0f, 4.0f,
        1.0f, 2.0f, 3.0f, 4.0f
    };
    cout << m.toString() << endl;
    cout << m.m[0][0] << endl;
    cout << m.m[1][1] << endl;
    cout << m.m[2][2] << endl;
    cout << m.m[3][3] << endl;

    /*
    auto m = Matrix4x4{
        1.0f, 2.0f, 3.0f, 4.0f,
        1.0f, 2.0f, 3.0f, 4.0f,
        1.0f, 2.0f, 3.0f, 4.0f,
        1.0f, 2.0f, 3.0f, 4.0f
    };
    cout << m.toString() << endl;

    cout << endl;

    Matrix4x4 n {
        12.0f, 32.0f, 43.0f, 12.0f,
        32.0f, 43.0f, 5.0f, 17.0f,
        74.0f, 3.0f, 5.0f, 123.0f,
        54.0f, 6.0f, 14.0f, 1.0f
    };
    auto nm = n * m;

    cout << nm.toString() << endl;

    Quaternion q = Quaternion::identity();
    cout << q.toString() << endl;
    */

    /*
    auto a = Matrix4x4::identity();
    auto b = Matrix4x4::identity();
    auto c = a * b;
    */

    // float d[16]{
    //     3, 1, 1, 2,
    //     5, 1, 3, 4,
    //     2, 0, 1, 0,
    //     1, 3, 2, 1
    // };
    // 
    // auto e = Matrix4x4{ d };
    // cout << e.toString() << endl;
    // 
    // auto x{ e.inverse() };
    // cout << x.toString() << endl;
    // 
    // e *= x;
    // cout << e.toString() << endl;
    // 
    // cout << "inv = " << e.determinant() << endl;

    /*
    auto te{ e.transpose() };
    cout << te.toString() << endl;

    /*
    auto f = e.determinant();
    cout << f << endl;
    cout << (1 / f) << endl;
    */

   

    while (true);
}
