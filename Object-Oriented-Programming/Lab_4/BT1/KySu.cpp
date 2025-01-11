#include "BaiTap1.h"

KySu::KySu(string msnv, string ten, double luongcoban, float sogiolamthem) : NhanVien(msnv, ten, luongcoban)
{
    this->SoGioLamThem = sogiolamthem;
}
KySu::~KySu() { ; }
long double KySu::TienThuong()
{
    long double tienthuong = 100000 * SoGioLamThem;
    return tienthuong;
}
void KySu::Xuat()
{
    cout << "-> Thong tin cua ky su:" << endl;
    cout << " + Ma so nhan vien: " << this->get_MaSoNhanVien() << endl;
    cout << " + Ten: " << this->get_Ten() << endl;
    cout << " + Luong co ban: " << setprecision(0) << fixed << this->get_LuongCoBan() << endl;
    cout << " + Tien thuong: " << setprecision(0) << fixed << this->TienThuong() << endl;
}
