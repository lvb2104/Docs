#ifndef CONVAT_H
#define CONVAT_H

#include <bits/stdc++.h>
using namespace std;

class ConVat
{
protected: 
    string loai;
    int* thoiGian;
public:
    // constructor
    ConVat() {};
    ConVat(string l)
    {
        loai = l;
    }

    // method
    string getLoai() { return loai; }
    int* getThoiGian() { return thoiGian; }
    virtual bool tuanTheoQuiLuat() = 0;
};

#endif