#include "NgayThangNam.h"
#include <iostream>
using namespace std;

bool check(int ngay, int thang, int nam){
    int maxThang;
    switch (thang){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            maxThang = 31;
            break;
        case 4: case 6: case 9: case 11:
            maxThang = 30;
            break;
        case 2:
            if (nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0))
                maxThang = 29;
            else {
                maxThang = 28;
            }
            break;
        default:
            cout << "Thang nhap khong hop le\n";
            return false;
    }
    if (maxThang < ngay || ngay <= 0){
        cout << "Ngay nhap khong hop le\n";
        return false;
    }
    return true;
}

void NgayThangNam::Nhap(){
    do {
        cout << "Nhap ngay thang nam: ";
        cin >> iNgay >> iThang >> iNam;
    } while(!check(iNgay, iThang, iNam));
}

void NgayThangNam::Xuat(){
    cout << "Ngay Thang Nam hien tai la: ";
    cout << iNgay << "/" << iThang << "/" << iNam << endl;
}

void NgayThangNam::NgayThangNamTiepTheo(){
    int maxThang;
    switch (iThang){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            maxThang = 31;
            break;
        case 4: case 6: case 9: case 11:
            maxThang = 30;
            break;
        case 2:
            if (iNam % 400 == 0 || (iNam % 4 == 0 && iNam % 100 != 0))
                maxThang = 29;
            else {
                maxThang = 28;
            }
            break;
        default:
            cout << "Thang nhap khong hop le\n";
    }
    if (iNgay < maxThang){
        iNgay++;
    }
    else {
        if (iThang < 12){
            iThang++;
            iNgay = 1;
        }
        else {
            iNam++;
            iThang = 1;
            iNgay = 1;
        }
    }
    cout << "Ngay Thang Nam tiep theo la: " << iNgay << '/' << iThang << '/' << iNam << endl;
}

int main(){
    NgayThangNam ngayHomNay;
    ngayHomNay.Nhap();
    ngayHomNay.Xuat();
    ngayHomNay.NgayThangNamTiepTheo();
    return 0;
}