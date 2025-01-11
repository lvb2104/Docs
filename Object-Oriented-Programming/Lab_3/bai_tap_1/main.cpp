#include "PhanSo.h"

int main()
{
    PhanSo ps1, ps2;
    cout << "-- Nhap phan so thu nhat:" << endl;
    cin >> ps1;
    ps1.RutGon();
    cout << "-> Phan so thu nhat (toi gian): " << ps1;
    cout << "-- Nhap phan so thu hai:" << endl;
    cin >> ps2;
    ps2.RutGon();
    cout << "-> Phan so thu hai (toi gian): " << ps2;
    cout << "-- Tinh toan phan so: " << endl;
    PhanSo tong = ps1 + ps2;
    cout << " + Tong hai phan so (toi gian): " << tong;
    PhanSo hieu = ps1 - ps2;
    cout << " + Hieu hai phan so (toi gian): " << hieu;
    PhanSo tich = ps1 * ps2;
    cout << " + Tich hai phan so (toi gian): " << tich;
    PhanSo thuong = ps1 / ps2;
    cout << "-- So sanh hai phan so: " << endl;
    if (ps1 == ps2)
    {
        cout << " + Hai phan so bang nhau." << endl;
    }
    else
    {
        cout << " + Hai phan so khac nhau." << endl;
    }
    if (ps1 != ps2)
    {
        cout << " + Hai phan so khac nhau." << endl;
    }
    else
    {
        cout << " + Hai phan so bang nhau." << endl;
    }
    if (ps1 >= ps2)
    {
        cout << " + Phan so thu nhat lon hon hoac bang phan so thu hai." << endl;
    }
    else
    {
        cout << " + Phan so thu nhat nho hon phan so thu hai." << endl;
    }
    if (ps1 <= ps2)
    {
        cout << " + Phan so thu nhat nho hon hoac bang phan so thu hai." << endl;
    }
    else
    {
        cout << " + Phan so thu nhat lon hon phan so thu hai." << endl;
    }
    if (ps1 > ps2)
    {
        cout << " + Phan so thu nhat lon hon phan so thu hai." << endl;
    }
    else
    {
        cout << " + Phan so thu nhat khong lon hon phan so thu hai." << endl;
    }
    if (ps1 < ps2)
    {
        cout << " + Phan so thu nhat nho hon phan so thu hai." << endl;
    }
    else
    {
        cout << " + Phan so thu nhat khong nho hon phan so thu hai." << endl;
    }
    return 0;
}
