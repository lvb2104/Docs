#include <bits/stdc++.h>
#include "Time.h"
using namespace std;

bool check(int gio, int phut, int giay){
    if (gio > 24 || gio < 0){
        cout << "Gio nhap khong hop le\n";
        return false;
    }
    if (phut > 60 || phut < 0){
        cout << "Phut nhap khong hop le\n";
        return false;
    }
    if (giay > 60 || giay < 0){
        cout << "Giay nhap khong hop le\n";
        return false;
    }
    return true;
}

void Time::Nhap(){
    do {
        cout << "Nhap gio, phut, giay: ";
        cin >> iGio >> iPhut >> iGiay;
    } while(!check(iGio, iPhut, iGiay));
}
void Time::Xuat(){
    cout << "Gio, Phut, Giay hien tai la: ";
    cout << iGio << " Gio " << iPhut << " Phut " << iGiay << " Giay." << endl;
}
void Time::TinhCongThemMotGiay(){
    if (iGiay < 59){
        iGiay++;
    }
    else {
        if (iPhut < 59){
            iPhut++;
            iGiay = 0;
        }
        else {
            if (iGio < 23){
                iGio++;
                iPhut = 0;
                iGiay = 0;
            }
            else {
                iGio = 0;
                iPhut = 0;
                iGiay = 0;
            }
        }
    }
    cout << "Gio, Phut, Giay tang them 1 giay la: ";
    cout << iGio << " Gio " << iPhut << " Phut " << iGiay << " Giay." << endl;
}

int main(){
    Time thoiGianHienTai;
    thoiGianHienTai.Nhap();
    thoiGianHienTai.Xuat();
    thoiGianHienTai.TinhCongThemMotGiay();
    return 0;
}