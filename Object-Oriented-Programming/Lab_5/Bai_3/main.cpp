#include "Ve.h"
#include "VeTungPhan.h"
#include "VeChonGoi.h"
#define endl "\n"

int main()
{
    // std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    // Nhap du lieu
    int n; 
    cout << "Nhap so luong ve: ";
    cin >> n;
    Ve *ve[n]; // khong duoc tao truc tiep object abstract class
    for (int i = 0; i < n; i++)
    {
        string mv, ht;
        int ns, sltcdtg;
        cout << "Nhap ma ve: ";
        cin >> mv;
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, ht);
        cout << "Nhap nam sinh: ";
        cin >> ns;
        cout << "Nhap so luong tro choi da tham gia: ";
        cin >> sltcdtg;
        if (mv[0] == 'T')
        {
            ve[i] = new VeTungPhan(mv, ht, ns, sltcdtg);
        }
        else
        {
            ve[i] = new VeChonGoi(mv, ht, ns, sltcdtg);
        }
        cout << "--------------------------------\n";
    }

    // Tinh tong so tien thu duoc
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += ve[i]->getGiaVe() + ve[i]->getSoLuongTroChoiDaThamGia() * ve[i]->getChiPhiTroChoi();
    }
    cout << "Tong so tien thu duoc: " << sum << "\n";

    // Tinh so ve tung phan
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (ve[i]->getMaVe()[0] == 'T')
        {
            count++;
        }
    }
    cout << "So ve tung phan: " << count << "\n";
    return 0;
}