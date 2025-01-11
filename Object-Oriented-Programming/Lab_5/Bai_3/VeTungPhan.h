#ifndef VETUNGPHAN_H
#define VETUNGPHAN_H

#include "Ve.h"

class VeTungPhan : public Ve
{
private:
    int giaVe;
    int soLuongTroChoi;
    int chiPhiTroChoi;

public:
    // Constructor
    VeTungPhan() : Ve() {}
    VeTungPhan(string mv, string ht, int ns, int sltcdtg) : Ve(mv, ht, ns, sltcdtg)
    {
        giaVe = 70000;
        soLuongTroChoi = 0;
        chiPhiTroChoi = 20000;
    }
    // Method
    int getGiaVe() { return giaVe; }
    int getSoLuongTroChoi() { return soLuongTroChoi; }
    int getChiPhiTroChoi() { return chiPhiTroChoi; }
};

#endif