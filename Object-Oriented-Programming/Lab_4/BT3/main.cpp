#include "Ranch.h"

int main()
{
    Ranch *ranch = new Ranch();
    ranch->init();
    ranch->absentHost();
    ranch->afterBreedingSeason();
    ranch->afterMilkingSeason();
    delete ranch;
    return 0;
}