#include <SFML/Graphics.hpp>

namespace gm {

    class Vector2 : public sf::Vector2f
    {
    public:
        Vector2(float x, float y);
        Vector2();

        float length() const;

        Vector2 normalize() const;

        float dot(const Vector2& vec) const;

        static Vector2 lerp(const Vector2& start, const Vector2& end, float t);

        static float angleBetween(const Vector2& a, const Vector2& b);

        bool isEnterViewAngle(const Vector2& direction, const Vector2& position, float angle);

        float x;
        float y;
    };

    std::ostream& operator<<(std::ostream& stream, const Vector2& vector);
    Vector2 operator + (const Vector2& v1, const Vector2& v2);
    Vector2 operator - (const Vector2& v1, const Vector2& v2);
    Vector2 operator*(const Vector2& v1, const Vector2& v2);
    Vector2 operator/(const Vector2& v1, const Vector2& v2);
    Vector2 operator*(const Vector2& v1, float num);
    Vector2 operator/(const Vector2& v1, float num);
}