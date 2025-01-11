#include "ThiSinh.h"

string chuanHoaTen(string name)
{
    stringstream ss(name);
    string res = "", word;
    while (ss >> word)
    {
        res += toupper(word[0]);
        for (int j = 1; j < word.size(); j++)
        {
            res += tolower(word[j]);
        }
        res += " ";
    }
    res.pop_back();
    return res;
}

string chuanHoaNgayThangNam(int ngay, int thang, int nam)
{
    string res = "";
    res += to_string(ngay);
    res += "/";
    res += to_string(thang);
    res += "/";
    res += to_string(nam);
    if (res[2] != '/')
        res = "0" + res;
    if (res[5] != '/')
        res.insert(3, "0");
    return res;
}

void ThiSinh::Nhap()
{
    cout << "Nhap TEN cua thi sinh: ";
    getline(cin, Ten);
    Ten = chuanHoaTen(Ten);
    cout << "Nhap MSSV cua thi sinh: ";
    cin >> MSSV;
    cout << "Nhap NGAY sinh cua thi sinh: ";
    cin >> iNgay;
    cout << "Nhap THANG sinh cua thi sinh: ";
    cin >> iThang;
    cout << "Nhap NAM sinh cua thi sinh: ";
    cin >> iNam;
    cout << "Nhap diem TOAN cua thi sinh: ";
    cin >> fToan;
    cout << "Nhap diem VAN cua thi sinh: ";
    cin >> fVan;
    cout << "Nhap diem ANH cua thi sinh: ";
    cin >> fAnh;
    cin.ignore(1);
}

void ThiSinh::Xuat()
{
    cout << MSSV << '\t' << Ten << "\t" << chuanHoaNgayThangNam(iNgay, iThang, iNam);
    cout << '\t' << fixed << setprecision(2) << fToan << '\t' << fixed << setprecision(2) << fVan << '\t' << fixed << setprecision(2) << fAnh;
    cout << '\t' << fixed << setprecision(2) << Tong() << endl;
}

float ThiSinh::Tong()
{
    float DTB = fToan + fVan + fAnh;
    return DTB;
}