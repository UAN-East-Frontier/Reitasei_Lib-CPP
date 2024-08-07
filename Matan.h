#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <cmath>

int getRandomNumber(int min, int max);

float sinWave(float x, float a, float b, float c);

sf::Vector2f circleMoving(sf::Vector2f center, float velocity, float radius, float time);

sf::Vector2f curveBezier(float t, sf::Vector2f p0, sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3);

sf::Vector2f circleVector(sf::Vector2f center, float velocity, float radius, float time);

float getPositionAngleRotate(const sf::Vector2f& obj, const sf::Vector2f& target);

float getDirectionAngleRotate(const sf::Vector2f& direction);