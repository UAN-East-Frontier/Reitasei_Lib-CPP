#include "Matan.h"

int getRandomNumber(int min, int max)
{
    if (min > max)
    {
        std::cout << "Warning min greater max!" << std::endl;
        int temp = max;
        max = min;
        min = temp;
    }
    std::srand(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    return min + rand() % (max - min + 1); //+1 need because include max number in range
}

float sinWave(float x, float a, float b, float c) {
    return a * sin(b * x + c);
}

sf::Vector2f circleMoving(sf::Vector2f center, float velocity, float radius, float time) { //Формула №6
    float x = center.x + radius * cos(velocity * time);
    float y = center.y + radius * sin(velocity * time);
    return sf::Vector2f(x, y);
}

