#include <iostream>
#include "PhanSo.h"
#include <algorithm>
using namespace std;

void PhanSo::Nhap(){
    cout << "Nhap tu so: ";
    cin >> iTu;
    cout << "Nhap mau so: ";
    cin >> iMau;
}

void PhanSo::Xuat(){
    if (iTu == iMau){
        cout << "Ket qua la: " << 1 << endl;
        return;
    }
    if (iMau == 1)
        cout << "Ket qua la: " << iTu << endl;
    else 
        cout << "Ket qua la: " << iTu << '/' << iMau << endl;
}

void PhanSo::Rutgon(){
    int uocChung = __gcd(iTu, iMau);
    iTu /= uocChung;
    iMau /= uocChung;
    if (iTu < 0 && iMau < 0){
        iTu *= -1;
        iMau *= -1;
    }
    else if (iTu > 0 && iMau < 0){
        iTu *= -1;
        iMau *= -1;
    }
}

void PhanSo::Tong(PhanSo other){
    PhanSo result;
    result.iTu = iTu * other.iMau + other.iTu * iMau;
    result.iMau = iMau * other.iMau;
    result.Rutgon();
    cout << "Phep cong" << endl;
    result.Xuat();
}

void PhanSo::Hieu(PhanSo other){
    PhanSo result;
    result.iTu = iTu * other.iMau - other.iTu * iMau;
    result.iMau = iMau * other.iMau;
    result.Rutgon();
    cout << "Phep tru" << endl;
    result.Xuat();
}

void PhanSo::Tich(PhanSo other){
    PhanSo result;
    result.iTu = iTu * other.iTu;
    result.iMau = iMau * other.iMau;
    result.Rutgon();
    cout << "Phep nhan" << endl;
    result.Xuat();
}

void PhanSo::Thuong(PhanSo other){
    PhanSo result;
    result.iTu = iTu * other.iMau;
    result.iMau = iMau * other.iTu;
    result.Rutgon();
    cout << "Phep chia" << endl;
    result.Xuat();
}

void PhanSo::SoSanh(PhanSo other){
    float check = (1.0 * iTu / iMau ) - (1.0 * other.iTu / other.iMau);
    if (check == 0){
        cout << "Hai phan so bang nhau" << endl;
    }
    else if (check < 0){
        if (iMau == 1)
            cout << "Phan so " << iTu;
        else 
            cout << "Phan so " << iTu << '/' << iMau;
        cout << " nho hon ";
        if (other.iMau == 1)
            cout << "phan so " << other.iTu;
        else 
            cout << "phan so " << other.iTu << '/' << other.iMau;
    }
    else {
        if (iMau == 1)
            cout << "Phan so " << iTu;
        else 
            cout << "Phan so " << iTu << '/' << iMau;
        cout << " lon hon ";
        if (other.iMau == 1)
            cout << "phan so " << other.iTu;
        else 
            cout << "phan so " << other.iTu << '/' << other.iMau;
    }
}

int PhanSo::getMau(){
    return iMau;
}

int main(){
    PhanSo a;
    do {
        cout << "Nhap phan so thu nhat" << endl;
        a.Nhap();
        if (a.getMau() == 0){
            cout << "Mau cua phan so da nhap khong hop le.\n";
        }
    } while(a.getMau() == 0);
    PhanSo b;
    do {
        cout << "Nhap phan so thu hai" << endl;
        b.Nhap();
        if (b.getMau() == 0){
            cout << "Mau cua phan so da nhap khong hop le.\n";
        }
    } while(b.getMau() == 0);
    a.Tong(b);
    a.Hieu(b);
    a.Tich(b);
    a.Thuong(b);
    a.SoSanh(b);
}