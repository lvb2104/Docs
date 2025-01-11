#include "Diem.h"

Diem::Diem(){};

Diem::Diem(int Hoanh, int Tung)
{
    iHoanh = Hoanh;
    iTung = Tung;
}

Diem::Diem(const Diem &x)
{
    iHoanh = x.iHoanh;
    iTung = x.iTung;
}

void Diem::Xuat()
{
    cout << "Toa do: (" << iHoanh << ", " << iTung << ")" << endl;
}

int Diem::GetTungDo()
{
    return iTung;
}

int Diem::GetHoanhDo()
{
    return iHoanh;
}

void Diem::SetTungDo(int y)
{
    iTung = y;
}

void Diem::SetHoanhDo(int x)
{
    iHoanh = x;
}

void Diem::TinhTien(int dx, int dy)
{
    iHoanh += dx;
    iTung += dy;
}