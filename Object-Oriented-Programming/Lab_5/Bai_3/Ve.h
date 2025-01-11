#ifndef VE_H
#define VE_H

#include <bits/stdc++.h>
using namespace std;

class Ve
{
protected:
    string maVe;
    string hoTen;
    int namSinh;
    int soLuongTroChoiDaThamGia;

public:
    // Constructor
    Ve() {}
    Ve(string mv, string ht, int ns, int sltcdtg)
    {
        maVe = mv;
        hoTen = ht;
        namSinh = ns;
        soLuongTroChoiDaThamGia = sltcdtg;
    }

    // Method
    string getMaVe() { return maVe; }
    string getHoTen() { return hoTen; }
    int getNamSinh() { return namSinh; }
    int getSoLuongTroChoiDaThamGia() { return soLuongTroChoiDaThamGia; }
    virtual int getGiaVe() = 0;
    virtual int getSoLuongTroChoi() = 0;
    virtual int getChiPhiTroChoi() = 0;
};

#endif