#include "NgayThangNam.h"

NgayThangNam::NgayThangNam()
{
}

NgayThangNam::NgayThangNam(int Nam, int Thang, int Ngay = 1)
{
    iNam = Nam;
    iThang = Thang;
    iNgay = Ngay;
}

void NgayThangNam::setNgay(int Ngay)
{
    iNgay = Ngay;
}

void NgayThangNam::setThang(int Thang)
{
    iThang = Thang;
}

void NgayThangNam::setNam(int Nam)
{
    iNam = Nam;
}

// int NgayThangNam::getNgay()
// {
//     return iNgay;
// }

// int NgayThangNam::getThang()
// {
//     return iThang;
// }

// int NgayThangNam::getNam()
// {
//     return iNam;
// }

int NgayThangNam::getMaxThang(int Nam, int Thang)
{
    int maxNgay;
    switch (Thang)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        maxNgay = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        maxNgay = 30;
        break;
    case 2:
        if (Nam % 400 == 0 || (Nam % 4 == 0 && Nam % 100 != 0))
            maxNgay = 29;
        else
        {
            maxNgay = 28;
        }
        break;
    default:
        break;
    }
    return maxNgay;
}

void NgayThangNam::ChuanHoa()
{
    int Ngay = iNgay, Thang = iThang, Nam = iNam;

    // Chuyển ngày, tháng, năm âm thành dương
    while (Ngay <= 0 || Thang <= 0 || Nam <= 0)
    {
        if (Ngay <= 0)
        {
            if (Thang == 1)
            {
                --Nam;
                Thang = 12;
            }
            else
            {
                --Thang;
            }
            Ngay += getMaxThang(Nam, Thang);
        }
        if (Thang <= 0)
        {
            --Nam;
            Thang += 12;
        }
        if (Nam <= 0)
        {
            Nam++;
        }
    }

    // Chuyển ngày, tháng vượt quá giới hạn thành ngày hợp lệ
    while (Ngay > getMaxThang(Nam, Thang))
    {
        Ngay -= getMaxThang(Nam, Thang);
        if (++Thang > 12)
        {
            Thang = 1;
            ++Nam;
        }
    }

    // Chuyển tháng vượt quá 12 thành tháng hợp lệ
    while (Thang > 12)
    {
        Thang -= 12;
        ++Nam;
    }

    setNgay(Ngay);
    setThang(Thang);
    setNam(Nam);
}

void NgayThangNam::TinhNgay()
{
    int tongNgay = 0;
    for (int i = 1; i < iThang; i++)
    {
        tongNgay += getMaxThang(iNam, i);
    }
    tongNgay += iNgay;
    std::cout << "Ngay thu " << tongNgay << " trong nam" << std::endl;
}

NgayThangNam NgayThangNam::operator+(int Ngay)
{
    NgayThangNam *result = new NgayThangNam(iNam, iThang, iNgay + Ngay);
    result->ChuanHoa();
    return *result;
}

NgayThangNam NgayThangNam::operator-(int Ngay)
{
    NgayThangNam *result = new NgayThangNam(iNam, iThang, iNgay - Ngay);
    result->ChuanHoa();
    return *result;
}

NgayThangNam NgayThangNam::operator-(NgayThangNam NgayThangNam2)
{
    NgayThangNam *result;
    result = new NgayThangNam(iNam - NgayThangNam2.iNam, iThang - NgayThangNam2.iThang, iNgay - NgayThangNam2.iNgay);
    result->ChuanHoa();
    return *result;
}

NgayThangNam NgayThangNam::operator++()
{
    NgayThangNam *result = new NgayThangNam(iNam, iThang, iNgay + 1);
    result->ChuanHoa();
    return *result;
}

NgayThangNam NgayThangNam::operator--()
{
    NgayThangNam *result = new NgayThangNam(iNam, iThang, iNgay - 1);
    result->ChuanHoa();
    return *result;
}

bool NgayThangNam::operator==(NgayThangNam NgayThangNam2)
{
    return iNam == NgayThangNam2.iNam && iThang == NgayThangNam2.iThang && iNgay == NgayThangNam2.iNgay;
}

bool NgayThangNam::operator!=(NgayThangNam NgayThangNam2)
{
    return iNam != NgayThangNam2.iNam || iThang != NgayThangNam2.iThang || iNgay != NgayThangNam2.iNgay;
}

bool NgayThangNam::operator>=(NgayThangNam NgayThangNam2)
{
    if (iNam > NgayThangNam2.iNam)
        return true;
    if (iNam == NgayThangNam2.iNam && iThang > NgayThangNam2.iThang)
        return true;
    if (iNam == NgayThangNam2.iNam && iThang == NgayThangNam2.iThang && iNgay >= NgayThangNam2.iNgay)
        return true;
    return false;
}

bool NgayThangNam::operator<=(NgayThangNam NgayThangNam2)
{
    if (iNam < NgayThangNam2.iNam)
        return true;
    if (iNam == NgayThangNam2.iNam && iThang < NgayThangNam2.iThang)
        return true;
    if (iNam == NgayThangNam2.iNam && iThang == NgayThangNam2.iThang && iNgay <= NgayThangNam2.iNgay)
        return true;
    return false;
}

bool NgayThangNam::operator>(NgayThangNam NgayThangNam2)
{
    if (iNam > NgayThangNam2.iNam)
        return true;
    if (iNam == NgayThangNam2.iNam && iThang > NgayThangNam2.iThang)
        return true;
    if (iNam == NgayThangNam2.iNam && iThang == NgayThangNam2.iThang && iNgay > NgayThangNam2.iNgay)
        return true;
    return false;
}

bool NgayThangNam::operator<(NgayThangNam NgayThangNam2)
{
    if (iNam < NgayThangNam2.iNam)
        return true;
    if (iNam == NgayThangNam2.iNam && iThang < NgayThangNam2.iThang)
        return true;
    if (iNam == NgayThangNam2.iNam && iThang == NgayThangNam2.iThang && iNgay < NgayThangNam2.iNgay)
        return true;
    return false;
}

std::istream &operator>>(std::istream &in, NgayThangNam &ntn)
{
    std::cout << "Nhap ngay: ";
    in >> ntn.iNgay;
    std::cout << "Nhap thang: ";
    in >> ntn.iThang;
    std::cout << "Nhap nam: ";
    in >> ntn.iNam;
    return in;
}

std::ostream &operator<<(std::ostream &out, NgayThangNam ntn)
{
    out << ntn.iNgay << '/' << ntn.iThang << '/' << ntn.iNam;
    return out;
}
