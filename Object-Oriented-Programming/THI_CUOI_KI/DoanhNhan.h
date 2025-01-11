#ifndef DOANHNHAN_H
#define DOANHNHAN_H

#include <bits/stdc++.h>
#include "People.h"
using namespace std;

class DoanhNhan : public People
{
private:
    float taiSan;
public:
    DoanhNhan(int type, string ten, int tuoi, string sdt, float taiSan) : People(type, ten, tuoi, sdt)
    {
        this->taiSan = taiSan;
        if (taiSan > 5)
        {
            this->cachChet = "nang";
        }
        else if (taiSan > 3 && taiSan <= 5)
        {
            this->cachChet = "binh thuong";
        }
        else
        {
            this->cachChet = "nhe";
        }
    }
    float getTaiSan()
    {
        return this->taiSan;
    }
};

#endif