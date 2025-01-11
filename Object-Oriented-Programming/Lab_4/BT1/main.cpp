#include "BaiTap1.h"
#include <bits/stdc++.h>

bool check_MaSoNhanVien(string msnv)
{
    if (msnv.length() != 8)
    {
        return false;
    }
    for (int i = 0; i < msnv.length() - 1; i++)
    {
        if (!isalnum(msnv[i]))
        {
            return false;
        }
    }
    return true;
}
bool check_Ten(string ten)
{
    for (int i = 0; i < ten.length() - 1; i++)
    {
        if (!isalpha(ten[i]) && !isspace(ten[i]))
        {
            return false;
        }
    }
    return true;
}
void Nhap(string &msnv, string &ten, double &luongcoban)
{
    cout << " + Ma so nhan vien (8 chu so): ";
    getline(cin, msnv);
    cout << " + Ten: ";
    getline(cin, ten);
    cout << " + Luong co ban: ";
    cin >> luongcoban;
    cin.ignore();
    while (!check_MaSoNhanVien(msnv))
    {
        cout << " + Nhap lai ma so nhan vien (8 chu so): ";
        getline(cin, msnv);
    }
    while (!check_Ten(ten))
    {
        cout << " + Nhap lai ten (Khong co ki tu dac biet hoac chu so): ";
        getline(cin, ten);
    }
}
int main()
{
    string msnv, ten;
    double luongcoban;
    /*Nhap Quan ly*/
    cout << "-- Nhap thong tin quan ly:" << endl;
    Nhap(msnv, ten, luongcoban);
    float tylethuong;
    cout << " + Ty le thuong (%): ";
    cin >> tylethuong;
    QuanLy temp1(msnv, ten, luongcoban, tylethuong);
    /*Nhap Ky su*/
    cin.ignore();
    cout << "-- Nhap thong tin ky su:" << endl;
    Nhap(msnv, ten, luongcoban);
    float sogiolamthem;
    cout << " + Gio lam them (h): ";
    cin >> sogiolamthem;
    KySu temp2(msnv, ten, luongcoban, sogiolamthem);
    /*Xuat*/
    temp1.Xuat();
    temp2.Xuat();
}