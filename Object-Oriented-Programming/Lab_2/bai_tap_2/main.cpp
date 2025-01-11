#include "TamGiac.h"
#define PI 3.14159

void TamTamGiac(TamGiac temp, Diem &G)
{
    Diem arr[3];
    temp.GetDinh(arr);
    float sum1 = 0, sum2 = 0;
    for (int i = 0; i < 3; i++)
    {
        sum1 += arr[i].GetHoanhDo();
        sum2 += arr[i].GetTungDo();
    }
    sum1 = sum1 / 3;
    sum2 = sum2 / 3;
    G.Set_HoanhDo(sum1);
    G.Set_TungDo(sum2);
}
int main()
{
    TamGiac temp;
    temp.Nhap();
    temp.Xuat();
    vec vec_temp;
    cout << "-- Nhap toa do vector tinh tien: ";
    cin >> vec_temp.x;
    cin >> vec_temp.y;
    temp.TinhTien(vec_temp);
    Diem G;
    TamTamGiac(temp, G);
    Diem arr1[3], arr2[3];
    cout << "-- Nhap he so phong to: ";
    float hesophongto;
    cin >> hesophongto;
    temp.PhongTo(G, hesophongto, arr1);
    cout << "-- Nhap he so thu nho: ";
    float hesothunho;
    cin >> hesothunho;
    temp.ThuNho(G, hesothunho, arr2);
    cout << "-- Nhap goc quay: ";
    float gocquay;
    cin >> gocquay;
    Diem arr3[3];
    gocquay = (gocquay / 180) * PI;
    temp.Quay(gocquay, arr3);
    return 0;
}
