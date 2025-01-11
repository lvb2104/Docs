#include "KhachSan.h"

int main()
{
     Deluxe Deluxe_a, Deluxe_b;
     Premium Premium_c, Premium_d;
     Business Business_e;

     cout << "Phong Deluxe a:" << '\n'
          << "*===================*" << '\n';
     Deluxe_a.Nhap();
     cout << "Doanh thu cua phong la: " << fixed << setprecision(0) << doanhthu(Deluxe_a) << " VND";
     cout << '\n'
          << "*===================*" << '\n'
          << '\n';

     cout << "Phong Deluxe b:" << '\n'
          << "*===================*" << '\n';
     Deluxe_b.Nhap();
     cout << "Doanh thu cua phong la: " << fixed << setprecision(0) << doanhthu(Deluxe_b) << " VND";
     cout << '\n'
          << "*===================*" << '\n'
          << '\n';

     cout << "Phong Premium c:" << '\n'
          << "*===================*" << '\n';
     Premium_c.Nhap();
     cout << "Doanh thu cua phong la: " << fixed << setprecision(0) << doanhthu(Premium_c) << " VND";
     cout << '\n'
          << "*===================*" << '\n'
          << '\n';

     cout << "Phong Premium d:" << '\n'
          << "*===================*" << '\n';
     Premium_d.Nhap();
     cout << "Doanh thu cua phong la: " << fixed << setprecision(0) << doanhthu(Premium_d) << " VND";
     cout << '\n'
          << "*===================*" << '\n'
          << '\n';

     cout << "Phong Business e:" << '\n'
          << "*===================*" << '\n';
     Business_e.Nhap();
     cout << "Doanh thu cua phong la: " << fixed << setprecision(0) << doanhthu(Business_e) << " VND";
     cout << '\n'
          << "*===================*" << '\n'
          << '\n';

     double total_revenue_Deluxe = doanhthu(Deluxe_a) + doanhthu(Deluxe_b);
     double total_revenue_Premium = doanhthu(Premium_c) + doanhthu(Premium_d);
     double total_revenue_Business = doanhthu(Business_e);

     string most_revenue_room_type;
     double max_revenue = max({total_revenue_Deluxe, total_revenue_Premium, total_revenue_Business});

     if (max_revenue == total_revenue_Deluxe)
     {
          most_revenue_room_type = "Deluxe";
     }
     else if (max_revenue == total_revenue_Premium)
     {
          most_revenue_room_type = "Premium";
     }
     else
     {
          most_revenue_room_type = "Business";
     }

     cout << "Doanh thu cua loai phong " << most_revenue_room_type << " la nhieu nhat!" << '\n';
     return 0;
}