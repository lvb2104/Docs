#ifndef DIEM_H
#define DIEM_H

#include <bits/stdc++.h>
using namespace std;

class Diem
{
private:
    int iHoanh, iTung;

public:
    Diem();
    Diem(int Hoanh, int Tung);
    Diem(const Diem &x);
    void Xuat();
    int GetTungDo();
    int GetHoanhDo();
    void SetTungDo(int y);
    void SetHoanhDo(int x);
    void TinhTien(int dx, int dy);
};

#endif