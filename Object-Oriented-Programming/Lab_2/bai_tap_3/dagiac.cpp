#include "bai3.h"

void dagiac::Nhap()
{
    cout << "Nhap so dinh:";
    cin >> n;
    Dinh = new Diem[n + 10];
    cout << "Nhap toa do cac dinh:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Dinh " << i + 1 << ":";
        Dinh[i].SetHoanhDo();
        Dinh[i].SetTungDo();
    }
}
void dagiac::Xuat()
{
    char kitu = 'A';
    cout << "da giac ";
    for (int i = 0; i < n; i++)
    {
        cout << (char)(kitu + i);
    }
    cout << " co cac dinh voi toa do lan luot la: ";
    for (int i = 0; i < n; i++)
    {
        cout << "(" << Dinh[i].GetHoanhDo() << "," << Dinh[i].GetTungDo() << ")"
             << " ";
    }
    cout << endl;
}
int dagiac::getn()
{
    return n;
}

void dagiac::getdinh(Diem arr[])
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = Dinh[i];
    }
}

void dagiac::TinhTien(vec temp)
{
    for (int i = 0; i < n; i++)
    {
        Dinh[i].TinhTien(temp);
    }

    char kitu = 'A';
    cout << "da giac ";
    for (int i = 0; i < n; i++)
    {
        cout << (char)(kitu + i);
    }
    cout << " sau khi tinh tien co toa do cac dinh la: ";
    for (int i = 0; i < n; i++)
    {
        cout << "(" << Dinh[i].GetHoanhDo() << "," << Dinh[i].GetTungDo() << ")"
             << " ";
    }
    cout << endl;
}

void dagiac::PhongTo(Diem G, int hesophongto, Diem arr[])
{

    getdinh(arr);
    for (int i = 0; i < n; i++)
    {
        float hoanh = hesophongto * (arr[i].GetHoanhDo() - G.GetHoanhDo()) + G.GetHoanhDo();
        float tung = hesophongto * (arr[i].GetTungDo() - G.GetTungDo()) + G.GetTungDo();

        arr[i].Set_HoanhDo(hoanh);
        arr[i].Set_TungDo(tung);
    }

    cout << "Da giac sau khi phong to gap " << hesophongto << " lan :";
    for (int i = 0; i < n; i++)
    {
        cout << "(" << arr[i].GetHoanhDo() << "," << arr[i].GetTungDo() << ")"
             << " ";
    }
    cout << endl;
}

void dagiac::ThuNho(Diem G, int hesothunho, Diem arr[])
{

    getdinh(arr);
    for (int i = 0; i < n; i++)
    {
        float hoanh = (float)(1 / hesothunho) * (arr[i].GetHoanhDo() - G.GetHoanhDo()) + G.GetHoanhDo();
        float tung = (float)(1 / hesothunho) * (arr[i].GetTungDo() - G.GetTungDo()) + G.GetTungDo();

        arr[i].Set_HoanhDo(hoanh);
        arr[i].Set_TungDo(tung);
    }

    cout << "Da giac sau khi thu nho gap " << hesothunho << " lan :";
    for (int i = 0; i < n; i++)
    {
        cout << "(" << arr[i].GetHoanhDo() << "," << arr[i].GetTungDo() << ")"
             << " ";
    }
    cout << endl;
}
void dagiac::Quay(float gocquay, Diem arr[])
{
    getdinh(arr);
    float hoanh, tung;
    for (int i = 0; i < n; i++)
    {
        hoanh = arr[i].GetHoanhDo() * cos(gocquay) - arr[i].GetTungDo() * sin(gocquay);
        tung = arr[i].GetHoanhDo() * sin(gocquay) + arr[i].GetTungDo() * cos(gocquay);

        arr[i].Set_HoanhDo(hoanh);
        arr[i].Set_TungDo(tung);
    }

    cout << "Da giac sau khi quay :";
    for (int i = 0; i < n; i++)
    {
        cout << setprecision(0) << fixed << "(" << arr[i].GetHoanhDo() << "," << arr[i].GetTungDo() << ")"
             << " ";
    }
}
