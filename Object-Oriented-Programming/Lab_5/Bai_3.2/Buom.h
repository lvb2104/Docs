#ifndef BUOM_H
#define BUOM_H

#include "ConVat.h"

class Buom : public ConVat
{
private:

public:
    // constructor
    Buom() : ConVat() {};
    Buom(string l, int* tg) : ConVat(l) 
    {
        tg = new int[4];
    };

    // method
    bool tuanTheoQuiLuat()
    {
        if (thoiGian[0] < 3 && thoiGian[0] > 8) return false;
        if (thoiGian[1] < 15 && thoiGian[1] > 16) return false;
        if (thoiGian[2] != 10) return false;
        if (thoiGian[3] < 2 && thoiGian[3] > 3) return false;
        return true;
    }
};

#endif