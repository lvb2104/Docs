#ifndef VECHONGOI
#define VECHONGOI

#include "Ve.h"

class VeChonGoi : public Ve
{
private:
    int giaVe;
    int soLuongTroChoi;
    int chiPhiTroChoi;

public:
    // Constructor
    VeChonGoi() : Ve() {}
    VeChonGoi(string mv, string ht, int ns, int sltcdtg) : Ve(mv, ht, ns, sltcdtg)
    {
        giaVe = 200000;
        soLuongTroChoi = 30;
        chiPhiTroChoi = 0;
    }

    // Method
    int getGiaVe() { return giaVe; }
    int getSoLuongTroChoi() { return soLuongTroChoi; }\
    int getChiPhiTroChoi() { return chiPhiTroChoi; }
};

#endif