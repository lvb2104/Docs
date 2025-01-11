#ifndef BAI1_H_INCLUDED
#define BAI1_H_INCLUDED
#include <bits/stdc++.h>
using namespace std;
typedef struct
{
    float x;
    float y;
} vec;

class Diem
{
private:
    float ihoanh, itung;

public:
    Diem();
    Diem(float hoanh, float tung);
    void xuat();
    float GetTungDo();
    float GetHoanhDo();
    void SetTungDo();
    void SetHoanhDo();

    void Set_HoanhDo(float hoanh);

    void Set_TungDo(float tung);

    void TinhTien(vec temp);
};

#endif // BAI1_H_INCLUDED
