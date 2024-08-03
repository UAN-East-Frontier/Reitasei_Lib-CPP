#pragma once
#include "Vector2.h"

gm::Vector2::Vector2(float x, float y) : sf::Vector2f(x, y) {

}

float gm::Vector2::length() const {
    return std::sqrt(this->x * this->x + this->y * this->y);
}

gm::Vector2 gm::Vector2::normalize() const {
    float length = this->length();
    if (length != 0)
        return Vector2(this->x / length, this->y / length);
    else
        return *this;
}

float gm::Vector2::dot(const Vector2& vec) const
{
    return this->x * vec.x + this->y * vec.y;
}

gm::Vector2 gm::Vector2::lerp(const Vector2& start, const Vector2& end, float t) {
    if (t > 1.0f)
        t = 1.0f;
    if (t < 0.0f)
        t = 0.0f;
    float x = start.x + t * (end.x - start.x);
    float y = start.y + t * (end.y - start.y);
    return Vector2(x, y);
}


gm::Vector2::Vector2() {
    this->x = 0.0f;
    this->y = 0.0f;
}

float gm::Vector2::angleBetween(const Vector2& a, const Vector2& b) {
    float dotProduct = a.dot(b);
    float lengths = a.length() * b.length();
    float cosTheta = dotProduct / lengths;
    // Protect from possible errors when calculating cosTheta
    if (cosTheta > 1.0f) cosTheta = 1.0f;
    else if (cosTheta < -1.0f) cosTheta = -1.0f;
    return std::acos(cosTheta); // Return angle in radians
}

bool gm::Vector2::isEnterViewAngle(const Vector2& direction, const Vector2& position, float angleView)
{
    gm::Vector2 normDirect = direction.normalize(); 
    gm::Vector2 differentPos = (position - *this); 
    gm::Vector2 normPos = differentPos.normalize();

    const float radAngle = gm::Vector2::angleBetween(normDirect, normPos);
    const float angle = radAngle * (180 / 3.14);

    if (angle < angleView / 2)
        return true;
    return false;
}


std::ostream& gm::operator<<(std::ostream& stream, const gm::Vector2& vector)
{
    return stream << vector.x  << " " << vector.y;
}

gm::Vector2 gm::operator+(const Vector2& v1, const Vector2& v2)
{
    return gm::Vector2(v1.x + v2.x, v1.y + v2.y);
}

gm::Vector2 gm::operator-(const Vector2& v1, const Vector2& v2)
{
    return gm::Vector2(v1.x - v2.x, v1.y - v2.y);
}

gm::Vector2 gm::operator*(const Vector2& v1, const Vector2& v2)
{
    return gm::Vector2(v1.x * v2.x, v1.y * v2.y);
}

gm::Vector2 gm::operator/(const Vector2& v1, const Vector2& v2)
{
    return gm::Vector2(v1.x / v2.x, v1.y / v2.y);
}

gm::Vector2 gm::operator*(const Vector2& v1, float num)
{
    return gm::Vector2(v1.x * num, v1.y * num);
}

gm::Vector2 gm::operator/(const Vector2& v1, float num)
{
    return gm::Vector2(v1.x / num, v1.y / num);
}