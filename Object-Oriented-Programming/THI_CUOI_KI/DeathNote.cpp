#include "People.h"
#include "DoanhNhan.h"
#include "ChinhTriGia.h"
#include "TuNhan.h"
#include "DeathNote.h"

int DeathNote::getGioiHan()
{
    return this->gioiHan;
}

void DeathNote::setGioiHan(int gioiHan)
{
    this->gioiHan = gioiHan;
}

int DeathNote::getSoLuongNhap()
{
    return this->soLuongNhap;
}

void DeathNote::setSoLuongNhap(int soLuongNhap)
{
    this->soLuongNhap = soLuongNhap;
}

void DeathNote::nhap()
{
    int n, m;
    cin >> n >> m;
    this->setSoLuongNhap(n);
    this->setGioiHan(m);
    for (int i = 0; i < n; i++)
    {
        People *p;
        int type;
        cin >> type;
        string ten, sdt;
        int tuoi;
        cin >> ten;
        cin >> tuoi;
        cin >> sdt;
        
        if (type == 1)
        {
            string chucVu;
            cin >> chucVu;
            p = new ChinhTriGia(1, ten, tuoi, sdt, chucVu);
        }
        else if (type == 2)
        {
            float taiSan;
            cin >> taiSan;
            p = new DoanhNhan(2, ten, tuoi, sdt, taiSan);
        }
        else if (type == 3)
        {
            string toiPham;
            cin >> toiPham;
            int soNamTu;
            cin >> soNamTu;
            p = new TuNhan(3, ten, tuoi, sdt, toiPham, soNamTu);
        }
        
        this->listPeople.push_back(p);
    }
    // #include <iostream>

    
}

void DeathNote::xuata()
{

    for (int i = 0; i < listPeople.size(); i++)
    {
        cout << listPeople[i]->getType() << ' ' << listPeople[i]->getTen() << " " << listPeople[i]->getTuoi() << " " << listPeople[i]->getSdt() << ' ';
        if (listPeople[i]->getType() == 1)
        {
            cout << listPeople[i]->getChucVu();
        }
        else if (listPeople[i]->getType() == 2)
        {
            cout << listPeople[i]->getTaiSan();
        }
        else if (listPeople[i]->getType() == 3)
        {
            cout << listPeople[i]->getPhamToi() << ' ' << listPeople[i]->getNamTu();
        }
        cout << endl;
    }
}

void DeathNote::xuLy()
{
    for (int i = 1; i < listPeople.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (this->listPeople[j]->getTen() == this->listPeople[i]->getTen())
            {
                this->listPeople.erase(this->listPeople.begin() + i);
                i--;
            }
        }
    }
    while(this->listPeople.size() > this->getGioiHan())
    {
        this->listPeople.erase(this->listPeople.begin());
    }
}

void DeathNote::xuatb()
{
    People *temp1; string tam1 = "";
    float tam2 = 0; string temp2 = "";
    int tam3 = 0; string temp3 = "";
    for (int i = 0; i < listPeople.size(); i++)
    {
        if (listPeople[i]->getType() == 1)
        {
            if (listPeople[i]->getChucVu().size() > tam1.size())
            {
                temp1 = listPeople[i];
                tam1 = listPeople[i]->getChucVu();
            }
        }
        else if (listPeople[i]->getType() == 2)
        {
            tam2 += listPeople[i]->getTaiSan();
            if (listPeople[i]->getCachChet() == "nang")
            {
                temp2 = listPeople[i]->getCachChet();
            }
            else if (listPeople[i]->getCachChet() == "binh thuong" && temp2 != "nang")
            {
                temp2 = listPeople[i]->getCachChet();
            }
            else if (listPeople[i]->getCachChet() == "nhe" && temp2 != "nang" && temp2 != "binh thuong")
            {
                temp2 = listPeople[i]->getCachChet();
            }
        }
        else if (listPeople[i]->getType() == 3)
        {
            tam3 += listPeople[i]->getNamTu();
            if (listPeople[i]->getNamTu() > tam3)
            {
                tam3 = listPeople[i]->getNamTu();
            }
            if (listPeople[i]->getCachChet() == "nang")
            {
                temp3 = listPeople[i]->getCachChet();
            }
            else if (listPeople[i]->getCachChet() == "binh thuong" && temp3 != "nang")
            {
                temp3 = listPeople[i]->getCachChet();
            }
            else if (listPeople[i]->getCachChet() == "nhe" && temp3 != "nang" && temp3 != "binh thuong")
            {
                temp3 = listPeople[i]->getCachChet();
            }
        }
    }
    if (temp1 != NULL)
    {
        cout << temp1->getTen() << ", Chuc vu: " << temp1->getChucVu() << endl;
    }
    if (tam2 != 0)
    {
        cout << "Doanh nhan: " << tam2 << " ty dong, Cach thuc chet: " << temp2 << endl;
    }
    if (tam3 != 0)
    {
        cout << "Tu nhan: " << tam3 << ", Cach thuc chet: " << temp3 << endl;
    }
}

void DeathNote::xuatc()
{
    if (listPeople.size() == 0)
    cout << "DeathNote trong";
}

