#ifndef TAMGIAC_H
#define TAMGIAC_H

#include "Diem.h"

class TamGiac
{
private:
    Diem *Dinh;

public:
    void Nhap();
    void Xuat();
    void GetDinh(Diem *p);
    void TinhTien(vec temp);
    void PhongTo(Diem G, float hesophongto, Diem arr[]);
    void ThuNho(Diem G, float hesothunho, Diem arr[]);
    void Quay(float gocquay, Diem arr[]);
    TamGiac(); 
    ~TamGiac();
};

#endif
