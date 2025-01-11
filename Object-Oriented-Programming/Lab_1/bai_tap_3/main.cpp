#include <bits/stdc++.h>
#include "SoPhuc.h"
using namespace std;

void SoPhuc::Nhap(){
    cout << "Nhap phan thuc: ";
    cin >> iThuc;
    cout << "Nhap phan ao: ";
    cin >> iAo;
}

void SoPhuc::Xuat(){
    if (iThuc == 0 && iAo == 0){
        cout << 0;
        return;
    }
    if (iThuc != 0){
        cout << iThuc;
    }
    if (iAo == 0){
        return;
    }
    if (iAo > 0 && iThuc != 0){
        cout << " + ";
        if (iAo != 1){
            cout << iAo;
        }
        cout << "i" << endl;
        return;
    }
    else if (iAo < 0 && iThuc != 0){
        cout << " - ";
        if (abs(iAo) != 1){
            cout << abs(iAo);
        }
        cout << "i" << endl;
        return;
    }
    if (iAo >= 1){
        if (iAo != 1){
            cout << iAo;
        }
        cout << "i" << endl;
    }
    else if (iAo <= -1){
        cout << "-";
        if (abs(iAo) != 1){
            cout << abs(iAo);
        }
        cout << "i" << endl;
    }
}

void SoPhuc::Tong(SoPhuc other){
    SoPhuc result;
    result.iThuc = iThuc + other.iThuc;
    result.iAo = iAo + other.iAo;
    cout << "Phep cong" << endl;
    result.Xuat();
}

void SoPhuc::Hieu(SoPhuc other){
    SoPhuc result;
    result.iThuc = iThuc - other.iThuc;
    result.iAo = iAo - other.iAo;
    cout << "Phep tru" << endl;
    result.Xuat();
}

void SoPhuc::Tich(SoPhuc other){
    SoPhuc result;
    result.iThuc = (iThuc * other.iThuc) - (iAo * other.iAo);
    result.iAo = (iThuc * other.iAo) + (iAo * other.iThuc);
    cout << "Phep nhan" << endl;
    result.Xuat();
}

void SoPhuc::Thuong(SoPhuc other){
    SoPhuc result;
    result.iThuc = ((iThuc * other.iThuc) + (iAo * other.iAo)) / (pow(other.iThuc, 2) + pow(other.iAo, 2));
    result.iAo = ((iAo * other.iThuc) - (iThuc * other.iAo)) / (pow(other.iThuc, 2) + pow(other.iAo, 2));
    cout << "Phep chia" << endl;
    result.Xuat();
}


int main(){
    SoPhuc a;
    SoPhuc b;
    cout << "Nhap so phuc thu nhat" << endl;
    a.Nhap();
    cout << "Nhap so phuc thu hai" << endl;
    b.Nhap();
    a.Tong(b);
    a.Hieu(b);
    a.Tich(b);
    a.Thuong(b);
    return 0;
}