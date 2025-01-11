#include <bits/stdc++.h>
// #pragma GCC optimize("03,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2")
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
    int t; cin >> t;
    vector<int> v;
    while(t--)
    {
        string s; cin >> s;
        if (s == "show")
        {
            if (v.empty())
            {
                cout << "EMPTY" << endl;
            }
            else 
            {
                for (int x : v)
                {
                    cout << x << ' ';
                }
                cout << endl;
            }
        }
        else if (s == "push")
        {
            int temp;
            cin >> temp;
            v.push_back(temp);
        }
        else if (s == "pop")
        {
            if (!v.empty())
            {
                v.pop_back();
            }
        }
    }
    return 0;
}