#ifndef ECH_H
#define ECH_H

#include "ConVat.h"

class Ech : public ConVat
{
private:

public:
    // constructor
    Ech() : ConVat() {};
    Ech(string l, int* tg) : ConVat(l) 
    {
        tg = new int[5];
    };

    // method
    bool tuanTheoQuiLuat()
    {
        if (thoiGian[0] < 1 && thoiGian[0] > 3) return false;
        if (thoiGian[1] != 4) return false;
        if (thoiGian[2] < 6 && thoiGian[2] > 9) return false;
        if (thoiGian[3] < 1 && thoiGian[3] > 4) return false;
        if (thoiGian[4] < 2 && thoiGian[4] > 4) return false;
        return true;
    }
};

#endif