#pragma once
#include <cmath>
#include <map>
#define PI 3.141592653589793223846
#include <SFML/Graphics.hpp>

float getEaseNumber(float start, float end, float easingT);

std::pair<std::pair<float, float>, std::pair<float, float>> getCoordinates(sf::Vector2f& start, sf::Vector2f& end);

float getT(float duration, sf::Clock& clock);

float easeOutBounce(float t);

sf::Vector2f animateLinearVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateSineInVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateSineOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateSineInOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateQuadInVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateQuadOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateQuadInOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateCubicInVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateCubicOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateCubicInOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateQuartInVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateQuartOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateQuartInOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateQuintInVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateQuintOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateQuintInOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateExponentialInVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateExponentialOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateExponentialInOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateCircularInVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateCircularOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateCircularInOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateBackInVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateBackOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateBackInOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateBounceInVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateBounceOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateBounceInOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);