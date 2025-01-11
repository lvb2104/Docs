#include "bai3.h"
#define giay_motngay 86400

void thoigian::xuat()
{
    cout << Gio << "h:" << Phut << "p:" << Giay << "s\n";
}

thoigian::thoigian(int gio, int phut, int giay)
{
    Gio = gio;
    Phut = phut;
    Giay = giay;
}
int thoigian::TinhGiay()
{ // giay thu may trong ngay
    ll result = Gio * 3600 + Phut * 60 + Giay;
    return result;
}
void thoigian::Tinhlaigio(int giay)
{
    int temp = Giay;
    Giay = giay;
    if (temp == Giay)
        ;
    else
    {
        if (Giay >= 60)
        {
            Phut += Giay / 60;
            Giay %= 60;
            Gio += Phut / 60;
            Phut %= 60;
            if (Gio >= 24)
            {
                int heso = Gio / 24;
                Gio -= heso * 24;
            }
        }
    }
    xuat();
}

thoigian thoigian::operator+(int giay)
{
    thoigian temp;
    temp.Giay = Giay + giay;
    temp.Gio = Gio;
    temp.Phut = Phut;
    if (temp.Giay >= 60)
    {
        temp.Phut += temp.Giay / 60;
        temp.Giay %= 60;
        temp.Gio += temp.Phut / 60;
        temp.Phut %= 60;
        if (temp.Gio >= 24)
        {
            int heso = temp.Gio / 24;
            temp.Gio -= heso * 24;
        }
    }
    return temp;
}
thoigian thoigian::operator-(int giay)
{
    thoigian temp;
    temp.Gio = Gio;
    temp.Phut = Phut;
    if (Giay - giay >= 0)
        temp.Giay = Giay - giay;
    else
    {
        ll result = Gio * 3600 + Phut * 60 + Giay - giay;
        if (result < 0)
        {
            result += giay_motngay;
            temp.Giay = result;
        }
        temp.Phut = temp.Giay / 60;
        temp.Giay %= 60;
        temp.Gio = temp.Phut / 60;
        temp.Phut %= 60;
    }
    return temp;
}
thoigian thoigian::operator+(thoigian a)
{
    thoigian sum;

    ll result = (Gio + a.Gio) * 3600 + (Phut + a.Phut) * 60 + (Giay + a.Giay);
    sum.Phut = result / 60;
    sum.Giay = result % 60;
    sum.Gio = sum.Phut / 60;
    sum.Phut %= 60;
    if (sum.Gio >= 24)
    {
        int heso = sum.Gio / 24;
        sum.Gio -= heso * 24;
    }
    return sum;
}
thoigian thoigian::operator-(thoigian a)
{
    thoigian res;

    ll result = (Gio - a.Gio) * 3600 + (Phut - a.Phut) * 60 + (Giay - a.Giay);
    if (result < 0)
    {
        result += giay_motngay;
        res.Giay = result;
    }

    res.Phut = result / 60;
    res.Giay = result % 60;
    res.Gio = res.Phut / 60;
    res.Phut %= 60;
    return res;
}
void thoigian::operator++()
{

    if (Giay == 59)
    {
        if (Phut == 59)
        {
            if (Gio == 23)
            {
                Gio = 0;
                Phut = 0;
                Giay = 0;
            }
            else
            {
                Gio++;
                Phut = 0;
                Giay = 0;
            }
        }
        else
        {
            Phut++;
            Giay = 0;
        }
    }
    else
        Giay++;
}

void thoigian::operator--()
{
    if (Giay == 0)
    {
        if (Phut == 0)
        {
            if (Gio == 0)
            {
                Gio = 23;
                Phut = 59;
                Giay = 59;
            }
            else
            {
                Gio--;
                Phut = 59;
                Giay = 59;
            }
        }
        else
        {
            Phut--;
            Giay = 59;
        }
    }
    else
        Giay--;
}

bool thoigian::operator==(thoigian a)
{
    if (Gio == a.Gio && Phut == a.Phut && Giay == a.Giay)
        return true;
    return false;
}

bool thoigian::operator!=(thoigian a)
{
    if (Gio == a.Gio && Phut == a.Phut && Giay == a.Giay)
        return false;
    return true;
}

bool thoigian::operator>=(thoigian a)
{
    if (TinhGiay() >= a.TinhGiay())
        return true;
    return false;
}

bool thoigian::operator<=(thoigian a)
{
    if (TinhGiay() <= a.TinhGiay())
        return true;
    return false;
}

bool thoigian::operator>(thoigian a)
{
    if (TinhGiay() > a.TinhGiay())
        return true;
    return false;
}

bool thoigian::operator<(thoigian a)
{
    if (TinhGiay() < a.TinhGiay())
        return true;
    return false;
}

istream &operator>>(istream &in, thoigian &a)
{
    in >> a.Gio >> a.Phut >> a.Giay;
    return in;
}

ostream &operator<<(ostream &out, thoigian a)
{
    out << "Time:" << a.Gio << "h:" << a.Phut << "p:" << a.Giay << "s\n";
    return out;
}
