#include "KhachSan.h"

SOFITEL::SOFITEL()
{
    SoDem = 0;
    PhiDichVu = 0;
    PhiPhucVu = 0;
}

SOFITEL::SOFITEL(int sodem, double phidichvu, double phiphucvu)
{
    SoDem = sodem;
    PhiDichVu = phidichvu;
    PhiPhucVu = phiphucvu;
}

void SOFITEL::Nhap()
{
    cout << "Nhap so dem: ";
    cin >> SoDem;
    cout << "Nhap phi dich vu: ";
    cin >> PhiDichVu;
    cout << "Nhap phi phuc vu: ";
    cin >> PhiPhucVu;
}

double doanhthu(const SOFITEL &s)
{
    return (s.SoDem * s.SDmoney) + (s.PhiDichVu * s.PDVmoney) + (s.PhiPhucVu * s.PPVmoney);
}
