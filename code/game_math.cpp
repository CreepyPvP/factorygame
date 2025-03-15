#include "game_math.h"


///////////////////////////////
/// Vec2I
///////////////////////////////

Vec2I::Vec2I(const i32 x, const i32 y): x(x), y(y)
{
}

Vec2I::Vec2I(const Vector2 vec): x((i32)vec.x), y((i32)vec.y)
{
}

Vec2I Vec2I::operator+(const Vec2I &rhs) const
{
    return {this->x + rhs.x, this->y + rhs.y};
}

Vec2I & Vec2I::operator+=(const Vec2I &rhs)
{
    this->x += rhs.x;
    this->y += rhs.y;
    return *this;
}

Vec2I Vec2I::operator-(const Vec2I &rhs) const
{
    return {this->x - rhs.x, this->y - rhs.y};
}

Vec2I & Vec2I::operator-=(const Vec2I &rhs)
{
    this->x -= rhs.x;
    this->y -= rhs.y;
    return *this;
}

Vec2I Vec2I::operator*(const Vec2I &rhs) const
{
    return {this->x * rhs.x, this->y * rhs.y};
}

Vec2I & Vec2I::operator*=(const Vec2I &rhs)
{
    this->x *= rhs.x;
    this->y *= rhs.y;
    return *this;
}

Vec2I Vec2I::operator/(const Vec2I &rhs) const
{
    return {this->x / rhs.x, this->y / rhs.y};
}

Vec2I & Vec2I::operator/=(const Vec2I &rhs)
{
    this->x /= rhs.x;
    this->y /= rhs.y;
    return *this;
}

bool Vec2I::operator==(const Vec2I &rhs) const
{
    return this->x == rhs.x && this->y == rhs.y;
}

Vec2I Vec2I::operator*(const i32 &rhs) const
{
    return {this->x * rhs, this->y * rhs};
}

Vec2I & Vec2I::operator*=(const i32 &rhs)
{
    this->x *= rhs;
    this->y *= rhs;
    return *this;
}

Vec2I Vec2I::operator/(const i32 &rhs) const
{
    return {this->x / rhs, this->y / rhs};
}

Vec2I & Vec2I::operator/=(const i32 &rhs)
{
    this->x /= rhs;
    this->y /= rhs;
    return *this;
}

Vec2I::operator Vector2() const
{
    return Vector2{(f32) x, (f32) y};
}
