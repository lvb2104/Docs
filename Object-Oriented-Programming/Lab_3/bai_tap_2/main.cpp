#include "SoPhuclab3.h"
#include <iostream>
using namespace std;

int main()
{
    SoPhuc c1, c2, result;
    cout << "Nhap vao so phuc dau tien: ";
    cin >> c1;
    cout << "Nhap vao so phuc thu hai: ";
    cin >> c2;

    cout << "----------------------------------" << endl;

    result = c1 + c2;
    cout << "Tong cua hai so phuc: " << result << endl;

    result = c1 - c2;
    cout << "Hieu cua hai so phuc: " << result << endl;

    result = c1 * c2;
    cout << "Thuong cua hai so phuc: " << result << endl;

    result = c1 / c2;
    cout << "Tich cua hai so phuc: " << result << endl;

    if (c1 == c2)
        cout << "Hai so phuc " << c1 << " va " << c2 << " bang nhau!" << endl;
    else if (c1 != c2)
        cout << "Hai so phuc " << c1 << " va " << c2 << " khong bang nhau!" << endl
             << endl;
    return 0;
}
