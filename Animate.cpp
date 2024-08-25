#include "Animate.h"

float getEaseNumber(float start, float end, float easingT) {
    return start + (end - start) * easingT;
}

std::pair<std::pair<float, float>, std::pair<float, float>> getCoordinates(sf::Vector2f& start, sf::Vector2f& end) {
    float startX = start.x;
    float startY = start.y;
    float endX = end.x;
    float endY = end.y;
    return std::make_pair(std::make_pair(startX, startY), std::make_pair(endX, endY));
}

float getT(float duration, sf::Clock& clock) {
    float time = clock.getElapsedTime().asSeconds();
    if (time <= duration)
        return time / duration;
    return 1;
}

sf::Vector2f animateLinearVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock)
{
    float t = getT(duration, clock);
    auto coords = getCoordinates(startPoint, endPoint);
    float x = getEaseNumber(coords.first.first, coords.second.first, t);
    float y = getEaseNumber(coords.first.second, coords.second.second, t);
    return sf::Vector2f(x, y);
}

sf::Vector2f animateSineInVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock) {
    float t = getT(duration, clock);
    auto coords = getCoordinates(startPoint, endPoint);
    float x = getEaseNumber(coords.first.first, coords.second.first, 1 - std::cos((t * PI) / 2));
    float y = getEaseNumber(coords.first.second, coords.second.second, 1 - std::cos((t * PI) / 2));
    return sf::Vector2f(x, y);
}

sf::Vector2f animateSineOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock) {
    float t = getT(duration, clock);
    auto coords = getCoordinates(startPoint, endPoint);
    float x = getEaseNumber(coords.first.first, coords.second.first, std::sin((t * PI) / 2));
    float y = getEaseNumber(coords.first.second, coords.second.second, std::sin((t * PI) / 2));
    return sf::Vector2f(x, y);
}

sf::Vector2f animateSineInOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock) {
    float t = getT(duration, clock);
    auto coords = getCoordinates(startPoint, endPoint);
    float x = getEaseNumber(coords.first.first, coords.second.first, -(std::cos(PI * t) - 1) / 2);
    float y = getEaseNumber(coords.first.second, coords.second.second, -(std::cos(PI * t) - 1) / 2);
    return sf::Vector2f(x, y);
}

sf::Vector2f animateQuadInVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock) {
    float t = getT(duration, clock);
    auto coords = getCoordinates(startPoint, endPoint);
    float x = getEaseNumber(coords.first.first, coords.second.first, t * t);
    float y = getEaseNumber(coords.first.second, coords.second.second, t * t);
    return sf::Vector2f(x, y);
}

sf::Vector2f animateQuadOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock) {
    float t = getT(duration, clock);
    auto coords = getCoordinates(startPoint, endPoint);
    float x = getEaseNumber(coords.first.first, coords.second.first, t * (2 - t));
    float y = getEaseNumber(coords.first.second, coords.second.second, t * (2 - t));
    return sf::Vector2f(x, y);
}

sf::Vector2f animateQuadInOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock) {
    float t = getT(duration, clock);
    auto coords = getCoordinates(startPoint, endPoint);
    if (t < 0.5f) {
        float x = getEaseNumber(coords.first.first, coords.second.first, t * (2 - t));
        float y = getEaseNumber(coords.first.second, coords.second.second, t * (2 - t));
        return sf::Vector2f(x, y);
    }
    float x = getEaseNumber(coords.first.first, coords.second.first, -1 + (4 - 2 * t) * t);
    float y = getEaseNumber(coords.first.second, coords.second.second, -1 + (4 - 2 * t) * t);
    return sf::Vector2f(x, y);
}

sf::Vector2f animateCubicInVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock) {
    float t = getT(duration, clock);
    auto coords = getCoordinates(startPoint, endPoint);
    float x = getEaseNumber(coords.first.first, coords.second.first, t * t * t);
    float y = getEaseNumber(coords.first.second, coords.second.second, t * t * t);
    return sf::Vector2f(x, y);
}

sf::Vector2f animateCubicOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock) {
    float t = getT(duration, clock);
    auto coords = getCoordinates(startPoint, endPoint);
    float x = getEaseNumber(coords.first.first, coords.second.first, (t - 1) * (t - 1) * (t - 1) + 1);
    float y = getEaseNumber(coords.first.second, coords.second.second, (t - 1) * (t - 1) * (t - 1) + 1);
    return sf::Vector2f(x, y);
}

sf::Vector2f animateCubicInOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock) {
    float t = getT(duration, clock);
    auto coords = getCoordinates(startPoint, endPoint);
    if (t < 0.5f) {
        float x = getEaseNumber(coords.first.first, coords.second.first, 4 * t * t * t);
        float y = getEaseNumber(coords.first.second, coords.second.second, 4 * t * t * t);
        return sf::Vector2f(x, y);
    }
    float x = getEaseNumber(coords.first.first, coords.second.first, (t - 1) * (2 * t - 2) * (2 * t - 2) + 1);
    float y = getEaseNumber(coords.first.second, coords.second.second, (t - 1) * (2 * t - 2) * (2 * t - 2) + 1);
    return sf::Vector2f(x, y);
}

sf::Vector2f animateQuartInVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock) {
    float t = getT(duration, clock);
    auto coords = getCoordinates(startPoint, endPoint);
    float x = getEaseNumber(coords.first.first, coords.second.first, t * t * t * t);
    float y = getEaseNumber(coords.first.second, coords.second.second, t * t * t * t);
    return sf::Vector2f(x, y);
}

sf::Vector2f animateQuartOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock) {
    float t = getT(duration, clock);
    auto coords = getCoordinates(startPoint, endPoint);
    float x = getEaseNumber(coords.first.first, coords.second.first, 1 - (t - 1) * (t - 1) * (t - 1) * (t - 1));
    float y = getEaseNumber(coords.first.second, coords.second.second, 1 - (t - 1) * (t - 1) * (t - 1) * (t - 1));
    return sf::Vector2f(x, y);
}

sf::Vector2f animateQuartInOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock) {
    float t = getT(duration, clock);
    auto coords = getCoordinates(startPoint, endPoint);
    if (t < 0.5f) {
        float x = getEaseNumber(coords.first.first, coords.second.first, 8 * t * t * t * t);
        float y = getEaseNumber(coords.first.second, coords.second.second, 8 * t * t * t * t);
        return sf::Vector2f(x, y);
    }
    float x = getEaseNumber(coords.first.first, coords.second.first, 1 - 8 * (t - 1) * (t - 1) * (t - 1) * (t - 1));
    float y = getEaseNumber(coords.first.second, coords.second.second, 1 - 8 * (t - 1) * (t - 1) * (t - 1) * (t - 1));
    return sf::Vector2f(x, y);
}

sf::Vector2f animateQuintInVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock) {
    float t = getT(duration, clock);
    auto coords = getCoordinates(startPoint, endPoint);
    float x = getEaseNumber(coords.first.first, coords.second.first, t * t * t * t * t);
    float y = getEaseNumber(coords.first.second, coords.second.second, t * t * t * t * t);
    return sf::Vector2f(x, y);
}

sf::Vector2f animateQuintOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock) {
    float t = getT(duration, clock);
    auto coords = getCoordinates(startPoint, endPoint);
    float x = getEaseNumber(coords.first.first, coords.second.first, 1 + (t - 1) * (t - 1) * (t - 1) * (t - 1) * (t - 1));
    float y = getEaseNumber(coords.first.second, coords.second.second, 1 + (t - 1) * (t - 1) * (t - 1) * (t - 1) * (t - 1));
    return sf::Vector2f(x, y);
}

sf::Vector2f animateQuintInOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock) {
    float t = getT(duration, clock);
    auto coords = getCoordinates(startPoint, endPoint);
    if (t < 0.5f) {
        float x = getEaseNumber(coords.first.first, coords.second.first, 16 * t * t * t * t * t);
        float y = getEaseNumber(coords.first.second, coords.second.second, 16 * t * t * t * t * t);
        return sf::Vector2f(x, y);
    }
    float x = getEaseNumber(coords.first.first, coords.second.first, 1 + 16 * (t - 1) * (t - 1) * (t - 1) * (t - 1) * (t - 1));
    float y = getEaseNumber(coords.first.second, coords.second.second, 1 + 16 * (t - 1) * (t - 1) * (t - 1) * (t - 1) * (t - 1));
    return sf::Vector2f(x, y);
}

sf::Vector2f animateExponentialInVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock) {
    float t = getT(duration, clock);
    auto coords = getCoordinates(startPoint, endPoint);
    float x = getEaseNumber(coords.first.first, coords.second.first,  pow(2, 10 * (t - 1)));
    float y = getEaseNumber(coords.first.second, coords.second.second, pow(2, 10 * (t - 1)));
    return sf::Vector2f(x, y);
}

sf::Vector2f animateExponentialOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock) {
    float t = getT(duration, clock);
    auto coords = getCoordinates(startPoint, endPoint);
    float x = getEaseNumber(coords.first.first, coords.second.first, 1 - pow(2, -10 * t));
    float y = getEaseNumber(coords.first.second, coords.second.second, 1 - pow(2, -10 * t));
    return sf::Vector2f(x, y);
}

sf::Vector2f animateExponentialInOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock) {
    float t = getT(duration, clock);
    auto coords = getCoordinates(startPoint, endPoint);
    if (t < 0.5f) {
        float x = getEaseNumber(coords.first.first, coords.second.first, pow(2, 20 * t - 10) / 2);
        float y = getEaseNumber(coords.first.second, coords.second.second, pow(2, 20 * t - 10) / 2);
        return sf::Vector2f(x, y);
    }
    float x = getEaseNumber(coords.first.first, coords.second.first, (2 - pow(2, -20 * t + 10)) / 2);
    float y = getEaseNumber(coords.first.second, coords.second.second, (2 - pow(2, -20 * t + 10)) / 2);
    return sf::Vector2f(x, y);
}

sf::Vector2f animateCircularInVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock) {
    float t = getT(duration, clock);
    auto coords = getCoordinates(startPoint, endPoint);
    float x = getEaseNumber(coords.first.first, coords.second.first, 1 - sqrt(1 - t * t));
    float y = getEaseNumber(coords.first.second, coords.second.second, 1 - sqrt(1 - t * t));
    return sf::Vector2f(x, y);
}

sf::Vector2f animateCircularOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock) {
    float t = getT(duration, clock);
    auto coords = getCoordinates(startPoint, endPoint);
    float x = getEaseNumber(coords.first.first, coords.second.first, sqrt(1 - (t - 1) * (t - 1)));
    float y = getEaseNumber(coords.first.second, coords.second.second, sqrt(1 - (t - 1) * (t - 1)));
    return sf::Vector2f(x, y);
}

sf::Vector2f animateCircularInOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock) {
    float t = getT(duration, clock);
    auto coords = getCoordinates(startPoint, endPoint);
    if (t < 0.5f) {
        float x = getEaseNumber(coords.first.first, coords.second.first, (1 - sqrt(1 - 4 * t * t)) / 2);
        float y = getEaseNumber(coords.first.second, coords.second.second, (1 - sqrt(1 - 4 * t * t)) / 2);
        return sf::Vector2f(x, y);
    }
    float x = getEaseNumber(coords.first.first, coords.second.first, (sqrt(1 - (2 * t - 2) * (2 * t - 2)) + 1) / 2);
    float y = getEaseNumber(coords.first.second, coords.second.second, (sqrt(1 - (2 * t - 2) * (2 * t - 2)) + 1) / 2);
    return sf::Vector2f(x, y);
}

sf::Vector2f animateBackInVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock) {
    float t = getT(duration, clock);
    float c1 = 1.70158;
    float c3 = c1 + 1;
    auto coords = getCoordinates(startPoint, endPoint);
    float x = getEaseNumber(coords.first.first, coords.second.first, c3 * t * t * t - c1 * t * t);
    float y = getEaseNumber(coords.first.second, coords.second.second, c3 * t * t * t - c1 * t * t);
    return sf::Vector2f(x, y);
}

sf::Vector2f animateBackOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock) {
    float t = getT(duration, clock);
    float c1 = 1.70158;
    float c3 = c1 + 1;
    auto coords = getCoordinates(startPoint, endPoint);
    float x = getEaseNumber(coords.first.first, coords.second.first, 1 + c3 * (t - 1) * (t - 1) * (t - 1) + c1 * (t - 1) * (t - 1));
    float y = getEaseNumber(coords.first.second, coords.second.second, 1 + c3 * (t - 1) * (t - 1) * (t - 1) + c1 * (t - 1) * (t - 1));
    return sf::Vector2f(x, y);
}

sf::Vector2f animateBackInOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock) {
    float t = getT(duration, clock);
    float c1 = 1.70158;
    float c2 = c1 + 1;
    auto coords = getCoordinates(startPoint, endPoint);
    if (t < 0.5f) {
        float x = getEaseNumber(coords.first.first, coords.second.first, ((2 * t) * (2 * t) * ((c2 + 1) * 2 * t - c2)) / 2);
        float y = getEaseNumber(coords.first.second, coords.second.second, ((2 * t) * (2 * t) * ((c2 + 1) * 2 * t - c2)) / 2);
        return sf::Vector2f(x, y);
    }
    float x = getEaseNumber(coords.first.first, coords.second.first, ((2 * t - 2) * (2 * t - 2) * ((c2 + 1) * (t * 2 - 2) + c2) + 2) / 2);
    float y = getEaseNumber(coords.first.second, coords.second.second, ((2 * t - 2) * (2 * t - 2) * ((c2 + 1) * (t * 2 - 2) + c2) + 2) / 2);
    return sf::Vector2f(x, y);
}

float easeOutBounce(float t) {
    float n1 = 7.5625;
    float d1 = 2.75;
    if (t < 1 / d1)
        return n1 * t * t;
    else if (t > 2 / d1) return n1 * (t - 1.5 / d1) * (t - 1.5 / d1) + 0.75;
    else if (t < 2.5 / d1) return n1 * (t - 2.25 / d1) * (t - 2.25 / d1) + 0.9375;
    else return n1 * (t - 2.625 / d1) * (t - 2.625 / d1) + 0.984375;
}

sf::Vector2f animateBounceInVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock) {
    float t = getT(duration, clock);
    auto coords = getCoordinates(startPoint, endPoint);
    float x = getEaseNumber(coords.first.first, coords.second.first, 1 - easeOutBounce(1 - t));
    float y = getEaseNumber(coords.first.second, coords.second.second, 1 - easeOutBounce(1 - t));
    return sf::Vector2f(x, y);
}

sf::Vector2f animateBounceOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock) {
    float t = getT(duration, clock);
    auto coords = getCoordinates(startPoint, endPoint);
    float x = getEaseNumber(coords.first.first, coords.second.first, easeOutBounce(t));
    float y = getEaseNumber(coords.first.second, coords.second.second, 1 - easeOutBounce(t));
    return sf::Vector2f(x, y);
}

sf::Vector2f animateBounceInOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock) {
    float t = getT(duration, clock);
    float c1 = 1.70158;
    float c2 = c1 + 1;
    auto coords = getCoordinates(startPoint, endPoint);
    if (t < 0.5f) {
        float x = getEaseNumber(coords.first.first, coords.second.first, (1 - easeOutBounce(1 - 2 * t)) / 2);
        float y = getEaseNumber(coords.first.second, coords.second.second, (1 - easeOutBounce(1 - 2 * t)) / 2);
        return sf::Vector2f(x, y);
    }
    float x = getEaseNumber(coords.first.first, coords.second.first, (1 + easeOutBounce(2 * t - 1)) / 2);
    float y = getEaseNumber(coords.first.second, coords.second.second, (1 + easeOutBounce(2 * t - 1)) / 2);
    return sf::Vector2f(x, y);
}

float animateLinearFloat(float startPoint, float endPoint, float duration, sf::Clock& clock)
{
    float t = getT(duration, clock);
    float x = getEaseNumber(startPoint, endPoint, t);
    return x;
}

float animateSineInFloat(float startPoint, float endPoint, float duration, sf::Clock& clock)
{
    float t = getT(duration, clock);
    float x = getEaseNumber(startPoint, endPoint, 1 - std::cos((t * PI) / 2));
    return x;
}

float animateSineOutFloat(float startPoint, float endPoint, float duration, sf::Clock& clock)
{
    float t = getT(duration, clock);
    float x = getEaseNumber(startPoint, endPoint, std::sin((t * PI) / 2));
    return x;
}

float animateSineInOutFloat(float startPoint, float endPoint, float duration, sf::Clock& clock)
{
    float t = getT(duration, clock);
    float x = getEaseNumber(startPoint, endPoint, -(std::cos(PI * t) - 1) / 2);
    return x;
}

float animateQuadInFloat(float startPoint, float endPoint, float duration, sf::Clock& clock)
{
    float t = getT(duration, clock);
    float x = getEaseNumber(startPoint, endPoint, t * t);
    return x;
}

float animateQuadOutFloat(float startPoint, float endPoint, float duration, sf::Clock& clock)
{
    float t = getT(duration, clock);
    float x = getEaseNumber(startPoint, endPoint, t * (2 - t));
    return x;
}

float animateQuadInOutFloat(float startPoint, float endPoint, float duration, sf::Clock& clock)
{
    float t = getT(duration, clock);
    if (t < 0.5f) {
        float x = getEaseNumber(startPoint, endPoint, t * (2 - t));
        return x;
    }
    float x = getEaseNumber(startPoint, endPoint, -1 + (4 - 2 * t) * t);
    return x;
}

float animateCubicInFloat(float startPoint, float endPoint, float duration, sf::Clock& clock)
{
    float t = getT(duration, clock);
    float x = getEaseNumber(startPoint, endPoint, t * t * t);
    return x;
}

float animateCubicOutFloat(float startPoint, float endPoint, float duration, sf::Clock& clock)
{
    float t = getT(duration, clock);
    float x = getEaseNumber(startPoint, endPoint, (t - 1) * (t - 1) * (t - 1) + 1);
    return x;
}

float animateCubicInOutFloat(float startPoint, float endPoint, float duration, sf::Clock& clock)
{
    float t = getT(duration, clock);
    if (t < 0.5f) {
        float x = getEaseNumber(startPoint, endPoint, 4 * t * t * t);
        return x;
    }
    float x = getEaseNumber(startPoint, endPoint, (t - 1) * (2 * t - 2) * (2 * t - 2) + 1);
    return x;
}

float animateQuartInFloat(float startPoint, float endPoint, float duration, sf::Clock& clock)
{
    float t = getT(duration, clock);
    float x = getEaseNumber(startPoint, endPoint, t * t * t * t);
    return x;
}

float animateQuartOutFloat(float startPoint, float endPoint, float duration, sf::Clock& clock)
{
    float t = getT(duration, clock);
    float x = getEaseNumber(startPoint, endPoint, 1 - (t - 1) * (t - 1) * (t - 1) * (t - 1));
    return x;
}

float animateQuartInOutFloat(float startPoint, float endPoint, float duration, sf::Clock& clock)
{
    float t = getT(duration, clock);
    if (t < 0.5f) {
        float x = getEaseNumber(startPoint, endPoint, 8 * t * t * t * t);
        return x;
    }
    float x = getEaseNumber(startPoint, endPoint, 1 - 8 * (t - 1) * (t - 1) * (t - 1) * (t - 1));
    return x;
}

float animateQuintInFloat(float startPoint, float endPoint, float duration, sf::Clock& clock)
{
    float t = getT(duration, clock);
    float x = getEaseNumber(startPoint, endPoint, t * t * t * t * t);
    return x;
}

float animateQuintOutFloat(float startPoint, float endPoint, float duration, sf::Clock& clock)
{
    float t = getT(duration, clock);
    float x = getEaseNumber(startPoint, endPoint, 1 + (t - 1) * (t - 1) * (t - 1) * (t - 1) * (t - 1));
    return x;
}

float animateQuintInOutFloat(float startPoint, float endPoint, float duration, sf::Clock& clock)
{
    float t = getT(duration, clock);
    if (t < 0.5f) {
        float x = getEaseNumber(startPoint, endPoint, 16 * t * t * t * t * t);
        return x;
    }
    float x = getEaseNumber(startPoint, endPoint, 1 + 16 * (t - 1) * (t - 1) * (t - 1) * (t - 1) * (t - 1));
    return x;
}

float animateExponentialInFloat(float startPoint, float endPoint, float duration, sf::Clock& clock)
{
    float t = getT(duration, clock);
    float x = getEaseNumber(startPoint, endPoint, pow(2, 10 * (t - 1)));
    return x;
}

float animateExponentialOutFloat(float startPoint, float endPoint, float duration, sf::Clock& clock)
{
    float t = getT(duration, clock);
    float x = getEaseNumber(startPoint, endPoint, 1 - pow(2, -10 * t));
    return x;
}

float animateExponentialInOutFloat(float startPoint, float endPoint, float duration, sf::Clock& clock)
{
    float t = getT(duration, clock);
    if (t < 0.5f) {
        float x = getEaseNumber(startPoint, endPoint, pow(2, 20 * t - 10) / 2);
        return x;
    }
    float x = getEaseNumber(startPoint, endPoint, (2 - pow(2, -20 * t + 10)) / 2);
    return x;
}

float animateCircularInFloat(float startPoint, float endPoint, float duration, sf::Clock& clock)
{
    float t = getT(duration, clock);
    float x = getEaseNumber(startPoint, endPoint, 1 - sqrt(1 - t * t));
    return x;
}

float animateCircularOutFloat(float startPoint, float endPoint, float duration, sf::Clock& clock)
{
    float t = getT(duration, clock);
    float x = getEaseNumber(startPoint, endPoint, sqrt(1 - (t - 1) * (t - 1)));
    return x;
}

float animateCircularInOutFloat(float startPoint, float endPoint, float duration, sf::Clock& clock)
{
    float t = getT(duration, clock);
    if (t < 0.5f) {
        float x = getEaseNumber(startPoint, endPoint, (1 - sqrt(1 - 4 * t * t)) / 2);
        return x;
    }
    float x = getEaseNumber(startPoint, endPoint, (sqrt(1 - (2 * t - 2) * (2 * t - 2)) + 1) / 2);
    return x;
}

float animateBackInFloat(float startPoint, float endPoint, float duration, sf::Clock& clock)
{
    float t = getT(duration, clock);
    float c1 = 1.70158;
    float c3 = c1 + 1;
    float x = getEaseNumber(startPoint, endPoint, c3 * t * t * t - c1 * t * t);
    return x;
}

float animateBackOutFloat(float startPoint, float endPoint, float duration, sf::Clock& clock)
{
    float t = getT(duration, clock);
    float c1 = 1.70158;
    float c3 = c1 + 1;
    float x = getEaseNumber(startPoint, endPoint, 1 + c3 * (t - 1) * (t - 1) * (t - 1) + c1 * (t - 1) * (t - 1));
    return x;
}

float animateBackInOutFloat(float startPoint, float endPoint, float duration, sf::Clock& clock)
{
    float t = getT(duration, clock);
    float c1 = 1.70158;
    float c2 = c1 + 1;
    if (t < 0.5f) {
        float x = getEaseNumber(startPoint, endPoint, ((2 * t) * (2 * t) * ((c2 + 1) * 2 * t - c2)) / 2);
        return  x;
    }
    float x = getEaseNumber(startPoint, endPoint, ((2 * t - 2) * (2 * t - 2) * ((c2 + 1) * (t * 2 - 2) + c2) + 2) / 2);
    return x;
}

float animateBounceInFloat(float startPoint, float endPoint, float duration, sf::Clock& clock)
{
    float t = getT(duration, clock);
    float x = getEaseNumber(startPoint, endPoint, 1 - easeOutBounce(1 - t));
    return x;
}

float animateBounceOutFloat(float startPoint, float endPoint, float duration, sf::Clock& clock)
{
    float t = getT(duration, clock);
    float x = getEaseNumber(startPoint, endPoint, easeOutBounce(t));
    return x;
}

float animateBounceInOutFloat(float startPoint, float endPoint, float duration, sf::Clock& clock)
{
    float t = getT(duration, clock);
    if (t < 0.5f) {
        float x = getEaseNumber(startPoint, endPoint, (1 - easeOutBounce(1 - 2 * t)) / 2);
        return x;
    }
    float x = getEaseNumber(startPoint, endPoint, (1 + easeOutBounce(2 * t - 1)) / 2);
    return x;
}

bool AnimateText::startAnimate(sf::Text& text, const std::string& str, float durtaionWaitNextSymbol) {
    if (str.size() == 0)
        return true;
    else if (index == 0) {
        text.setString("");
    }
    if (clock.getElapsedTime().asSeconds() >= durtaionWaitNextSymbol)
    {
        if (index < str.size()) {
            std::string txt = text.getString();
            txt += str[index];
            text.setString(txt);
            index++;
            clock.restart();
        }
        else return true;
    }
    return false;
}

void AnimateText::nextRowString(std::string& word, int& row) {
    std::string currentTextRow = bufferText[row].getString();
    int index = currentTextRow.find(word);
    if (index != std::string::npos) {
        auto iter = currentTextRow.begin() + index;
        std::string lastWord = currentTextRow.substr(index);
        currentTextRow.erase(iter, currentTextRow.end());
        bufferText[row].setString(currentTextRow);
        sf::Text newTextRow = bufferText[row];
        newTextRow.setString(lastWord);
        newTextRow.setPosition(sf::Vector2f(newTextRow.getPosition().x, newTextRow.getPosition().y + newTextRow.getLocalBounds().height));
        bufferText.push_back(newTextRow);
        row = bufferText.size() - 1;
        word = lastWord;
    }
}

bool AnimateText::animateSizeText(const sf::Text& textParametr, const std::string& stroka, float duration) {
    if (symbol.getFont() == nullptr) { //Start
        symbol = textParametr;
        symbol.setString("");
        bufferText.push_back(symbol);
        shape.setPosition(symbol.getPosition());
    }
    else {
        symbol.setCharacterSize(textParametr.getCharacterSize());
    }
    if (index >= stroka.size()) {
        symbol.setString("");
        return true;
    }
    int row = bufferText.size() - 1;
    int sumHeight = 0;
    for (size_t i = 0; i < bufferText.size(); i++)
    {
        sumHeight += bufferText[row].getLocalBounds().height;
        if (sumHeight > height)
            return true;
    }
    float end = symbol.getCharacterSize();
    float start = symbol.getCharacterSize() + 10;
    sf::Vector2f position = sf::Vector2f(bufferText[row].getPosition().x + bufferText[row].getLocalBounds().width, bufferText[row].getPosition().y - bufferText[row].getLocalBounds().height);
    auto pos2 = sf::Vector2f(bufferText[row].getPosition().x + bufferText[row].getLocalBounds().width, bufferText[row].getPosition().y);
    auto vec = animateLinearVector(position, pos2, duration, clock);
    symbol.setPosition(vec);
    symbol.setCharacterSize(animateLinearFloat(start, end, duration, clock));
    symbol.setString(stroka[index]);
    start = 0;
    end = 255;
    sf::Color color = symbol.getFillColor();
    symbol.setFillColor(sf::Color(color.r, color.g, color.b, animateLinearFloat(start, end, duration, clock)));
    if (clock.getElapsedTime().asSeconds() > duration) {
        std::string result = bufferText[row].getString() + stroka[index];
        if (stroka[index] != ' ') {
            word += stroka[index];
            std::string NextSymbolResult = result + stroka[index];
            bufferText[row].setString(NextSymbolResult);
            if (bufferText[row].getLocalBounds().width > width) {
                bufferText[row].setString(result);
                nextRowString(word, row);
            }
            else  bufferText[row].setString(result);
        }
        else {
            std::string NextSymbolResult = bufferText[row].getString() + stroka[index];
            bufferText[row].setString(NextSymbolResult);
            if (bufferText[row].getLocalBounds().width > width) {
                bufferText[row].setString(result);
                sf::Text newTextRow = bufferText[row];
                newTextRow.setString("");
                newTextRow.setPosition(sf::Vector2f(bufferText[row].getPosition().x, bufferText[row].getPosition().y + bufferText[row].getLocalBounds().height));
                bufferText.push_back(newTextRow);
            }
            else  bufferText[row].setString(result);
            word = "";
        }
        index++;
        clock.restart();
    }
    return false;
}

void AnimateText::resetSizeText() {
    symbol.setString("");
    symbol = sf::Text();
    index = 0;
    clock.restart();
    word = "";
    bufferText.clear();
    isNotAnimateSymbol = true;
}

AnimateText::AnimateText(): width(0), height(0) {

}

AnimateText::AnimateText(int width, int height) {
    this->width = width;
    this->height = height;
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(sf::Color(255, 255, 255, 0));
    shape.setOutlineThickness(1);
    shape.setOutlineColor(sf::Color(sf::Color::Red));
}

void AnimateText::setWidth(int width) {
    this->width = width;
}
void AnimateText::setHeight(int height) {
    this->height = height;
}
int AnimateText::getWidth() {
    return width;
}
int AnimateText::getHeight() {
    return height;
}

void AnimateText::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (size_t i = 0; i < bufferText.size(); i++)
    {
        target.draw(bufferText[i], states);
    }

    if (symbol.getFont() != nullptr)
        target.draw(symbol, states);
}

void AnimateText::resetAnimate() {
    index = 0;
    clock.restart();
}

AnimateNumber::AnimateNumber(const TextLabel& txt) : label(txt) {
    label.text.setString("0");
}

AnimateNumber::AnimateNumber(const TextLabel& txt, float dur, int num) : label(txt), targetNumber(num), duration(dur) {
    label.text.setString("0");
}

AnimateNumber::AnimateNumber(const TextLabel& txt, const std::vector<std::string>& pathsTexture): label(txt)
{
    if (pathsTexture.size() < 10)
        throw new std::invalid_argument("Size array less 10");
    for (int i = 0; i < 10; i++)
    {
        auto texture = std::make_shared<sf::Texture>();
        if (!texture->loadFromFile(pathsTexture[i]))
            throw  std::invalid_argument("Texture invalid path " + std::to_string(i));
        texturesNumbers.push_back(texture);
        sf::Sprite sprite(*texturesNumbers[texturesNumbers.size() - 1]);
        numbers.push_back(sprite);
        spritesNumbers.push_back(numbers[i]);
    }
}

AnimateNumber::AnimateNumber(const TextLabel& txt, const std::vector<std::string>& pathsTexture, float dur, int num) : label(txt), targetNumber(num), duration(dur)
{
    if (pathsTexture.size() < 10)
        throw new std::invalid_argument("Size array less 10");
    for (int i = 0; i < 10; i++)
    {
        auto texture = std::make_shared<sf::Texture>();
        if (!texture->loadFromFile(pathsTexture[i]))
            throw  std::invalid_argument("Texture invalid path " + std::to_string(i));
        texturesNumbers.push_back(texture);
        sf::Sprite sprite(*texturesNumbers[texturesNumbers.size() - 1]);
        numbers.push_back(sprite);
        spritesNumbers.push_back(numbers[i]);
    }
}

void AnimateNumber::setNewNumberValue(int newValue) {
    targetNumber = newValue;
    clock.restart();
}

void AnimateNumber::updateNumberValue() {
    float T = getT(duration, clock);
    number = targetNumber * T;
    label.text.setString(std::to_string(number));
    
}

void AnimateNumber::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if (numbers.size() < 10)
    target.draw(label,states);
    else
    {
        auto str = (std::string)label.text.getString();
        for (size_t i = 0; i < str.size(); i++)
        {
                char symbol = str[i];
                int digit = symbol - '0';
                std::shared_ptr<sf::Sprite> sprite = std::make_shared<sf::Sprite>(spritesNumbers[digit]);
                sprite->setScale(scale);
                sf::Vector2f positionText = label.text.getPosition();
                sf::Vector2f positionNumber = sf::Vector2f(positionText.x + sprite->getTextureRect().width * i * sprite->getScale().x, positionText.y + sprite->getTextureRect().height * sprite->getScale().y);
                sprite->setPosition(positionNumber);
                target.draw(*sprite,states);    
        }
    }
}

void AnimateNumber::setPosition(const sf::Vector2f& pos) {
    label.text.setPosition(pos);
}


void AnimateNumber::setSpritesNumbers(const std::vector<std::string>& pathsTexture)
{
    if (pathsTexture.size() < 10)
        throw new std::invalid_argument("Size array less 10");
    for (int i = 0; i < 10; i++)
    {
        auto texture = std::make_shared<sf::Texture>();
        if (!texture->loadFromFile(pathsTexture[i]))
            throw  std::invalid_argument("Texture invalid path " + std::to_string(i));
       texturesNumbers.push_back(texture);
       sf::Sprite sprite(*texturesNumbers[texturesNumbers.size()-1]);
       numbers.push_back(sprite);
       spritesNumbers.push_back(numbers[i]);
    }
}

int AnimateNumber::getNumber()
{
    return number;
}

