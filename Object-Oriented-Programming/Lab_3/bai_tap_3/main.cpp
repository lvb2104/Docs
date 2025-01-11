#include "bai3.h"

int main()
{

    thoigian temp1(21, 25, 32);
    cout << temp1;
    cout << "Giay thu " << temp1.TinhGiay() << " trong ngay!\n";
    int giay;
    cout << "Nhap giay moi:";
    cin >> giay;
    temp1.Tinhlaigio(giay);

    cout << "Nhap giay muon cong :";
    cin >> giay;
    printf("Sau khi cong them %d giay:", giay);
    temp1 = temp1 + giay;
    temp1.xuat();

    cout << "Nhap giay muon tru :";
    cin >> giay;
    printf("Sau khi tru di %d giay:", giay);
    temp1 = temp1 - giay;
    temp1.xuat();

    cout << "Sau khi them 1 giay:";
    ++temp1;
    temp1.xuat();

    cout << "Sau khi tru 1 giay:";
    --temp1;
    temp1.xuat();

    // Thao tac 2 thoi gian
    cout << "*-------------------------------------------------------------*";
    cout << "\n*Thao tac 2 thoi gian\n";
    thoigian temp2(0, 0, 0), temp3(0, 0, 0);
    thoigian result;
    cout << "Nhap thoi gian thu 1:";
    cin >> temp2;
    cout << temp2;
    cout << "Nhap thoi gian thu 2:";
    cin >> temp3;
    cout << temp3;
    cout << "Thoi gian sau khi cong:";
    result = temp2 + temp3;
    result.xuat();
    cout << "Thoi gian sau khi tru:";
    result = temp2 - temp3;
    result.xuat();
    system("pause");

    // So sanh
    cout << "*-------------------------------------------------------------*";
    cout << "\n*So sanh thoi gian\n";
    cout << "Nhap thoi gian thu 1:";
    cin >> temp2;
    cout << temp2;
    cout << "Nhap thoi gian thu 2:";
    cin >> temp3;
    cout << temp3;
    if (temp2 == temp3)
        cout << "Thoi gian bang nhau.\n";
    if (temp2 != temp3)
        cout << "Thoi gian khac nhau.\n";
    if (temp2 > temp3)
        cout << "Thoi gian thu nhat lon hon Thoi gian thu hai.\n";
    if (temp2 < temp3)
        cout << "Thoi gian thu nhat be hon Thoi gian thu 2.\n";

    return 0;
}
