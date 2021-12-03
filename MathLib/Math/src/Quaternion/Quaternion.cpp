#include "../../include/Quaternion/Quaternion.h"
#include <cmath>

#define tostr(value) std::to_string(value)

#include <iostream>

namespace gnLib {

    Quaternion gnLib::Quaternion::identity()
    {
        return { 0.0f, 0.0f, 0.0f, 1.0f };
    }

    Quaternion::Quaternion(float _x, float _y, float _z, float _w)
        : x(_x)
        , y(_y)
        , z(_z)
        , w(_w)
    {
    }

    const float Quaternion::length()
    {
        return std::sqrtf(sqrtLength());
    }

    const float Quaternion::sqrtLength()
    {
        return x * x + y * y + z * z + w * w;
    }

    Quaternion Quaternion::normalized()
    {
        auto len = length();

        // ’l‚ª0‚ÌŽž
        if (len < 0.0001f) {
            return Quaternion::identity();
        }

        auto mg = 1.0f / len;
        return {
            x * mg, y * mg, z * mg, w * mg
        };
    }

    Quaternion Quaternion::conjugate()
    {
        return { -x, -y, -z, w };
    }

    Quaternion Quaternion::inverse()
    {
        auto len = sqrtLength();

        // 0ˆ—
        if (len < 0.00001f) {
            return Quaternion::identity();
        }

        auto cq = conjugate();
        auto oneOverLen = 1.0f / len;

        return {
            cq.x * oneOverLen,
            cq.y * oneOverLen,
            cq.z * oneOverLen,
            cq.w * oneOverLen,
        };
    }

    const Quaternion Quaternion::operator*(const Quaternion& _q) const
    {
        const float rw{ w * _q.w - x * _q.x - y * _q.y - z * _q.z };
        const float rx{ w * _q.x + _q.w * x + y * _q.z - z * _q.y };
        const float ry{ w * _q.y + _q.w * y + z * _q.x - x * _q.z };
        const float rz{ w * _q.z + _q.w * z + x * _q.y - y * _q.x };

        return { rx, ry, rz, rw };
    }

    const bool Quaternion::operator==(const Quaternion& _q) const
    {
        return {
            x == _q.x && y == _q.y && z == _q.z && w == _q.w
        };
    }

    const bool Quaternion::operator!=(const Quaternion& _q) const
    {
        return !(*this == _q);
    }

    const std::string Quaternion::toString()
    {
        return { 
            "[ x = " + tostr(x) +
            ", y = " + tostr(y) +
            ", z = " + tostr(z) +
            ", w = " + tostr(w) + " ]\n"
        };
    }

}
