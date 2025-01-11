#ifndef BAI3_H_INCLUDED
#define BAI3_H_INCLUDED

#include <bits/stdc++.h>
#define endl "\n"
#include <iostream>

using namespace std;
using ll = long long;

class thoigian
{
private:
    int Gio, Phut, Giay;

public:
    void xuat();
    thoigian(){};
    thoigian(int gio, int phut, int giay);
    int TinhGiay();
    void Tinhlaigio(int giay);

    thoigian operator+(int giay);
    thoigian operator-(int giay);
    thoigian operator+(thoigian a);
    thoigian operator-(thoigian a);
    void operator++();
    void operator--();
    bool operator==(thoigian a);
    bool operator!=(thoigian a);
    bool operator>=(thoigian a);
    bool operator<=(thoigian a);
    bool operator>(thoigian a);
    bool operator<(thoigian a);
    friend istream &operator>>(istream &in, thoigian &a);
    friend ostream &operator<<(ostream &out, thoigian a);
};

#endif // BAI3_H_INCLUDED
