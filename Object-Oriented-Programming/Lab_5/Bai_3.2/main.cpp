#include "ConVat.h"
#include "Muoi.h"
#include "Ech.h"
#include "Buom.h"

int main()
{
    cout << "Nhap vao so luong con vat: ";
    int n; cin >> n;
    ConVat *cv[n];
    for (int i = 0; i < n; i++)
    {
        string l;
        cout << "Nhap loai con vat: "; cin >> l;
        if (l == "Buom")
        {
            cv[i] = new Buom(l, new int[4]);
            cout << "Nhap vao thoi gian: ";
            for (int j = 0; j < 4; j++)
            {
                cin >> cv[i]->getThoiGian()[j];
            }
        }
        else if (l == "Muoi")
        {
            cv[i] = new Muoi(l, new int[4]);
            cout << "Nhap vao thoi gian: ";
            for (int j = 0; j < 4; j++)
            {
                cin >> cv[i]->getThoiGian()[j];
            }
        }
        else if (l == "Ech")
        {
            cv[i] = new Ech(l, new int[5]);
            cout << "Nhap vao thoi gian: ";
            for (int j = 0; j < 5; j++)
            {
                cin >> cv[i]->getThoiGian()[j];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!cv[i]->tuanTheoQuiLuat())
        {
            cout << "Con vat thu " << i + 1 << " khong tuan theo qui luat\n";
        }
    }
    
    return 0;
}