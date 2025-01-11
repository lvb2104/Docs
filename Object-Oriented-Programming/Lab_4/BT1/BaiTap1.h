#ifndef BAITAP1_H
#define BAITAP1_H

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

class NhanVien
{
private:
    string MaSoNhanVien;
    string Ten;
    double LuongCoBan;

public:
    NhanVien(string msnv, string ten, double luongcoban);
    string get_MaSoNhanVien();
    string get_Ten();
    double get_LuongCoBan();
    virtual void Xuat() = 0;
};
class QuanLy : public NhanVien
{
protected:
    float TyLeThuong;

public:
    QuanLy(string msnv, string ten, double luongcoban, float tylethuong);
    ~QuanLy();
    double TienThuong();
    void Xuat();
};
class KySu : public NhanVien
{
protected:
    float SoGioLamThem;

public:
    KySu(string msnv, string ten, double luongcoban, float sogiolamthem);
    ~KySu();
    long double TienThuong();
    void Xuat();
};

#endif