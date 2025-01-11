#include "BaiTap1.h"

NhanVien::NhanVien(string msnv, string ten, double luongcoban)
{
    this->MaSoNhanVien = msnv;
    this->Ten = ten;
    this->LuongCoBan = luongcoban;
}
string NhanVien::get_MaSoNhanVien()
{
    return this->MaSoNhanVien;
}
string NhanVien::get_Ten()
{
    return this->Ten;
}
double NhanVien::get_LuongCoBan()
{
    return this->LuongCoBan;
}