#include <iostream>
#include <chrono>

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