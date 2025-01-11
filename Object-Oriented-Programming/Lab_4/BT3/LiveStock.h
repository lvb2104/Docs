#ifndef LIVESTOCK_H
#define LIVESTOCK_H

#include <bits/stdc++.h>

class LiveStock
{
public:
    virtual int giveMilk() = 0;
    virtual int giveBirth() = 0;
    virtual void sound() = 0;
};

#endif