#include "PhanSo.h"

int UCLN(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return UCLN(b, a % b);
    }
}
void PhanSo::RutGon()
{
    int ucln = UCLN(iTu, iMau);
    iTu /= ucln;
    iMau /= ucln;
}
PhanSo::PhanSo()
{
    iTu;
    iMau;
}
PhanSo::PhanSo(int Tu, int Mau)
{
    iTu = Tu;
    iMau = Mau;
}
PhanSo PhanSo::operator+(const PhanSo &other)
{
    PhanSo tong;
    tong.iTu = iTu * other.iMau + other.iTu * iMau;
    tong.iMau = iMau * other.iMau;
    tong.RutGon();
    return tong;
}
PhanSo PhanSo::operator-(const PhanSo &other)
{
    PhanSo hieu;
    hieu.iTu = iTu * other.iMau - other.iTu * iMau;
    hieu.iMau = iMau * other.iMau;
    hieu.RutGon();
    return hieu;
}
PhanSo PhanSo::operator*(const PhanSo &other)
{
    PhanSo tich;
    tich.iTu = iTu * other.iTu;
    tich.iMau = iMau * other.iMau;
    tich.RutGon();
    return tich;
}
PhanSo PhanSo::operator/(const PhanSo &other)
{
    PhanSo thuong;
    cout << " + Thuong hai phan so (toi gian): ";
    if (other.iTu != 0)
    {
        thuong.iTu = iTu * other.iMau;
        thuong.iMau = iMau * other.iTu;
        thuong.RutGon();
        cout << thuong;
    }
    else
    {
        cout << "Phep tinh khong thuc hien duoc vi phan so thu hai bang 0." << endl;
    }
    return thuong;
}
bool PhanSo::operator==(const PhanSo &other)
{
    return (iTu * other.iMau == other.iTu * iMau);
}
bool PhanSo::operator!=(const PhanSo &other)
{
    return !(*this == other);
}
bool PhanSo::operator>=(const PhanSo &other)
{
    return (iTu * other.iMau >= other.iTu * iMau);
}
bool PhanSo::operator<=(const PhanSo &other)
{
    return (iTu * other.iMau <= other.iTu * iMau);
}
bool PhanSo::operator>(const PhanSo &other)
{
    return !(*this <= other);
}
bool PhanSo::operator<(const PhanSo &other)
{
    return !(*this >= other);
}
istream &operator>>(istream &in, PhanSo &ps)
{
    cout << " + Nhap tu so: ";
    in >> ps.iTu;
    cout << " + Nhap mau so: ";
    in >> ps.iMau;
    if (ps.iMau == 0)
    {
        cout << " + Phan so nay khong hop le vi co mau so bang 0. Hay nhap lai mau so: ";
        in >> ps.iMau;
    }
    return in;
}
ostream &operator<<(ostream &out, const PhanSo &ps)
{
    if (ps.iTu == 0)
    {
        out << 0 << endl;
    }
    else if (ps.iMau < 0)
    {
        out << -ps.iTu << "/" << -ps.iMau << endl;
    }
    else
    {
        if (ps.iMau == 1)
        {
            out << ps.iTu << endl;
        }
        else
        {
            out << ps.iTu << "/" << ps.iMau << endl;
        }
    }
    return out;
}