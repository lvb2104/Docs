#ifndef DEATHNOTE_H
#define DEADTHOTE_H

#include <bits/stdc++.h>
#include "People.h"
#include "DoanhNhan.h"
#include "ChinhTriGia.h"
#include "TuNhan.h"
using namespace std;

class DeathNote
{
private:
    int soLuongNhap;
    int gioiHan;
    vector<People *> listPeople;
public:
    int getGioiHan();
    void setGioiHan(int gioiHan);
    int getSoLuongNhap();
    void setSoLuongNhap(int soLuongNhap);
    void nhap();
    void xuata();
    void xuLy();
    void xuatb();
    void xuatc();
};

#endif