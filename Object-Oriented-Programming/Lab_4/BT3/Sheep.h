#include "LiveStock.h"

class Sheep : public LiveStock
{
public:
    int giveMilk();
    int giveBirth();
    void sound();
};