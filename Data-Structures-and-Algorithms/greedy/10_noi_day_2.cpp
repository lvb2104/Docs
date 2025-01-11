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
    priority_queue<ll> q;
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll x; cin >> x;
        q.push(x);
    }
    ll sum = 0;
    while(q.size() > 1)
    {
        ll x, y;
        x = q.top(); q.pop();
        y = q.top(); q.pop();
        sum += (x + y) % mod;
        sum %= mod;
        q.push((x + y) % mod);
    }
    cout << sum;
    return 0;
}