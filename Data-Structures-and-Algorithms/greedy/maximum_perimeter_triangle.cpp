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



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;
    sort(a, a + n, greater<int>());
    for (int i = 0; i < n - 2; i++)
    {
        int l = i + 1, r = l + 1;
        for ( ; l < n - 1; l++)
        {
            for ( ; r < n; r++)
            {
                if (a[l] + a[r] > a[i])
                {
                    cout << a[r] << ' ' << a[l] << ' ' << a[i];
                    return 0;
                }
            }
        }
    }
    cout << -1;
    return 0;
}