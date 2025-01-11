#include "bai1.h"

Diem::Diem()
{
    ;
}

Diem::Diem(float hoanh, float tung)
{
    ihoanh = hoanh;
    itung = tung;
    xuat();
}

void Diem::xuat()
{
    cout << "(" << ihoanh << "," << itung << ")" << endl;
}

float Diem::GetTungDo()
{
    return itung;
}
float Diem::GetHoanhDo()
{
    return ihoanh;
}
void Diem::SetTungDo()
{
    cin >> itung;
}
void Diem::SetHoanhDo()
{
    cin >> ihoanh;
}

// advanced
void Diem::Set_HoanhDo(float hoanh)
{
    ihoanh = hoanh;
}

void Diem::Set_TungDo(float tung)
{
    itung = tung;
}

void Diem::TinhTien(vec temp)
{
    ihoanh += temp.x;
    itung += temp.y;
}
