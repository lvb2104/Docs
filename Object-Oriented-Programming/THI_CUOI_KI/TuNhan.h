#ifndef TUNHAN_H
#define TUNHAN_H

#include <bits/stdc++.h>
#include "People.h"
using namespace std;

class TuNhan : public People
{
private:
    string phamToi;
    int soNamTu;
public:
    TuNhan(int type, string ten, int tuoi, string sdt, string phamToi, int soNamTu) : People(type, ten, tuoi, sdt)
    {
        this->phamToi = phamToi;
        this->soNamTu = soNamTu;
        if (soNamTu > 20)
        {
            this->cachChet = "nang";
        }
        else if (soNamTu > 10 && soNamTu <= 20)
        {
            this->cachChet = "binh thuong";
        }
        else
        {
            this->cachChet = "nhe";
        }
    }
    string getPhamToi()
    {
        return this->phamToi;
    }
    int getNamTu()
    {
        return this->soNamTu;
    }
};

#endif