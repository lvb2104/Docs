#include "LiveStock.h"

class Cow : public LiveStock
{
public:
    int giveMilk();
    int giveBirth();
    void sound();
};