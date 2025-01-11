#ifndef BAI3_H_INCLUDED
#define BAI3_H_INCLUDED

#include "bai1.h"

class dagiac
{
private:
    int n;
    Diem *Dinh;

public:
    void Nhap();
    void Xuat();
    int getn();
    void getdinh(Diem *p);
    void TinhTien(vec temp);
    void PhongTo(Diem G, int hesophongto, Diem arr[]);
    void ThuNho(Diem G, int hesothunho, Diem arr[]);
    void Quay(float gocquay, Diem arr[]);
};

#endif // BAI3_H_INCLUDED
