#include "Goat.h"

void Goat::sound()
{
    std::cout << "Beeeeee Beeeeee ";
}

int Goat::giveMilk()
{
    return (rand() % 5) + 1;
}

int Goat::giveBirth()
{
    return (rand() % 3) + 1;
}