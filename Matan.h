#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>

int getRandomNumber(int min, int max);

float sinWave(float x, float a, float b, float c);

sf::Vector2f circleMoving(sf::Vector2f center, float velocity, float radius, float time);

