#include "NgayThangNam.h"

int main()
{
    NgayThangNam *ntn = new NgayThangNam;
    std::cout << "Nhap Ngay Thang Nam thu 1: " << std::endl;
    std::cin >> *ntn;
    NgayThangNam *ntn2 = new NgayThangNam;
    std::cout << "Nhap Ngay Thang Nam thu 2: " << std::endl;
    std::cin >> *ntn2;
    std::cout << "Ngay thang nam thu 1: " << *ntn << std::endl;
    std::cout << "Ngay thang nam thu 2: " << *ntn2 << std::endl;
    std::cout << "Ngay thang nam thu 1 - Ngay thang nam thu 2: " << *ntn - *ntn2 << std::endl;
    ntn->TinhNgay();
    int NgayCong;
    std::cout << "Cong them luong ngay la: ";
    std::cin >> NgayCong;
    std::cout << "Cong 2 ngay thang nam: " << *ntn + NgayCong << std::endl;
    int NgayTru;
    std::cout << "Tru di luong ngay la: ";
    std::cin >> NgayTru;
    std::cout << "Tru 2 ngay thang nam: " << *ntn - NgayTru << std::endl;
    std::cout << "Cong ngay thang nam them 1 ngay la: " << ++(*ntn) << std::endl;
    std::cout << "Tru ngay thang nam di 1 ngay la: " << --(*ntn) << std::endl;
    std::cout << "So sanh 2 ngay thang nam: " << std::endl;
    if (*ntn == *ntn2)
    {
        std::cout << "2 ngay thang nam bang nhau" << std::endl;
    }
    if (*ntn != *ntn2)
    {
        std::cout << "2 ngay thang nam khac nhau" << std::endl;
    }
    if (*ntn >= *ntn2)
    {
        std::cout << "Ngay thang nam 1 lon hon hoac bang ngay thang nam 2" << std::endl;
    }
    if (*ntn <= *ntn2)
    {
        std::cout << "Ngay thang nam 1 nho hon hoac bang ngay thang nam 2" << std::endl;
    }
    if (*ntn > *ntn2)
    {
        std::cout << "Ngay thang nam 1 lon hon ngay thang nam 2" << std::endl;
    }
    if (*ntn < *ntn2)
    {
        std::cout << "Ngay thang nam 1 nho hon ngay thang nam 2" << std::endl;
    }
    return 0;
}