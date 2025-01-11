#ifndef PHANSO_OPERATOR
#define PHANSO_OPERATOR

#include <bits/stdc++.h>
using namespace std;

class PhanSo
{
private:
    int iTu, iMau;

public:
    PhanSo();
    PhanSo(int Tu, int Mau);
    void RutGon();
    PhanSo operator+(const PhanSo &other);
    PhanSo operator-(const PhanSo &other);
    PhanSo operator*(const PhanSo &other);
    PhanSo operator/(const PhanSo &other);
    bool operator==(const PhanSo &other);
    bool operator!=(const PhanSo &other);
    bool operator>=(const PhanSo &other);
    bool operator<=(const PhanSo &other);
    bool operator>(const PhanSo &other);
    bool operator<(const PhanSo &other);
    friend istream &operator>>(istream &in, PhanSo &ps);
    friend ostream &operator<<(ostream &out, const PhanSo &ps);
};

#endif