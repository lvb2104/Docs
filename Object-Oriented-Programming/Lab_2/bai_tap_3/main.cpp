#include "bai3.h"
#define PI 3.14159

void tamdagiac(dagiac temp, Diem &G)
{

    Diem arr[temp.getn() + 10];
    temp.getdinh(arr);
    float sum1 = 0, sum2 = 0;

    for (int i = 0; i < temp.getn(); i++)
    {
        sum1 += arr[i].GetHoanhDo();
        sum2 += arr[i].GetTungDo();
    }

    sum1 = sum1 / temp.getn();
    sum2 = sum2 / temp.getn();

    G.Set_HoanhDo(sum1);
    G.Set_TungDo(sum2);
}

int main()
{
    dagiac temp;
    temp.Nhap();
    temp.Xuat();

    cout << "Nhap toa do vecto:";
    vec vec_temp;
    cin >> vec_temp.x;
    cin >> vec_temp.y;

    temp.TinhTien(vec_temp);

    Diem G;
    tamdagiac(temp, G);
    Diem arr1[temp.getn() + 1], arr2[temp.getn() + 1];

    // cout<<G.GetHoanhDo()<<","<<G.GetTungDo()<<endl;
    cout << "nhap vao he so phong to:";
    int hesophongto;
    cin >> hesophongto;

    temp.PhongTo(G, hesophongto, arr1);

    // cout<<G.GetHoanhDo()<<","<<G.GetTungDo()<<endl;
    cout << "nhap vao he so thu nho:";
    int hesothunho;
    cin >> hesothunho;
    temp.ThuNho(G, hesothunho, arr2);

    cout << "Nhap goc quay:";
    float gocquay;
    cin >> gocquay;
    Diem arr3[temp.getn() + 1];

    gocquay = (gocquay / 180) * PI;
    // cout<<"goc quay:"<<gocquay<<endl;
    temp.Quay(gocquay, arr3);

    return 0;
}
