#ifndef THISINH_H
#define THISINH_H

#include <bits/stdc++.h>
using namespace std;

string chuanHoaTen(string name);
string chuanHoaNgayThangNam(int ngay, int thang, int nam);

class ThiSinh
{
private:
    std::string Ten, MSSV;
    int iNgay, iThang, iNam;
    float fToan, fVan, fAnh;
public:
    void Nhap();
    void Xuat();
    float Tong();
};

#endif