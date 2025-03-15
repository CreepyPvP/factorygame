#pragma once
#include "raylib.h"
#include "types.h"


struct Vec2I
{
    i32 x;
    i32 y;

    Vec2I();
    Vec2I(i32 x, i32 y);
    Vec2I(Vector2 vec);

    Vec2I operator+(const Vec2I& rhs) const;
    Vec2I& operator+=(const Vec2I& rhs);
    Vec2I operator-(const Vec2I& rhs) const;
    Vec2I& operator-=(const Vec2I& rhs);
    Vec2I operator*(const Vec2I& rhs) const;
    Vec2I& operator*=(const Vec2I& rhs);
    Vec2I operator/(const Vec2I& rhs) const;
    Vec2I& operator/=(const Vec2I& rhs);
    bool operator==(const Vec2I& rhs) const;
    Vec2I operator*(const i32& rhs) const;
    Vec2I& operator*=(const i32& rhs);
    Vec2I operator/(const i32& rhs) const;
    Vec2I& operator/=(const i32& rhs);

    operator Vector2() const;

};


inline Vec2I v2i(i32 x, i32 y)
{
    return {x, y};
}
inline Vector2 v2(f32 x, f32 y)
{
    return {x, y};
}