#ifndef PEOPLE_H
#define PEOPLE_H

#include <bits/stdc++.h>
using namespace std;

class People
{
protected:
    int type;
    string ten;
    int tuoi;
    string sdt;
    string cachChet;
public:
    People(int type, string ten, int tuoi, string sdt)
    {
        this->type = type;
        this->ten = ten;
        this->tuoi = tuoi;
        this->sdt = sdt;
    }
    string getTen();
    int getTuoi();
    string getSdt();
    string getCachChet();
    int getType();
    virtual string getChucVu();
    virtual float getTaiSan();
    virtual string getPhamToi();
    virtual int getNamTu();
};

#endif