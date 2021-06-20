#include "Quaternion.h"

#define tostr(value) std::to_string(value)

namespace gnLib {

    Quaternion gnLib::Quaternion::identity()
    {
        return Quaternion(0.0f, 0.0f, 0.0f, 1.0f);
    }

    Quaternion::Quaternion(float _x, float _y, float _z, float _w)
        : x(_x)
        , y(_y)
        , z(_z)
        , w(_w)
    {
    }

    const std::string Quaternion::toString()
    {
        return "[ x = " + tostr(x) + ", y = " + tostr(y) + ", z = " + tostr(z) + ", w = " + tostr(w) + " ]\n";
    }

}
