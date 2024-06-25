#pragma once
#include "Vector2.h"

Geometry::Vector2::Vector2(float x, float y) : sf::Vector2f(x, y) {

}

float Geometry::Vector2::length() const {
    return std::sqrt(this->x * this->x + this->y * this->y);
}

Geometry::Vector2 Geometry::Vector2::normalize() const {
    float length = this->length();
    if (length != 0)
        return Vector2(this->x / length, this->y / length);
    else
        return *this;
}

float Geometry::Vector2::dot(const Vector2& vec) const
{
    return this->x * vec.x + this->y * vec.y;
}

Geometry::Vector2 Geometry::Vector2::lerp(const Vector2& start, const Vector2& end, float t) {
    if (t > 1.0f)
        t = 1.0f;
    if (t < 0.0f)
        t = 0.0f;
    float x = start.x + t * (end.x - start.x);
    float y = start.y + t * (end.y - start.y);
    return Vector2(x, y);
}


Geometry::Vector2::Vector2() {
    this->x = 0.0f;
    this->y = 0.0f;
}

float Geometry::Vector2::angleBetween(const Vector2& a, const Vector2& b) {
    float dotProduct = a.dot(b);
    float lengths = a.length() * b.length();
    float cosTheta = dotProduct / lengths;
    // Protect from possible errors when calculating cosTheta
    if (cosTheta > 1.0f) cosTheta = 1.0f;
    else if (cosTheta < -1.0f) cosTheta = -1.0f;
    return std::acos(cosTheta); // Return angle in radians
}

bool Geometry::Vector2::isEnterViewAngle(const Vector2& direction, const Vector2& position, float angleView)
{
    Geometry::Vector2 normDirect = direction.normalize(); 
    Geometry::Vector2 differentPos = (position - *this); 
    Geometry::Vector2 normPos = differentPos.normalize();

    const float radAngle = Geometry::Vector2::angleBetween(normDirect, normPos);
    const float angle = radAngle * (180 / 3.14);

    if (angle < angleView / 2)
        return true;
    return false;
}


std::ostream& Geometry::operator<<(std::ostream& stream, const Geometry::Vector2& vector)
{
    return stream << vector.x  << " " << vector.y;
}

Geometry::Vector2 Geometry::operator+(const Vector2& v1, const Vector2& v2)
{
    return Geometry::Vector2(v1.x + v2.x, v1.y + v2.y);
}

Geometry::Vector2 Geometry::operator-(const Vector2& v1, const Vector2& v2)
{
    return Geometry::Vector2(v1.x - v2.x, v1.y - v2.y);
}

Geometry::Vector2 Geometry::operator*(const Vector2& v1, const Vector2& v2)
{
    return Geometry::Vector2(v1.x * v2.x, v1.y * v2.y);
}

Geometry::Vector2 Geometry::operator/(const Vector2& v1, const Vector2& v2)
{
    return Geometry::Vector2(v1.x / v2.x, v1.y / v2.y);
}

Geometry::Vector2 Geometry::operator*(const Vector2& v1, float num)
{
    return Geometry::Vector2(v1.x * num, v1.y * num);
}

Geometry::Vector2 Geometry::operator/(const Vector2& v1, float num)
{
    return Geometry::Vector2(v1.x / num, v1.y / num);
}