#include "BaiTap1.h"

QuanLy::QuanLy(string msnv, string ten, double luongcoban, float tylethuong) : NhanVien(msnv, ten, luongcoban)
{
    this->TyLeThuong = tylethuong;
}
QuanLy::~QuanLy() { ; }
double QuanLy::TienThuong()
{
    double tienthuong = get_LuongCoBan() * (this->TyLeThuong / 100);
    return tienthuong;
}
void QuanLy::Xuat()
{
    cout << "-> Thong tin cua quan ly:" << endl;
    cout << " + Ma so nhan vien: " << this->get_MaSoNhanVien() << endl;
    cout << " + Ten: " << this->get_Ten() << endl;
    cout << " + Luong co ban: " << setprecision(0) << fixed << this->get_LuongCoBan() << endl;
    cout << " + Tien thuong: " << setprecision(0) << fixed << this->TienThuong() << endl;
}