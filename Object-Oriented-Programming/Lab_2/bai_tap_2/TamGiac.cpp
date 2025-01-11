#include "TamGiac.h"

void TamGiac::Nhap()
{
    cout << "-- Nhap toa do cac dinh cua tam giac ABC: " << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << " + Toa do dinh " << i + 1 << ": ";
        Dinh[i].SetHoanhDo();
        Dinh[i].SetTungDo();
    }
}
void TamGiac::Xuat()
{
    cout << "-> Toa do cac dinh cua tam giac ABC: ";
    for (int i = 0; i < 3; i++)
    {
        cout << "(" << setprecision(2) << fixed << Dinh[i].GetHoanhDo() << "," << setprecision(2) << fixed << Dinh[i].GetTungDo() << ")"
             << " ";
    }
    cout << endl;
}
void TamGiac::GetDinh(Diem arr[])
{
    for (int i = 0; i < 3; i++)
    {
        arr[i] = Dinh[i];
    }
}
void TamGiac::TinhTien(vec temp)
{
    for (int i = 0; i < 3; i++)
    {
        Dinh[i].TinhTien(temp);
    }
    cout << "-> Toa do tam giac ABC sau khi tinh tien: ";
    for (int i = 0; i < 3; i++)
    {
        cout << "(" << setprecision(2) << fixed << Dinh[i].GetHoanhDo() << "," << setprecision(2) << fixed << Dinh[i].GetTungDo() << ")"
             << " ";
    }
    cout << endl;
}
void TamGiac::PhongTo(Diem G, float hesophongto, Diem arr[])
{
    GetDinh(arr);
    for (int i = 0; i < 3; i++)
    {
        float hoanh = hesophongto * (arr[i].GetHoanhDo() - G.GetHoanhDo()) + G.GetHoanhDo();
        float tung = hesophongto * (arr[i].GetTungDo() - G.GetTungDo()) + G.GetTungDo();
        arr[i].Set_HoanhDo(hoanh);
        arr[i].Set_TungDo(tung);
    }
    cout << "-> Toa do tam giac ABC sau khi phong to gap " << hesophongto << " lan: ";
    for (int i = 0; i < 3; i++)
    {
        cout << "(" << setprecision(2) << fixed << arr[i].GetHoanhDo() << "," << setprecision(2) << fixed << arr[i].GetTungDo() << ")"
             << " ";
    }
    cout << endl;
}
void TamGiac::ThuNho(Diem G, float hesothunho, Diem arr[])
{
    GetDinh(arr);
    for (int i = 0; i < 3; i++)
    {
        float hoanh = (float)(1 / hesothunho) * (arr[i].GetHoanhDo() - G.GetHoanhDo()) + G.GetHoanhDo();
        float tung = (float)(1 / hesothunho) * (arr[i].GetTungDo() - G.GetTungDo()) + G.GetTungDo();
        arr[i].Set_HoanhDo(hoanh);
        arr[i].Set_TungDo(tung);
    }
    cout << "-> Toa do tam giac ABC sau khi thu nho gap " << hesothunho << " lan: ";
    for (int i = 0; i < 3; i++)
    {
        cout << "(" << setprecision(2) << fixed << arr[i].GetHoanhDo() << "," << setprecision(2) << fixed << arr[i].GetTungDo() << ")"
             << " ";
    }
    cout << endl;
}
void TamGiac::Quay(float gocquay, Diem arr[])
{
    GetDinh(arr);
    for (int i = 0; i < 3; i++)
    {
        float hoanh = arr[i].GetHoanhDo() * cos(gocquay) - arr[i].GetTungDo() * sin(gocquay);
        float tung = arr[i].GetHoanhDo() * sin(gocquay) + arr[i].GetTungDo() * cos(gocquay);
        arr[i].Set_HoanhDo(hoanh);
        arr[i].Set_TungDo(tung);
    }
    cout << "-> Toa do tam giac ABC sau khi quay: ";
    for (int i = 0; i < 3; i++)
    {
        cout << "(" << setprecision(2) << fixed << arr[i].GetHoanhDo() << "," << setprecision(2) << fixed << arr[i].GetTungDo() << ")"
             << " ";
    }
    cout << endl;
}

TamGiac::TamGiac()
{
    Dinh = new Diem[3];
}

TamGiac::~TamGiac()
{
    delete[] Dinh;
}
