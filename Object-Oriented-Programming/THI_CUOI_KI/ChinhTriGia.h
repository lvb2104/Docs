#ifndef CHINHTRIGIA_H
#define CHINHTRIGIA_H

#include <bits/stdc++.h>
#include "People.h"
using namespace std;

class ChinhTriGia : public People
{
private:
    string chucVu;
public:
    ChinhTriGia(int type, string ten, int tuoi, string sdt, string chucVu) : People(type, ten, tuoi, sdt)
    {
        this->cachChet = "dau tim";
        this->chucVu = chucVu;
    }
    string getChucVu()
    {
        return this->chucVu;
    }
};

#endif