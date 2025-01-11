#ifndef NGAYTHANGNAM_H
#define NGAYTHANGNAM_H

#include <bits/stdc++.h>

class NgayThangNam
{
private:
    int iNgay, iThang, iNam;

public:
    // Constructor
    NgayThangNam();
    NgayThangNam(int Nam, int Thang, int Ngay);

    // Method
    void TinhNgay();
    void ChuanHoa();
    int getMaxThang(int Nam, int Thang);
    void setNgay(int Ngay);
    void setThang(int Thang);
    void setNam(int Nam);

    // Overload operator
    NgayThangNam operator+(int Ngay);
    NgayThangNam operator-(int Ngay);
    NgayThangNam operator-(NgayThangNam NgayThangNam2);
    NgayThangNam operator++();
    NgayThangNam operator--();
    bool operator==(NgayThangNam NgayThangNam2);
    bool operator!=(NgayThangNam NgayThangNam2);
    bool operator>=(NgayThangNam NgayThangNam2);
    bool operator<=(NgayThangNam NgayThangNam2);
    bool operator>(NgayThangNam NgayThangNam2);
    bool operator<(NgayThangNam NgayThangNam2);
    friend std::istream &operator>>(std::istream &in, NgayThangNam &ntn);
    friend std::ostream &operator<<(std::ostream &out, NgayThangNam ntn);
};

#endif