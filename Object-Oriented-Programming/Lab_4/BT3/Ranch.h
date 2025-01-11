#ifndef RANCH_H
#define RANCH_H

#include "LiveStock.h"
#include "Cow.h"
#include "Sheep.h"
#include "Goat.h"

class Ranch
{
private:
    int amountCow;
    int amountSheep;
    int amountGoat;
    Cow *cow;
    Sheep *sheep;
    Goat *goat;
    int amountMilk;

public:
    void init();
    void absentHost();
    void afterBreedingSeason();
    void afterMilkingSeason();
};

#endif