#include "Sheep.h"

void Sheep::sound()
{
    std::cout << "Meeeeee Meeeeee ";
}

int Sheep::giveMilk()
{
    return (rand() % 10) + 1;
}

int Sheep::giveBirth()
{
    return (rand() % 4) + 1;
}