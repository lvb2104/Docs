#include "Cow.h"

void Cow::sound()
{
    std::cout << "Mooooo Mooooo ";
}

int Cow::giveMilk()
{
    return (rand() % 20) + 1;
}

int Cow::giveBirth()
{
    return (rand() % 2) + 1;
}
