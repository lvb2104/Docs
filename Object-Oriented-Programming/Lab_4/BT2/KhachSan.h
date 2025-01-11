#ifndef SOFITEL_DOANHTHU
#define SOFITEL_DOANHTHU

#include <bits/stdc++.h>
using namespace std;

class SOFITEL
{
public:
    int SoDem;
    double PhiDichVu, PhiPhucVu;

    int SDmoney, PDVmoney, PPVmoney;
    SOFITEL();
    SOFITEL(int sodem, double phidichvu, double phiphucvu);
    void Nhap();
    friend double doanhthu(const SOFITEL &s);
};

class Deluxe : public SOFITEL
{
public:
    Deluxe()
    {
        SDmoney = 750000;
        PDVmoney = 1;
        PPVmoney = 1;
    }
};

class Premium : public SOFITEL
{
public:
    Premium()
    {
        SDmoney = 500000;
        PDVmoney = 1;
        PPVmoney = 0;
    }
};

class Business : public SOFITEL
{
public:
    Business()
    {
        SDmoney = 300000;
        PDVmoney = 0;
        PPVmoney = 0;
    }
};

#endif