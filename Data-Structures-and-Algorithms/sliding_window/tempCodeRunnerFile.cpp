#include <bits/stdc++.h>
using namespace std;

using ll = long long;



int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s; cin >> s;
    int a[257] = {0};
    for (char x : s) a[x]++;
    int count = 0;
    for (int x : a) if (x) count++;
    set<char> se;
    int l = 0;
    int ans = INT_MAX;
    for (int r = 0; r < s.size(); r++){
        se.insert(s[r]);
        while(se.size() == count){
            ans = min(ans, r - l + 1);
            se.erase(s[l]);
            l++;
        }
    }
    cout << ans;
    return 0;
}