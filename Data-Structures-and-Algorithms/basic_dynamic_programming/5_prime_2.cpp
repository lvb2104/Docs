#include <bits/stdc++.h>
#pragma GCC optimize("03,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2")
using namespace std;
using ll = long long;
#define mod 1000000007
#define endl '\n'
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int F[1000005];
int a[1000005];

void init()
{
    for (int i = 0; i <= 1000000; i++) a[i] = 1;
    a[0] = a[1] = 0;
    for (int i = 2; i <= sqrt(1000000); i++)
    {
        if (a[i])
        {
            for (int j = i * i; j <= 1000000; j += i)
            {
                a[j] = 0;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    for (int i = 2; i <= 1000000; i++)
    {
        F[i] = F[i - 1] + a[i];
    }
    int t; cin >> t;
    while(t--)
    {
        int x, y; cin >> x >> y;
        cout << F[y] - F[x - 1] << endl;
    }
    return 0;
}