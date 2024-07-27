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



