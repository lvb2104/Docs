#ifndef MUOI_H
#define MUOI_H

#include "ConVat.h"

class Muoi : public ConVat
{
private:

public:
    // constructor
    Muoi() : ConVat() {};
    Muoi(string l, int* tg) : ConVat(l) 
    {
        tg = new int[4];
    };

    // method
    bool tuanTheoQuiLuat()
    {
        if (thoiGian[0] < 1 && thoiGian[0] > 3) return false;
        if (thoiGian[1] < 4 && thoiGian[1] > 10) return false;
        if (thoiGian[2] < 2 && thoiGian[2] > 3) return false;
        if (thoiGian[3] < 5 && thoiGian[3] > 8) return false;
        return true;
    }
};

#endif