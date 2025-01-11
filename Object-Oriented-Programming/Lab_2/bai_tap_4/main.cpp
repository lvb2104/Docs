#include "ThiSinh.h"

int main()
{
    int n;
    cout << "Nhap vao so Thi Sinh: ";
    cin >> n;
    cin.ignore(1);
    ThiSinh *a = new ThiSinh[n];
    for (int i = 0; i < n; i++)
    {
        cout << "--------------------------------" << endl;
        cout << "Nhap thong tin cua thi sinh thu " << i + 1 << ": " << endl;
        a[i].Nhap();
    }
    cout << endl;

    ThiSinh thuKhoa;
    int count = 0;
    cout << "Cac thi sinh co tong diem lon hon 15 diem: " << endl;
    cout << "STT\tMSSV\t\tTEN\t\tNgay/Thang/Nam\tTOAN\tVAN\tANH\tDTB\n";
    for (int i = 0; i < n; i++)
    {
        if (thuKhoa.Tong() < a[i].Tong())
        {
            thuKhoa = a[i];
        }
        if (a[i].Tong() > 15)
        {
            cout << ++count << "\t";
            a[i].Xuat();
        }
    }
    cout << endl;

    cout << "Thi sinh co tong diem cao nhat: " << endl;
    cout << "MSSV\t\tTEN\t\tNgay/Thang/Nam\tTOAN\tVAN\tANH\tDTB\n";
    thuKhoa.Xuat();
    delete[] a;
    return 0;
}