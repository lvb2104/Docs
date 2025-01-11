#include "Ranch.h"

void Ranch::init()
{
    srand(time(NULL));
    std::cout << "Enter the number of cows: ";
    std::cin >> amountCow;
    std::cout << "Enter the number of sheeps: ";
    std::cin >> amountSheep;
    std::cout << "Enter the number of goats: ";
    std::cin >> amountGoat;
    cow = new Cow[amountCow];
    sheep = new Sheep[amountSheep];
    goat = new Goat[amountGoat];
    amountMilk = 0;
}

void Ranch::absentHost()
{
    std::cout << "--- The host is absent !!! ---" << std::endl;
    std::cout << "The animals are starving !!!" << std::endl;
    std::cout << "Some sounds are coming from the farm: " << std::endl;
    cow[0].sound();
    sheep[0].sound();
    goat[0].sound();
    std::cout << std::endl;
}

void Ranch::afterBreedingSeason()
{
    std::cout << "--- The breeding season is over !!! ---" << std::endl;
    std::cout << "The animals are happy !!!" << std::endl;
    int amountBabyCow = 0;
    for (int i = 0; i < amountCow; i++)
    {
        amountBabyCow += cow[i].giveBirth();
    }
    this->amountCow += amountBabyCow;
    int amountBabySheep = 0;
    for (int i = 0; i < amountSheep; i++)
    {
        amountBabySheep += sheep[i].giveBirth();
    }
    this->amountSheep += amountBabySheep;
    int amountBabyGoat = 0;
    for (int i = 0; i < amountGoat; i++)
    {
        amountBabyGoat += goat[i].giveBirth();
    }
    this->amountGoat += amountBabyGoat;
    std::cout << "The number of cows: " << amountCow << std::endl;
    std::cout << "The number of sheeps: " << amountSheep << std::endl;
    std::cout << "The number of goats: " << amountGoat << std::endl;
}

void Ranch::afterMilkingSeason()
{
    std::cout << "--- The milking season is over !!! ---" << std::endl;
    std::cout << "The animals are happy !!!" << std::endl;
    for (int i = 0; i < amountCow; i++)
    {
        this->amountMilk += (rand() % 20) + 1;
    }
    for (int i = 0; i < amountGoat; i++)
    {
        this->amountMilk += (rand() % 5) + 1;
    }
    for (int i = 0; i < amountSheep; i++)
    {
        this->amountMilk += (rand() % 10) + 1;
    }
    std::cout << "The amount of milk is: " << this->amountMilk << std::endl;
}
