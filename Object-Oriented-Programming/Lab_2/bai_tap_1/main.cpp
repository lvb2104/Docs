#include "Diem.h"

int main()
{
    cout << "Nhap 2 diem x, y: ";
    int x, y;
    cin >> x >> y;
    Diem *a = new Diem(x, y);
    a->Xuat();
    cout << "Nhap 2 so dx, dy: ";
    int dx, dy;
    cin >> dx >> dy;
    a->TinhTien(dx, dy);
    a->Xuat();
    return 0;
}